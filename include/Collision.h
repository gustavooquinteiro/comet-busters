#ifndef _COLLISION_
#define _COLLISION_

#include <SDL2/SDL.h>
#include "GameObject.h"

static const int collisionBuffer = 4;

static SDL_Rect* GameObjectToSDLRect(GameObject* object)
{
    SDL_Rect* rect = new SDL_Rect();
    rect->x = object->getPosition().getX();
    rect->y = object->getPosition().getY();
    rect->h = object->getHeight();
    rect->w = object->getWidth();
    return rect;
}

static bool RectRect(SDL_Rect* A, SDL_Rect* B)
{
    int aHbuf = A->h / collisionBuffer;
    int aWbuf = A->w / collisionBuffer;
    
    int bHbuf = B->h / collisionBuffer;
    int bWbuf = B->w / collisionBuffer;
    
    if ((A->y + A->h) - aHbuf <= B->y + bHbuf) return false;
    if (A->y + aHbuf >= (B->h + B->y) - bHbuf) return false;
    if ((A->x + A->w) - aWbuf <= B->x + bWbuf) return false;
    if (A->x + aWbuf >= (B->x + B->w) - bWbuf) return false;
    
    return true;
}

static void resolveCollision(GameObject* A, GameObject* B)
{
    Vector2D velocityA = A->getVelocity();
    Vector2D velocityB = B->getVelocity();
    Vector2D relativeVelocity = velocityA - velocityB;
    Vector2D normal = relativeVelocity;
    normal.normalize();
    
    float velocityAlongNormal = scalarProduct(relativeVelocity, normal);
    
    if (velocityAlongNormal > 0) return;
    
    float e = min(A->getRestitution(), B->getRestitution());
    
    float j = -(1 + e) * velocityAlongNormal;
    j /= 1 / A->getMass() + 1 / B->getMass();
    
    normal *= j;
    Vector2D impulseA = normal * A->getMass();
    impulseA.setX(1 / impulseA.getX());
    impulseA.setY(1 / impulseA.getY());
    
    Vector2D impulseB = normal * B->getMass();
    impulseB.setX(1 / impulseB.getX());
    impulseB.setY(1 / impulseB.getY());
    
    velocityA -= impulseA;
    velocityB += impulseB;
    
    A->setVelocity(velocityA);
    B->setVelocity(velocityB);
}

#endif
