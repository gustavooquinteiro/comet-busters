#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "GameObject.h"

using namespace std;

class Enemy: public ShooterObject
{
public:
    virtual string type(){ return "Enemy"; }
    
protected:
    int health;
    
    Enemy(): ShooterObject(){}
    virtual ~Enemy(){}    
};

#endif
