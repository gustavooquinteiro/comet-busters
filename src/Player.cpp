#include <unistd.h>
#include "../include/Game.h"
#include "../include/Player.h"
#include "../include/InputHandler.h"
#include "../include/BulletHandler.h"
#include "../include/AngleHandler.h"

Player::Player(): ShooterObject() 
{
    angle = 0;
    myAngle = FIRST_QUADRANT;
    bulletFiringSpeed = 10;
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

void Player::respawn()
{
    position.setX(10);
    position.setY(200);
    
    textureId = "player";
    width = 268;
    height = 268;
    currentFrame = 0;
}

void Player::collision()
{
    int lives = Game::Instance()->getPlayerLives();
    Game::Instance()->setPlayerLives(lives - 1);
    if (Game::Instance()->getPlayerLives() != 0)
        respawn();
    else
    {
        dead = true;
        //delete this;
    }
}

void Player::setAngle(bool direction)
{
    direction? angle += 5: angle -= 5;
    
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
    if (angle < 0) 
        angle = 360 + angle;
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
                cout << angle << endl;
                int x = 129;
                int y = 129;
                Vector2D center = position + Vector2D(x, y);
                
                
                int dy = y + calculateYShift(angle);
                int dx = x + calculateXShift(angle);
                
                cout << "dx =" << dx << " e dy ==" << dy << endl;
                Vector2D bulletPosition;
                switch (myAngle)
                {
                case FIRST_QUADRANT:
                    bulletPosition = Vector2D(center.getX(), center.getY() - dy);
                    break;
                case SECOND_QUANDRANT:
                    bulletPosition = Vector2D(center.getX() + dx, center.getY());
                    break;
                case THIRD_QUADRANT:
                    bulletPosition = Vector2D(center.getX(), center.getY());
                    break;
                case FOURTH_QUADRANT:
                    bulletPosition = Vector2D(center.getX() + dx, center.getY() - dy);
                    break;


                
                default:
                    break;
                }
                    
                cout << "(" << bulletPosition.getX()<< "," << bulletPosition.getY()<<")"<<endl;
                Vector2D heading = setBulletHeading(angle);
                BulletHandler::Instance()->addPlayerBullet(bulletPosition.getX(), 
                                                           bulletPosition.getY(),
                                                           33, 
                                                           33,
                                                           "bullet3", 1, 
                                                           heading, this);
                bulletCounter = 0;
            }
            else
            {
                bulletCounter = bulletFiringSpeed;
            }
        }
    }
}

void Player::setPoints(int points)
{
    score += points;
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
