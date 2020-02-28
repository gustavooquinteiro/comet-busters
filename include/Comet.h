#ifndef _COMET_H_
#define _COMET_H_

#include "Enemy.h"
#include "GameObjectFactory.h"

class Comet: public Enemy
{
public:
    Comet();
    virtual void load(const unique_ptr<LoaderParams> &params);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void collision();
    string type(){ return "Comet"; }
    int getPoints(){ return points; }
private:
    Comet(int points, int health, float mass);
        
    int points;
};

class CometCreator: public BaseCreator
{
public:
    GameObject* createGameObject() const
    {
        return new Comet();
    }
};
#endif
