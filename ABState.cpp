//
// Created by guser on 5/3/18.
//

#include <stdexcept>
#include "ABState.h"
#include "BState.h"
#include "Session.h"

SessionStatus ABState::selectHandler(Session &session) {
    switch (cursor) {
        case 0:
            currentOption = "A";
            return ALIVE;
        case 1: {
            auto n_state = new BState();
            session.setState(n_state);
            currentOption = "";
            return ALIVE;
        }
        case 2:
            currentOption = "";
            return DEAD;
        default:
            break;
    }
    throw std::range_error("cursor out of bounds" + cursor);

}
