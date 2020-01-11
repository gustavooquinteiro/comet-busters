#include "../include/Comet.h"

Comet::Comet(const LoaderParams* params): SDLGameObject(params) {}

void Comet::load()
{
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
    GameObject::clean();
}
