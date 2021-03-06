#ifndef _STATE_PARSER_H_
#define _STATE_PARSER_H_

#include <iostream>
#include <vector>
#include "tinyxml.h"

using namespace std;

class GameObject;

class StateParser
{
public:
    bool parseState(const char* stateFile, string stateID, vector<GameObject*>* objects, vector<string>* textureIDs);
private:
    void parseObjects(TiXmlElement* stateRoot, vector<GameObject*>* objects);
    void parseTexture(TiXmlElement* stateRoot, vector<string>* textureIDs);
};

#endif
