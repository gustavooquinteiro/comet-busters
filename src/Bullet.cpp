#include "../include/Bullet.h"

void PlayerBullet::load(const unique_ptr<LoaderParams> &params, Vector2D heading)
{
    ShooterObject::load(params);
    this->heading = heading;
}

void PlayerBullet::draw()
{
    ShooterObject::draw();
}

void PlayerBullet::collision()
{
    isDead = true;
}

void PlayerBullet::update()
{
    velocity.setX(heading.getX());
    velocity.setY(heading.getY());
    ShooterObject::update();
}

void PlayerBullet::clean()
{
    ShooterObject::clean();
}
