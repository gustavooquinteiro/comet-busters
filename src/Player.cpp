#include "../include/Player.h"
#include "../include/InputHandler.h"

Player::Player(): ShooterObject() {}


void Player::draw()
{
    ShooterObject::draw();
}

void Player::update()
{
    handleInput();
    ShooterObject::update();
    handleAnimation();
}

void Player::clean()
{
    ShooterObject::clean();
}

void Player::handleInput()
{
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
        velocity.setX(2);
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        velocity.setX(-2);
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
        velocity.setY(-2);
}

long int Player::getScore() const{ return this->score; }

void Player::load(unique_ptr<LoaderParams> const &params)
{
    ShooterObject::load(params);
}

void Player::handleAnimation(){}
