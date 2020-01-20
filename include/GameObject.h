#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include "Vector2D.h"
#include "LoaderParams.h"

using namespace std;

class GameObject
{
public:
    virtual ~GameObject();
    virtual void load(unique_ptr<LoaderParams> const &params) = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual void collision() = 0;
    virtual string type() = 0;
    Vector2D& getPosition() { return position; }
    int getHeight() { return height; }
    int getWidth() { return width; }
    bool updating() { return statusUpdating; }
    bool dead() { return isDead; }
    void setUpdating(bool update) { statusUpdating = update; }
protected:
    GameObject();
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    
    int width;
    int height;
    
    int currentRow;
    int currentFrame;
        
    string textureId;
    
    bool statusUpdating;
    bool isDead;
};


class ShooterObject: public GameObject
{
public:
    ~ShooterObject();
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void load(unique_ptr<LoaderParams> const &params);
    virtual void collision();
    virtual string type() { return "ShooterObject"; }    
protected:
    ShooterObject();
    int bulletFiringSpeed;
    int bulletCounter;
    int moveSpeed;
    
    bool playedDeathSound;

    
};

#endif
