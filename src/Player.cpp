#include "../include/Player.h"
#include "../include/InputHandler.h"

Player::Player(const LoaderParams* params): SDLGameObject(params) {}


void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    acceleration.setX(1);
    
    handleInput();
    
    SDLGameObject::update();    
}

void Player::clean()
{
    SDLGameObject::clean();
}

void Player::handleInput()
{
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
        velocity.setX(2);
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        velocity.setX(-2);
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
        velocity.setX(-2);
}

long int Player::getScore() const{ return this->score; }


GameObject* PlayerCreator::createGameObject() const
{
    return new Player(new LoaderParams(0, 0, 268, 268, "player1"));
}
