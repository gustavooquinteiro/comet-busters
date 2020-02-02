#include "../include/Player.h"
#include "../include/InputHandler.h"
#include "../include/BulletHandler.h"

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
    if (!dead)
    {
        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
            velocity.setX(moveSpeed);
        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
            velocity.setX(-moveSpeed);
        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
            velocity.setY(-moveSpeed);
        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
        {
            if (bulletCounter == bulletFiringSpeed)
            {
                BulletHandler::Instance()->addPlayerBullet(position.getX(), 
                                                           position.getY(), 
                                                           11, 
                                                           11,
                                                           "bullet", 1, 
                                                           Vector2D(10,0));
                bulletCounter = 0;
            }
            else
            {
                bulletCounter = bulletFiringSpeed;
            }
        }
    }
}

long int Player::getScore() const{ return this->score; }

void Player::load(unique_ptr<LoaderParams> const &params)
{
    ShooterObject::load(move(params));
    bulletFiringSpeed = 15;
    moveSpeed = 3;
    bulletCounter = bulletFiringSpeed;
    dyingTime = 100;
}

void Player::handleAnimation(){}
