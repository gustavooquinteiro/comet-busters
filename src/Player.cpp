#include <math.h>
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
        {
            setAngle(true);
            //velocity.setX(moveSpeed);
        }
        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        {
            setAngle(false);
            //velocity.setX(moveSpeed);
        }
        if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
        {
            cout << "posicao x: "  << position.getX() << " y: " << position.getY() << endl;
            setVelocity();
        }
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

void Player::setVelocity()
{
//     int xRotated = acceleration.getX() * cos(angle) + acceleration.getY() * sin(angle); 
//     int yRotated = acceleration.getX() * -sin(angle) + acceleration.getY() * cos(angle); 
//     
//     acceleration.setX(xRotated);
//     acceleration.setY(yRotated);        
//     cout <<" Aceleration: x: " << acceleration.getX()<< " y: " << acceleration.getY() << endl;
    cout << angle << endl;
    acceleration.setX(0);
    acceleration.setY(0);
    switch(myAngle)
    {
        case FIRST_QUADRANT:
            if (angle == 0)
                acceleration.setY(-moveSpeed);
            else if (angle == 90)
                acceleration.setX(moveSpeed);
            else
            {
                acceleration.setY(-moveSpeed);
                acceleration.setX(moveSpeed);
            }
            break;
        case SECOND_QUANDRANT:
            acceleration.setY(moveSpeed);
            if (angle != 180)
                acceleration.setX(moveSpeed);
            break;
        case THIRD_QUADRANT:
            acceleration.setX(-moveSpeed);
            if (angle != 270)
                acceleration.setY(moveSpeed);
            break;
        case FOURTH_QUADRANT:
            acceleration.setX(-moveSpeed);
            acceleration.setY(-moveSpeed);
            break;
    }
    
    velocity += acceleration;
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
