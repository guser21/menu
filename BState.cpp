//
// Created by guser on 5/3/18.
//

#include <bits/exception.h>
#include <stdexcept>
#include "BState.h"
#include "ABState.h"
#include "Session.h"



SessionStatus BState::selectHandler(Session &session) {
    std::string menu;
    std::string option;
    switch (cursor) {
        case 0:
            currentOption = "B1";
            break;
        case 1:
            currentOption = "B2";
            break;
        case 2: {
            auto n_state = new ABState();
            session.setState(n_state);
            currentOption = "";
            break;
        }
        default:
            throw std::range_error("cursor out of bounds");
    }
    return ALIVE;

}
