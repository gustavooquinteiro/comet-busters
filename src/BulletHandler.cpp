#include "../include/BulletHandler.h"

BulletHandler* BulletHandler::instance = 0;

BulletHandler::BulletHandler(){}

BulletHandler* BulletHandler::Instance()
{
    if (instance == 0)
        instance = new BulletHandler();
    return instance;
}

void BulletHandler::addPlayerBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading)
{
    PlayerBullet* playerBullet = new PlayerBullet();
    playerBullet->load(unique_ptr<LoaderParams>(new LoaderParams(x, y, width, height, textureID, numFrames, 0, 0)), heading);
    playerBullets.push_back(playerBullet);
}

void BulletHandler::addEnemyBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading)
{
    EnemyBullet* enemyBullet = new EnemyBullet();
    enemyBullet->load(unique_ptr<LoaderParams>(new LoaderParams(x, y, width, height, textureID, numFrames, 0, 0)), heading);
    enemmyBullets.push_back(enemyBullet);
}

