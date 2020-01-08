#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <SDL2/SDL.h>
#include <iostream>
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
    int x;
    int y;
    int width;
    int height;
    
    string textureId;
};

#endif
