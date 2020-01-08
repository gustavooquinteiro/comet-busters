#include "../include/Comet.h"

Comet::Comet(int x, int y, int width, int height, std::string textureId): GameObject(x, y, width, height, textureId) {}

void Comet::load()
{
    GameObject::load();
}

void Comet::draw(SDL_Renderer* renderer)
{
    GameObject::draw(renderer);
}

void Comet::update()
{
}

void Comet::clean()
{
    GameObject::clean();
}
