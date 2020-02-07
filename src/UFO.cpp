#include "../include/UFO.h"
#include "../include/Game.h"
#include "../include/BulletHandler.h"

UFO::UFO(): Enemy()
{
    health = 1;
    moveSpeed = rand() % 4 + 1;
}

void UFO::update()
{
    if (!isDead())
    {
        static int xShift, yShift;
        xShift = yShift = moveSpeed;
        
        if (position.getX() >= Game::Instance()->getGameWidth() &&
            position.getY() >= Game::Instance()->getGameHeight())
        {
           xShift = -xShift | 1;
           yShift = -yShift | 1;
        }
        else if (position.getX() >= Game::Instance()->getGameWidth())
        {
            xShift = -xShift | 2;
        }
        else if (position.getY() >= Game::Instance()->getGameHeight())
        {
            yShift = -yShift | 2;
        }
    
        velocity.setX(xShift);
        velocity.setY(yShift);
        shoot();
    } 
    else
    {
        velocity.setX(0);
        velocity.setY(0);
        // TODO: Dying animation
    }
    ShooterObject::update();
}

void UFO::shoot()
{
    int x = rand() % 7 - 3;
    int y = rand() % 7 - 3;
    Vector2D heading = Vector2D(x, y);
    BulletHandler::Instance()->addEnemyBullet(position.getX(), position.getY(), 
                                              16, 16, "bullet", 1, heading);
    BulletHandler::Instance()->drawBullets();
    
}

void UFO::collision()
{
    health -= 1;
    if (health == 0)
    {
        // TODO: Dying animation
        delete this;
    }
}
