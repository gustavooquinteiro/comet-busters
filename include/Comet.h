#ifndef _COMET_H_
#define _COMET_H_

#include <SDL2/SDL.h>
#include "GameObject.h"

class Comet: public SDLGameObject
{
public:
    Comet();
    virtual void load(const LoaderParams* params);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif
