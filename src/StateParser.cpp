#include "../include/Game.h"
#include "../include/StateParser.h"
#include "../include/TextureManager.h"
#include "../include/GameObjectFactory.h"

bool StateParser::parseState(const char* stateFile, string stateID, vector<GameObject*>* objects, vector<string>* textureIDs)
{
    TiXmlDocument xmlDoc;
    if (!xmlDoc.LoadFile(stateFile))
    {
        cerr << xmlDoc.ErrorDesc() << endl;
        return false;
    }
    
    TiXmlElement* root = xmlDoc.RootElement();
    TiXmlElement* stateRoot = 0;
    
    for(TiXmlElement* element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
    {
        if (element->Value() == stateID)
            stateRoot = element;
    }
    
    TiXmlElement* textureRoot = 0;
     for(TiXmlElement* element = stateRoot->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
    {
        if (element->Value() == string("TEXTURES"))
            textureRoot = element;
    }
    parseTexture(textureRoot, textureIDs);
    TiXmlElement* objectRoot = 0;

    for(TiXmlElement* element = stateRoot->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
    {
        if (element->Value() == string("OBJECTS"))
            objectRoot = element;
    }
    parseObjects(objectRoot, objects);
    
    return true;
}

void StateParser::parseTexture(TiXmlElement* stateRoot, vector<string>* textureIDs)
{
    for(TiXmlElement* element = stateRoot->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
    {
        string filename = element->Attribute("filename");
        string id = element->Attribute("ID");
        textureIDs->push_back(id);
        TextureManager::Instance()->load(filename, id, Game::Instance()->getRenderer());
    }
}

void StateParser::parseObjects(TiXmlElement* stateRoot, vector<GameObject *>* objects)
{
     for(TiXmlElement* element = stateRoot->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
    {
        int x, y, width, height, numFrames, callbackID = 0, animSpeed = 0;
        string textureID;
        
        element->Attribute("x", &x);
        element->Attribute("y", &y);
        element->Attribute("width", &width);
        element->Attribute("height", &height);
        element->Attribute("numFrames", &numFrames);
        element->Attribute("callbackID", &callbackID);
        element->Attribute("animSpeed", &animSpeed);
        
        textureID = element->Attribute("textureID");
        
        GameObject* gameObject = GameObjectFactory::Instance()->create(element->Attribute("type"));
        gameObject->load(unique_ptr<LoaderParams>(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed)));
        objects->push_back(gameObject);
    }
    
}
