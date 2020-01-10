#include "../include/Game.h"
#include "../include/GameObject.h"
#include "../include/TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* params): GameObject(params), 
                                                            position(params->getX(), params->getY()),
                                                            velocity(0, 0),
                                                            acceleration(0, 0)
{
    width = params->getWidth();
    height = params->getHeight();
    textureId = params->getTextureID();
}

void SDLGameObject::draw()
{
    TextureManager::Instance()->draw(textureId, (int)position.getX(), (int)position.getY(), width, height, Game::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    velocity += acceleration;
    position += velocity;
}
