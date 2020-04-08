#ifndef _BULLET_MANAGER_H_
#define _BULLET_MANAGER_H_

#include "Enemy.h"
#include "Player.h"
#include "GameObject.h"
using namespace std;

class PlayerBullet: public ShooterObject
{
public:
    PlayerBullet(): ShooterObject(){}
    virtual ~PlayerBullet();
    string type() { return "PlayerBullet"; }
    void load(const unique_ptr<LoaderParams> &params, Vector2D heading, Player* player);
    void draw() override;
    void collision();
    void collision(Enemy* enemy);
    void update() override;
    void clean() override;
private:
    Vector2D heading;
    Player* player;
};

class EnemyBullet: public ShooterObject
{
public:
    EnemyBullet(): ShooterObject(){}
    virtual ~EnemyBullet();
    string type(){ return "EnemyBullet"; }
    void load(const unique_ptr<LoaderParams> &params, Vector2D heading);
    void draw() override;
    void collision();
    void update() override;
    void clean() override;
private:
    Vector2D heading;
};

#endif
