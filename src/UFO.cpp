#include "../include/UFO.h"
#include "../include/BulletHandler.h"

UFO::UFO(): Enemy()
{
    health = 1;
    moveSpeed = 2;
}

void UFO::update()
{
    Enemy::update();
    shoot();
}

void UFO::shoot()
{
    static int counter = moveSpeed * 100;
    if (counter < moveSpeed)
    {
        Vector2D heading = velocity;
        BulletHandler::Instance()->addEnemyBullet(position.getX(), position.getY(), 
                                                  33, 33, "bullet3", 1, heading);
        counter = moveSpeed * 100;
    }
    counter--;
}

void UFO::draw()
{
    Enemy::draw();
}

void UFO::collision()
{
    Enemy::collision();
}
