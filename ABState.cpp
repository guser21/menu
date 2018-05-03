//
// Created by guser on 5/3/18.
//

#include <stdio.h>
#include <stdexcept>
#include "ABState.h"
#include "BState.h"
#include "Session.h"
//TODO options should be objects

SessionStatus ABState::handleInput(Input  input, Session& session) {
    switch(input){
        case UP:
            up();
            return ALIVE;
        case DOWN:
            down();
            return ALIVE;
        case SELECT:
            return selectHandler(session);
    }
    throw std::logic_error("undefined input");
}

SessionStatus ABState::selectHandler(Session& session){
    switch (cursor){
        case 0:
            printf("%s\n","A");
            return ALIVE;
        case 1:
            session.setState(new BState());
            printf("%s\n","B");
            return ALIVE;
        case 2:
            printf("%s\n","END");
            return DEAD;
        default:
            throw std::range_error("cursor out of bounds");
    }


}
