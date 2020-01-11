#include "../include/Game.h"
#include "../include/GameObject.h"
#include "../include/TextureManager.h"

SDLGameObject::SDLGameObject(): GameObject() {}

void SDLGameObject::draw()
{
    TextureManager::Instance()->draw(textureId, (int)position.getX(), (int)position.getY(), width, height, Game::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    velocity += acceleration;
    position += velocity;
}

void SDLGameObject::load(const LoaderParams* params)
{
    position = Vector2D(params->getX(), params->getY());
    velocity = Vector2D(0, 0);
    acceleration = Vector2D(0, 0);
    width = params->getWidth();
    height = params->getHeight();
    textureId = params->getTextureID();
    
}


void SDLGameObject::clean()
{
}
