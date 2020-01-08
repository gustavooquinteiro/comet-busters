#ifndef _COMET_H_
#define _COMET_H_

#include <SDL2/SDL.h>
#include "GameObject.h"

class Comet: public GameObject
{
public:
    Comet(int x, int y, int width, int height, std::string textureId);
    void load();
    void draw(SDL_Renderer* renderer);
    void update();
    void clean();
};

#endif
