//
// Created by guser on 5/3/18.
//

#ifndef SIK1_STATE_H
#define SIK1_STATE_H


#include <stdexcept>
#include <vector>
#include "Util.h"

class Session;

class State {
protected:
    int cursor = 0;
    std::vector<std::string> menu;
public:
    std::string currentOption;

    virtual inline void up() { cursor = static_cast<int>((cursor + menu.size() - 1) % menu.size()); };

    virtual inline void down() { cursor = static_cast<int>((cursor + 1) % menu.size()); };

    virtual std::string printView() const;

    virtual SessionStatus selectHandler(Session &session)=0;

    virtual SessionStatus handleInput(Input input, Session &session);

};


#endif //SIK1_STATE_H
