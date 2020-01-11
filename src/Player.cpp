#include "../include/Player.h"
#include "../include/InputHandler.h"

Player::Player(): SDLGameObject() {}


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

void Player::load(const LoaderParams* params)
{
    SDLGameObject::load(params);
}

