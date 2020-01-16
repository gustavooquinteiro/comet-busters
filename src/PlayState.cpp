#include "../include/Game.h"
#include "../include/PlayState.h"
#include "../include/PauseState.h"
#include "../include/InputHandler.h"
#include "../include/GameOverState.h"

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
    
    SDLGameObject* player = dynamic_cast<SDLGameObject*>(gameObjects[0]); 
    for (int i = 1; i <= gameObjects.size(); i++)
    {
        if (checkCollision(player, dynamic_cast<SDLGameObject*>(gameObjects[i])))
            Game::Instance()->getStateMachine()->pushState(new GameOverState());
    }
}

bool PlayState::checkCollision(SDLGameObject* object, SDLGameObject* other)
{
    int leftObject, rightObject, topObject, bottomObject;
    int leftOther, rightOther, topOther, bottomOther;
    
    leftObject = object->getPosition().getX();
    rightObject = object->getPosition().getX() + object->getWidth();
    topObject = object->getPosition().getY();
    bottomObject = object->getPosition().getY() + object->getHeight();
    
    leftOther = other->getPosition().getX();
    rightOther = other->getPosition().getX() + other->getWidth();
    topOther = other->getPosition().getY();
    bottomOther = other->getPosition().getY() + other->getHeight();
    
    if (bottomObject <= topOther) return false;
    if (topObject >= bottomOther) return false;
    if (rightObject <= leftOther) return false;
    if (leftObject >= rightOther) return false;
    
    return true;
}

string PlayState::getStateID() const{ return this->playID; }


