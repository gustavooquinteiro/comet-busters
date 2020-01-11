#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "GameState.h"

class MenuState: public GameState
{
public:
    void update() override;
    void render() override;
    
    bool onEnter() override;
    bool onExit() override;
    
    string getStateID() const override;
private:
    static const string menuID;
};

#endif
