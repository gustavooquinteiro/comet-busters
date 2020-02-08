#include "../include/UFO.h"
#include "../include/Game.h"
#include "../include/BulletHandler.h"

UFO::UFO(): Enemy()
{
    health = 1;
    moveSpeed = 2;
}

bool isOutOfWidth(Vector2D position)
{
    if (position.getX() > Game::Instance()->getGameWidth() || 
        position.getX() < 0)
        return true;
    return false;
}

bool isOutOfHeight(Vector2D position)
{
    if (position.getY() > Game::Instance()->getGameHeight() || 
        position.getY() < 0)
        return true;
    return false;
}

bool isInScreen(Vector2D position)
{
    if (!isOutOfWidth(position) && !isOutOfHeight(position))
        return true;
    return false;
}

void UFO::update()
{
    if (!isDead())
    {
        static int xShift = moveSpeed;
        static int yShift = moveSpeed;

        if (!isInScreen(position))
        {
            if (isOutOfHeight(position) && isOutOfWidth(position))
            {
                xShift = -xShift + 1;
                yShift = -yShift + 1;
            }
            else if (isOutOfWidth(position))
            {
                xShift = -xShift;
            }
            else if (isOutOfHeight(position))
            {
                yShift = -yShift;
            }
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
