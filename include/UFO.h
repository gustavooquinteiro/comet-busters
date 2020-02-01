#ifndef _UFO_H_
#define _UFO_H_

#include "Enemy.h"
#include "GameObjectFactory.h"

class UFO: public Enemy
{
public:
    virtual ~UFO(){}
    UFO();
    virtual void collision();
    virtual void update();    
};

class UFOCreator: public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new UFO();
    }
};

#endif
