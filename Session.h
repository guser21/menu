//
// Created by guser on 5/3/18.
//

#ifndef SIK1_MENU_H
#define SIK1_MENU_H


#include "State.h"


class Session {
public:
    State *state;

    ~Session();

    explicit Session();

    void setState(State *state);

    SessionStatus handleInput(Input input);

    std::string view();
};


#endif //SIK1_MENU_H
