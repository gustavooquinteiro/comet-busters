#include "../include/CollisionManager.h"
#include "../include/BulletHandler.h"
#include "../include/Collision.h"

void CollisionManager::checkPlayerEnemyBulletCollision(Player* player)
{
    SDL_Rect* rectPlayer = new SDL_Rect();
    rectPlayer->x = player->getPosition().getX();
    rectPlayer->y = player->getPosition().getY();
    rectPlayer->h = player->getHeight();
    rectPlayer->w = player->getWidth();
    
    for (auto bullet: BulletHandler::Instance()->getEnemyBullets())
    {
        SDL_Rect* shot = new SDL_Rect();
        shot->x = bullet->getPosition().getX();
        shot->y = bullet->getPosition().getY();
        shot->h = bullet->getHeight();
        shot->w = bullet->getWidth();
        
        if (RectRect(rectPlayer, shot))
        {
            if (!player->dead() && !bullet->dead())
            {
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
    SDL_Rect* rectPlayer = new SDL_Rect();
    rectPlayer->x = player->getPosition().getX();
    rectPlayer->y = player->getPosition().getY();
    rectPlayer->h = player->getHeight();
    rectPlayer->w = player->getWidth();
    
    for (auto object: gameObjects)
    {
        if (object->type() != "Enemy" || !object->updating())
            continue;
        
        SDL_Rect* enemy = new SDL_Rect();
        enemy->x = object->getPosition().getX();
        enemy->y = object->getPosition().getY();
        enemy->h = object->getHeight();
        enemy->w = object->getWidth();
        
        if (RectRect(rectPlayer, enemy))
        {
            if (!object->dead())
                player->collision();
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
            
            SDL_Rect* rectEnemy = new SDL_Rect();
            rectEnemy->x = object->getPosition().getX();
            rectEnemy->y = object->getPosition().getY();
            rectEnemy->h = object->getHeight();
            rectEnemy->w = object->getWidth();
            
            SDL_Rect* playerShot = new SDL_Rect();
            playerShot->x = playerBullets->getPosition().getX();
            playerShot->y = playerBullets->getPosition().getY();
            playerShot->h = playerBullets->getHeight();
            playerShot->w = playerBullets->getWidth();
            
            if (RectRect(rectEnemy, playerShot))
            {
                playerBullets->collision();
                object->collision();
            }
            
            delete rectEnemy;
            delete playerShot;
        }
    }
}
