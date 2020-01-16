#ifndef _PAUSE_STATE_H_
#define _PAUSE_STATE_H_

#include "GameState.h"
#include "GameObject.h"
#include <vector>
using namespace std;

class PauseState: public GameState
{
public:
    void update() override;
    void render() override;
    bool onEnter() override;
    bool onExit() override;
    string getStateID() const override;
private:
    static void pauseToMain();
    static void resumePlay();
    
    static const string pauseID;
    vector<GameObject*> gameObjects;
};

#endif
