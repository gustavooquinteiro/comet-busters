#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "GameObject.h"

using namespace std;

class Enemy: public ShooterObject
{
public:
    virtual void draw();
    virtual void update();
    virtual void collision();
    virtual string type() { return "Enemy"; }
    int getPoints(){ return points; }
    
protected:
    int health;
    int points;
    
    Enemy();
    virtual ~Enemy(){}    
};

#endif
