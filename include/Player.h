#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SDL2/SDL.h>
#include "GameObject.h"
#include "GameObjectFactory.h"

class Player: public SDLGameObject
{
public:
    Player(const LoaderParams* params);
    virtual void draw();
    virtual void update();
    virtual void clean();
    long int getScore() const;
private:
    void handleInput();    
    
    long int score;
};

class PlayerCreator: public BaseCreator
{
public:
    GameObject* createGameObject() const override;
};

#endif
