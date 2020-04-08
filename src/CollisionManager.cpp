#include "../include/CollisionManager.h"
#include "../include/BulletHandler.h"
#include "../include/Collision.h"
#include "../include/Enemy.h"

void CollisionManager::checkPlayerEnemyBulletCollision(Player* player)
{
    
    SDL_Rect* rectPlayer = GameObjectToSDLRect(player);
        
    for (auto bullet: BulletHandler::Instance()->getEnemyBullets())
    {
        SDL_Rect* shot = GameObjectToSDLRect(bullet);
        
        if (RectRect(rectPlayer, shot))
        {
            if (!player->isDead() && !bullet->isDead())
            {
                resolveCollision(player, bullet);
                cout << "collision player and enemy bullet" << endl;
                bullet->collision();
                player->collision();
            }
        }
        delete shot;
    }
    delete rectPlayer;
}

void CollisionManager::checkPlayerEnemyCollision(Player* player, const vector<GameObject *> &gameObjects)
{
    SDL_Rect* rectPlayer = GameObjectToSDLRect(player);
    
    for (auto object: gameObjects)
    {
        if (object->type() != "Enemy" || !object->isUpdating())
            continue;
        
        SDL_Rect* enemy = GameObjectToSDLRect(object);
        
        if (RectRect(rectPlayer, enemy))
        {
            if (!object->isDead())
            {
                resolveCollision(player, object);
                cout << "collision player and enemy" << endl;
                player->collision();
                object->collision();
            }
        }
        delete enemy;
    }
    delete rectPlayer;
}

void CollisionManager::checkEnemyPlayerBulletCollision(const vector<GameObject *>& gameObjects)
{
    for (auto object: gameObjects)
    {
        for (auto playerBullets: BulletHandler::Instance()->getPlayerBullets())
        {
            if (object->type() != "Enemy")
                continue;
            
            SDL_Rect* rectEnemy = GameObjectToSDLRect(object);
            
            SDL_Rect* playerShot = GameObjectToSDLRect(playerBullets);
            
            if (RectRect(rectEnemy, playerShot))
            {
                resolveCollision(playerBullets, object);
                cout << "collision player bullet and enemy" << endl;
                if (dynamic_cast<Enemy*>(object))
                {
                    Enemy* enemy = dynamic_cast<Enemy*>(object);
                    playerBullets->collision(enemy);
                }
                object->collision();
            }
            
            delete rectEnemy;
            delete playerShot;
        }
    }
}
