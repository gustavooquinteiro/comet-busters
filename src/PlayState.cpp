#include "../include/Game.h"
#include "../include/PlayState.h"
#include "../include/PauseState.h"
#include "../include/InputHandler.h"

const string PlayState::playID = "PLAY";

bool PlayState::onEnter()
{
    cout << "Entering play state" << endl;
    return true;
}

bool PlayState::onExit()
{
    cout << "Exiting play state" << endl;
    return true;
}

void PlayState::render()
{
}

void PlayState::update()
{
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }
    
    for (auto object: gameObjects)
        object->update();
}

string PlayState::getStateID() const{ return this->playID; }


