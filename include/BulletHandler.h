#ifndef _BULLET_HANDLER_H_
#define _BULLET_HANDLER_H_

#include "Vector2D.h"
#include "Bullet.h"
#include <iostream>
#include <vector>
using namespace std;

class BulletHandler
{
public:
    void addPlayerBullet(int x, int y, int width, int height, string textureID, int numFrames, Vector2D heading);
    void addEnemyBullet(int x, int y, int width, int height, string textureID, int numFrames, Vector2D heading);
    static BulletHandler* Instance();
    
    void updateBullets();
    void drawBullets();

    vector<PlayerBullet*> getPlayerBullets() const;
    vector<EnemyBullet*> getEnemyBullets() const;
private:
    BulletHandler();
    static BulletHandler* instance;
    
    vector<PlayerBullet*> playerBullets;
    vector<EnemyBullet*> enemyBullets;
}

#endif
