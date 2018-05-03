//
// Created by guser on 5/3/18.
//

#include "Session.h"
#include "ABState.h"
void Session::setState(State *state) {
    auto old= this->state;
    this->state = state;
    delete old;
}

Session::Session() {
    this->state=new ABState();
}

SessionStatus Session::handleInput(Input input) {

    return state->handleInput(input, *this);
}

Session::~Session() {
    delete this->state;
}




