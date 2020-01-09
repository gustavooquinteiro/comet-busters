#ifndef _GAME_STATE_MACHINE_H_
#define _GAME_STATE_MACHINE_H_

#include "GameState.h"
#include <stack>

class GameStateMachine
{
public:
    GameStateMachine();
    void pushState(GameState* state);
    void changeState(GameState* state);
    void popState();
private:
    stack<GameState*> gameStates;
    
};

#endif
