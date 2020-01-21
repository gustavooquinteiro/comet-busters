#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SDL2/SDL.h>
#include "GameObject.h"
#include "GameObjectFactory.h"

class Player: public ShooterObject
{
public:
    Player();
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void load(unique_ptr<LoaderParams> const &params);
    long int getScore() const;
private:
    void handleInput();    
    void handleAnimation();
    
    long int score;
};

class PlayerCreator: public BaseCreator
{
public:
    GameObject* createGameObject() const
    {
        return new Player();
    }
};

#endif
