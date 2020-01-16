#ifndef _GAME_OVER_STATE_H_
#define _GAME_OVER_STATE_H_

#include "GameState.h"
#include "GameObject.h"
#include <vector>
using namespace std;

class GameOverState: public GameState
{
public:
    void update() override;
    void render() override;
    
    bool onEnter() override;
    bool onExit() override;
    string getStateID() const override;
private:
    static void gameOverToMain();
    static void restartPlay();
    
    static const string gameOverID;
    vector<GameObject*> gameObjects;
};

#endif
