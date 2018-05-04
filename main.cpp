#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <signal.h>
#include "err.h"
#include "Session.h"

#define BUFFER_SIZE   2000
#define QUEUE_LENGTH     5

const char UP_KEY[] = {27, 91, 65};
const char DOWN_KEY[] = {27, 91, 66};
const char ENTER[] = {13};
const char CLEAR[] = {0x1B, 'c', '\0'};
const char LINEMODE[] = "\377\375\042\377\373\001";

int port, msg_sock;


Input mapToInput(char buffer[]) {
    if (strncmp(UP_KEY, buffer, 3) == 0) {
        return UP;
    }
    if (strncmp(DOWN_KEY, buffer, 3) == 0) {
        return DOWN;
    }
    if (strncmp(ENTER, buffer, 1) == 0) {
        return SELECT;
    }
    return ERROR;
}


int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_address_len;

    char buffer[BUFFER_SIZE];
    ssize_t len, snd_len;
    if (argc < 2) syserr("Please provide the port number");

    port = atoi(argv[1]);
    sock = socket(PF_INET, SOCK_STREAM, 0); // creating IPv4 TCP socket
    if (sock < 0) syserr("socket");

    server_address.sin_family = AF_INET; // IPv4
    server_address.sin_addr.s_addr = htonl(INADDR_ANY); // listening on all interfaces
    server_address.sin_port = htons(port); // listening on port PORT_NUM

    // bind the socket to a concrete address
    if (bind(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
        syserr("bind");

    // switch to listening (passive open)
    if (listen(sock, QUEUE_LENGTH) < 0) syserr("listen");

    printf("accepting client connections on port %hu\n", ntohs(server_address.sin_port));


    for (;;) {
        client_address_len = sizeof(client_address);
        // get client connection from the socket
        msg_sock = accept(sock, (struct sockaddr *) &client_address, &client_address_len);

        if (msg_sock < 0) syserr("accept");
        //setting into line mode
        if (write(msg_sock, LINEMODE, 7) != 7) syserr("telnet not configured");

        Session session;
        SessionStatus sessionStatus = ALIVE;
        do {

            memset(buffer, 0, sizeof(buffer));
            if (write(msg_sock, CLEAR, 3) != 3) syserr("cleaning telnet screen");

            auto screenUpdate = session.view();

            if (write(msg_sock, screenUpdate.c_str(), screenUpdate.length()) != screenUpdate.length()) {
                syserr("writing to client socket");
            }

            len = read(msg_sock, buffer, sizeof(buffer));

            if (len < 0) {
                syserr("reading from client socket");
            } else {

                auto input = mapToInput(buffer);
                if (input == ERROR) continue;

                sessionStatus = session.handleInput(input);
            }
        } while (len > 0 && sessionStatus == ALIVE);

        if (close(msg_sock) < 0) syserr("close");
    }
    return 0;
}
