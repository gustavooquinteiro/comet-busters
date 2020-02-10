#include "../include/Bullet.h"

PlayerBullet::~PlayerBullet()
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::load(const unique_ptr<LoaderParams>& params, Vector2D heading)
{
    ShooterObject::load(move(params));
    this->heading = heading;
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
