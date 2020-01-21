#ifndef _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "GameState.h"
#include <vector>
using namespace std;

class PlayState: public GameState
{
public:
    void update() override;
    void render() override;
    
    bool onEnter() override;
    bool onExit() override;
    
    string getStateID() const override;
    
    bool checkCollision(GameObject* object, GameObject* other);
private:
    static const string playID;
    vector<GameObject*> gameObjects;
};

#endif
