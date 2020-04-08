#ifndef _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "GameState.h"
#include "CollisionManager.h"
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
    
    void setObjects(GameObject* object);
    static PlayState* Instance();
    
private:
    static const string playID;
    static PlayState* instance;
    
    CollisionManager collisionManager;
    
    vector<GameObject*> gameObjects;
};

#endif
