//
// Created by guser on 5/3/18.
//

#ifndef SIK1_BSTATE_H
#define SIK1_BSTATE_H


#include "State.h"

class BState : public State {
    SessionStatus handleInput(Input input, Session &session) override;

    SessionStatus selectHandler(Session &session);
};


#endif //SIK1_BSTATE_H
