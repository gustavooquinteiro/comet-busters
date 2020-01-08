#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <SDL2/SDL.h>
#include <iostream>
#include "Vector2D.h"
using namespace std;

class GameObject
{
public:
    GameObject(int x, int y, int width, int height, string textureId);
    virtual void load();
    virtual void draw(SDL_Renderer* renderer);
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
