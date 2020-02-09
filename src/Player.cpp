#include <math.h>
#include "../include/Game.h"
#include "../include/Player.h"
#include "../include/InputHandler.h"
#include "../include/BulletHandler.h"

Player::Player(): ShooterObject() 
{
    angle = 0;
    myAngle = FIRST_QUADRANT;
}


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

void Player::collision()
{
    int lives = Game::Instance()->getPlayerLives();
    Game::Instance()->setPlayerLives(lives - 1);
}

void Player::setAngle(bool direction)
{
    direction? angle += 10: angle -= 10;
    
    angle = (360 + (int) angle % 360) % 360;
    
    if (angle >= 0 && angle <= 90)
    {
        myAngle = FIRST_QUADRANT;
    }
    else if (angle > 90 && angle <= 180)
    {
        myAngle = SECOND_QUANDRANT;
    }
    else if (angle > 180 && angle <= 270)
    {
        myAngle = THIRD_QUADRANT;
    }
    else
    {
        myAngle = FOURTH_QUADRANT;
    }
    
}

void Player::handleInput()
{
    if (!dead)
    {
        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
            setAngle(true);

        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
            setAngle(false);

        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
            setVelocity();

        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
        {
            if (bulletCounter == bulletFiringSpeed)
            {
                BulletHandler::Instance()->addPlayerBullet(position.getX(), 
                                                           position.getY(), 
                                                           11, 
                                                           11,
                                                           "bullet3", 1, 
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

void Player::setVelocity()
{
    velocity.setX(0);
    velocity.setY(0);
    switch(myAngle)
    {
        case FIRST_QUADRANT:
            if (angle == 0)
                velocity.setY(-moveSpeed);
            else if (angle == 90)
                velocity.setX(moveSpeed);
            else
            {
                velocity.setY(-moveSpeed);
                velocity.setX(moveSpeed);
            }
            break;
        case SECOND_QUANDRANT:
            velocity.setY(moveSpeed);
            if (angle != 180)
                velocity.setX(moveSpeed);
            break;
        case THIRD_QUADRANT:
            velocity.setX(-moveSpeed);
            if (angle != 270)
                velocity.setY(moveSpeed);
            break;
        case FOURTH_QUADRANT:
            velocity.setX(-moveSpeed);
            velocity.setY(-moveSpeed);
            break;
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
