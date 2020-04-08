#include "../include/BulletHandler.h"
#include "../include/ScreenHandler.h"

BulletHandler* BulletHandler::instance = 0;

BulletHandler::BulletHandler(){}

BulletHandler* BulletHandler::Instance()
{
    if (instance == 0)
        instance = new BulletHandler();
    return instance;
}

void BulletHandler::addPlayerBullet(int x, int y, int width, int height, 
                                    std::string textureID, int numFrames, 
                                    Vector2D heading, Player* player)
{
    PlayerBullet* playerBullet = new PlayerBullet();
    LoaderParams* parameters = new LoaderParams(x, y, width, height, 
                                                textureID, numFrames, 0, 0);
    playerBullet->load(unique_ptr<LoaderParams>(parameters), heading, player);
    playerBullets.push_back(playerBullet);
}

void BulletHandler::addEnemyBullet(int x, int y, int width, int height, 
                                   string textureID, int numFrames,
                                   Vector2D heading)
{
    EnemyBullet* enemyBullet = new EnemyBullet();
    LoaderParams* parameters = new LoaderParams(x, y, width, height, 
                                                textureID, numFrames, 0, 0);
    enemyBullet->load(unique_ptr<LoaderParams>(parameters), heading);
    enemyBullets.push_back(enemyBullet);
}

void BulletHandler::updateBullets()
{
    vector<PlayerBullet*>::iterator playerIterator;
    for (playerIterator = playerBullets.begin(); playerIterator != playerBullets.end();)
    {
        PlayerBullet* bullet = *playerIterator;
        if (!isInScreen(bullet->getPosition()) || 
            bullet->isDead())
        {
            delete *playerIterator;
            playerBullets.erase(playerIterator);
        }
        else
        {
            bullet->update();
            playerIterator++;
        }
    }
    
     vector<EnemyBullet*>::iterator enemyIterator;
    for (enemyIterator = enemyBullets.begin(); enemyIterator != enemyBullets.end();)
    {
        EnemyBullet* bullet = *enemyIterator;
        if (!isInScreen(bullet->getPosition()) ||
            bullet->isDead())
        {
            delete *enemyIterator;
            enemyBullets.erase(enemyIterator);
        }
        else
        {
            bullet->update();
            enemyIterator++;
        }
    }
}

void BulletHandler::drawBullets()
{
    for (auto bullet: playerBullets)
        bullet->draw();
    
    for (auto bullet: enemyBullets)
        bullet->draw();
}

void BulletHandler::clearBullets()
{
    playerBullets.clear();
    enemyBullets.clear();
}


vector<EnemyBullet*> BulletHandler::getEnemyBullets() const
{ 
    return enemyBullets; 
}

vector<PlayerBullet*> BulletHandler::getPlayerBullets() const
{
    return playerBullets; 
}

