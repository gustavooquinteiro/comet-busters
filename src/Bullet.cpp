#include "../include/Bullet.h"
#include <ctime>

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::load(const unique_ptr<LoaderParams>& params, Vector2D heading)
{
    ShooterObject::load(move(params));
    this->heading = heading;
}

void EnemyBullet::update()
{
    int xShift = heading.getX();
    int yShift = heading.getY();
    if (heading.getX() < 0) xShift -= rand() % 3;
    if (heading.getY() < 0) yShift -= rand() % 3;
    this->velocity.setX(xShift);
    this->velocity.setY(yShift);
    ShooterObject::update();
}

void EnemyBullet::collision()
{
    dead = true;
}

void EnemyBullet::draw()
{
    ShooterObject::draw();
}

void EnemyBullet::clean()
{
    ShooterObject::clean();
}


PlayerBullet::~PlayerBullet()
{
}
void PlayerBullet::load(const unique_ptr<LoaderParams> &params,
                        Vector2D heading, Player* player)
{
    ShooterObject::load(move(params));
    this->heading = heading;
    this->player = player;
}

void PlayerBullet::draw()
{
    ShooterObject::draw();
}

void PlayerBullet::collision()
{
    dead = true;
}

void PlayerBullet::collision(Enemy* enemy)
{
    collision();
    this->player->setPoints(enemy->getPoints());
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
