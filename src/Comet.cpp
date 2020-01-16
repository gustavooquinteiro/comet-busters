#include "../include/Comet.h"

Comet::Comet(): SDLGameObject() {}

void Comet::load(const LoaderParams* params)
{
    SDLGameObject::load(params);
}

void Comet::draw()
{
    SDLGameObject::draw();
}

void Comet::update()
{
    acceleration.setX(1);
    
    SDLGameObject::update();
}

void Comet::clean()
{
    SDLGameObject::clean();
}
