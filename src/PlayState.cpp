#include "../include/Game.h"
#include "../include/PlayState.h"
#include "../include/PauseState.h"
#include "../include/InputHandler.h"
#include "../include/GameOverState.h"
#include "../include/TextureManager.h"
#include "../include/BulletHandler.h"
#include "../include/StateParser.h"

const string PlayState::playID = "PLAY";

PlayState* PlayState::instance = 0;

PlayState* PlayState::Instance()
{
    if (instance == 0)
        instance = new PlayState();
    return instance;
}

bool PlayState::onEnter()
{
    Game::Instance()->setPlayerLives(5);
    
    StateParser stateParser;
    stateParser.parseState(configFile, playID, &gameObjects, &textureIDList);
    
    TextureManager::Instance()->load("assets/images/space.jpeg", 
                                     "background", 
                                     Game::Instance()->getRenderer());
    TextureManager::Instance()->load("assets/images/bullet3.png", 
                                     "bullet3", 
                                     Game::Instance()->getRenderer());
    
    cout << "Entering play state" << endl;
    return true;
}

bool PlayState::onExit()
{
    InputHandler::Instance()->reset();
    BulletHandler::Instance()->clearBullets();
    cout << "Exiting play state" << endl;
    return true;
}

void PlayState::render()
{
    for (auto gameObject: gameObjects)
        gameObject->draw();
    
    BulletHandler::Instance()->drawBullets();
}

void PlayState::update()
{
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    
    BulletHandler::Instance()->updateBullets();
    
    if (Game::Instance()->getPlayerLives() == 0)
        Game::Instance()->getStateMachine()->changeState(new GameOverState());
    
    for (auto object: gameObjects)
    {
        if (dynamic_cast<Player*>(object))
        {
            Player* player = dynamic_cast<Player*>(object);
            collisionManager.checkPlayerEnemyCollision(player, gameObjects);
            collisionManager.checkPlayerEnemyBulletCollision(player);
        }
        collisionManager.checkEnemyPlayerBulletCollision(gameObjects);
        object->update();
    }
}

string PlayState::getStateID() const{ return this->playID; }

void PlayState::setObjects(GameObject* object)
{
    gameObjects.push_back(object);
}
