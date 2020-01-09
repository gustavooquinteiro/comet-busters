#include "../include/GameObjectFactory.h"

bool GameObjectFactory::registerType(string typeId, BaseCreator* creator)
{
    map<string, BaseCreator*>::iterator mapIterator = creators.find(typeId);
    if (mapIterator != creators.end())
    {
        delete creator;
        return false;
    }
    
    creators[typeId] = creator;
    return true;
}

GameObject * GameObjectFactory::create(string typeID)
{
    map<string, BaseCreator*>::iterator mapIterator = creators.find(typeID);
    if (mapIterator == creators.end())
        return NULL;
    
    BaseCreator* creator = (*mapIterator).second;
    return creator->createGameObject();
}

