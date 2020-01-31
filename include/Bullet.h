#ifndef _BULLET_MANAGER_H_
#define _BULLET_MANAGER_H_

#include "GameObject.h"
using namespace std;

class PlayerBullet: public ShooterObject
{
public:
    PlayerBullet(): ShooterObject(){}
    virtual ~PlayerBullet();
    string type() { return "PlayerBullet"; }
    void load(const unique_ptr<LoaderParams> &params, Vector2D heading);
    void draw() override;
    void collision() override;
    void update() override;
    void clean() override;
private:
    Vector2D heading;
};

class EnemyBullet: public PlayerBullet
{
public:
    EnemyBullet(): PlayerBullet(){}
    virtual ~EnemyBullet();
    string type(){ return "EnemyBullet"; }
};

#endif
