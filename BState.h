//
// Created by guser on 5/3/18.
//

#ifndef SIK1_BSTATE_H
#define SIK1_BSTATE_H


#include "State.h"

class BState : public State {

public:
    BState() { menu = {"Opcja B1", "Opcja B2", "Wstecz"}; }

    SessionStatus selectHandler(Session &session) override;
};


#endif //SIK1_BSTATE_H
