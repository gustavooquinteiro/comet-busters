#include "../include/UFO.h"
#include "../include/BulletHandler.h"

UFO::UFO(): Enemy()
{
    health = 1;
    moveSpeed = 3;
}

void UFO::update()
{
    if (!isDead)
    {
        velocity.setX(rand() % moveSpeed);
        velocity.setY(moveSpeed);
        int x = rand() % 7 - 3;
        int y = rand() % 7 - 3;
        Vector2D heading = Vector2D(x, y);
        BulletHandler::Instance()->addEnemyBullet(position.getX(), position.getY(), 16, 16, "bullet", 1, heading);
    } 
    else
    {
        velocity.setY(0);
        // TODO: Dying animation
    }
    ShooterObject::update();
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
