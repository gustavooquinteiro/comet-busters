#include "../include/Enemy.h"
#include "../include/ScreenHandler.h"

Enemy::Enemy(): ShooterObject()
{
    moveSpeed = 2;
}

void Enemy::update()
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
    }
    else
    {
        velocity.setX(0);
        velocity.setY(0);
        // TODO: Dying animation
    }
    ShooterObject::update();
}

void Enemy::draw()
{
    ShooterObject::draw();
}

void Enemy::collision()
{
    health -= 1;
    if (health == 0)
    {
        // TODO: Dying animation
        delete this;
    }
}
