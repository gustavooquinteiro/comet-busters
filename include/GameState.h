#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include <iostream>
#include <vector>
using namespace std;

class GameState
{
public:
    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;
    
    virtual string getStateID() const = 0;
    
protected:
    vector<string> textureIDList;
    static const char* configFile;
};

#endif
