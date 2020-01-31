#include "../include/Comet.h"

Comet::Comet(): GameObject() {}

void Comet::load(const unique_ptr<LoaderParams>& params)
{
    GameObject::load(move(params));
}

void Comet::draw()
{
    GameObject::draw();
}

void Comet::update()
{
    acceleration.setX(1);
    
    GameObject::update();
}

void Comet::clean()
{
    GameObject::clean();
}
