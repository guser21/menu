//
// Created by guser on 5/3/18.
//

#ifndef SIK1_ABSTATE_H
#define SIK1_ABSTATE_H


#include "State.h"

class ABState : public State {
public:
    ABState() { menu = {"Opcja A", "Opcja B", "Koniec"}; }

    SessionStatus selectHandler(Session &session) override;
};


#endif //SIK1_ABSTATE_H
