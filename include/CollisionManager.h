#ifndef _COLLISION_MANAGER_H_
#define _COLLISION_MANAGER_H_

#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;

class CollisionManager
{
public:
    void checkPlayerEnemyBulletCollision(Player* player);
    void checkPlayerEnemyCollision(Player* player, const vector<GameObject*> gameObjects);
    void checkEnemyPlayerBulletCollision(const vector<GameObject*> gameObjects);
};

#endif
