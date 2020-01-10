#ifndef _GAME_OBJECT_FACTORY_H_
#define _GAME_OBJECT_FACTORY_H_

#include <map>
#include <string>
#include "GameObject.h"

class BaseCreator
{
public:
    virtual GameObject* createGameObject() const = 0;
    virtual ~BaseCreator(){}
    
};

class GameObjectFactory
{
public:
    static GameObjectFactory* Instance();
    bool registerType(string typeID, BaseCreator* creator);
    GameObject* create(string typeID);
private:
    GameObjectFactory();
    
    map<string, BaseCreator*> creators;
    static GameObjectFactory* instance;
};

#endif
