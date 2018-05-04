//
// Created by guser on 5/4/18.
//


#include "State.h"

std::string State::printView() const {
    std::string res;
    for (int i = 0; i < menu.size(); ++i) {
        if (i == cursor) {
            res.append("-> " + menu[i] + " \n\r");
        } else {
            res.append(menu[i] + "\n\r");
        }
    }
    return res;
}

SessionStatus State::handleInput(Input input, Session &session) {
    switch (input) {
        case UP:
            up();
            return ALIVE;
        case DOWN:
            down();
            return ALIVE;
        case SELECT:
            return selectHandler(session);
        default:
            throw std::runtime_error("undefined input");
    }

}

