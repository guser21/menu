//
// Created by guser on 5/3/18.
//

#include <stdio.h>
#include <bits/exception.h>
#include <stdexcept>
#include "BState.h"
#include "ABState.h"
#include "Session.h"

SessionStatus BState::handleInput(Input input, Session &session) {
    switch (input) {
        case UP:
            up();
        case DOWN:
            down();
        case SELECT:
            return selectHandler(session);
    }
    return ALIVE;
}

SessionStatus BState::selectHandler(Session &session) {
    switch (cursor) {
        case 0:
            printf("%s\n","B1");
            break;
        case 1:
            printf("%s\n","B2");
            break;
        case 2:
            printf("%s\n","BACK");
            session.setState(new ABState());
            break;
        default:
            throw std::range_error("cursor out of bounds");
    }
    return ALIVE;
}
