#include "../include/Game.h"
#include "../include/PlayState.h"
#include "../include/MenuState.h"
#include "../include/GameOverState.h"


const string GameOverState::gameOverID = "GAMEOVER";

void GameOverState::gameOverToMain()
{
    Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::restartPlay()
{
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

bool GameOverState::onEnter()
{
}

bool GameOverState::onExit()
{
}

void GameOverState::render()
{
}

void GameOverState::update()
{
}

string GameOverState::getStateID() const{ return this->gameOverID; }
