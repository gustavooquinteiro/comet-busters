#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <SDL2/SDL.h>
#include <iostream>
#include "Vector2D.h"
#include "LoaderParams.h"

using namespace std;

class GameObject
{
public:
    virtual void load(const LoaderParams* params);
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
protected:
    GameObject(const LoaderParams* params);
    virtual ~GameObject();

};


class SDLGameObject: public GameObject
{
public:
    SDLGameObject(const LoaderParams* params);
    virtual void draw();
    virtual void update();
    virtual void clean();
protected:

    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    
    int width;
    int height;
    
 
    
    string textureId;
};

#endif
