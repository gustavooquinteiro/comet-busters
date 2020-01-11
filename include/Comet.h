#ifndef _COMET_H_
#define _COMET_H_

#include <SDL2/SDL.h>
#include "GameObject.h"

class Comet: public SDLGameObject
{
public:
    Comet(const LoaderParams* params);
    virtual void load();
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif
