#include "../include/GameStateMachine.h"

GameStateMachine::GameStateMachine(){}

void GameStateMachine::pushState(GameState* state)
{
    gameStates.push(state);
    gameStates.top()->onEnter();
}

void GameStateMachine::popState()
{
    if (!gameStates.empty())
    {
        if (gameStates.top()->onExit())
        {
            gameStates.pop();
        } 
    }
}


void GameStateMachine::changeState(GameState* state)
{
    if (!gameStates.empty())
    {
        if (gameStates.top()->getStateID() == state->getStateID())
            return;
        popState();
    }
    pushState(state);
}

void GameStateMachine::update()
{
    if (!gameStates.empty())
        gameStates.top()->update();
        
}

void GameStateMachine::render()
{
    if (!gameStates.empty())
        gameStates.top()->render();
}



