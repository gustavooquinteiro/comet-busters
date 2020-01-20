#include "../include/TextureManager.h"
#include "../include/InputHandler.h"
#include "../include/PauseState.h"
#include "../include/MenuState.h"
#include "../include/Game.h"

const string PauseState::pauseID = "PAUSE";

void PauseState::pauseToMain()
{
    Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::resumePlay()
{
    Game::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
    for (auto object: gameObjects)
        object->update();
}

void PauseState::render()
{
    for (auto object: gameObjects)
        object->draw();
}

bool PauseState::onEnter()
{
    return false;
}

bool PauseState::onExit()
{
    for (auto object: gameObjects)
        object->clean();
    
    gameObjects.clear();
    
    for (auto texture: textureIDList)
        TextureManager::Instance()->clearFromTextureMap(texture);
    
    InputHandler::Instance()->reset();
    return true;
}


string PauseState::getStateID() const{ return this->pauseID; }
