//
// Created by guser on 5/3/18.
//

#ifndef SIK1_STATE_H
#define SIK1_STATE_H


#include "Util.h"

class Session;

class State {
protected:
    int cursor = 0;
public:

    virtual void up() { cursor = ((cursor + 1) % 3); };

    virtual void down() { cursor = ((3 + cursor - 1) % 3); };

    virtual SessionStatus handleInput(Input input, Session &session)= 0;
};


#endif //SIK1_STATE_H
