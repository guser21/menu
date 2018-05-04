//
// Created by guser on 5/3/18.
//

#include "Session.h"
#include "ABState.h"

//State design pattern implemented
//Expected functional changes to menu will be easy to implement
void Session::setState(State *state) {
    auto old = this->state;
    this->state = state;
    delete old;
}

Session::Session() {
    this->state = new ABState();
}

SessionStatus Session::handleInput(Input input) {
    return state->handleInput(input, *this);
}

Session::~Session() {
    delete this->state;
}

std::string Session::view() {
    return state->printView() + "\n\r" + state->currentOption;
}




