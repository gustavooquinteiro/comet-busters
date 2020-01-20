#include "../include/Game.h"
#include "../include/GameObject.h"
#include "../include/TextureManager.h"

GameObject::GameObject() {}

GameObject::~GameObject(): position(0, 0), velocity(0, 0), acceleration(0, 0), width(0), height(0), currentRow(0), currentFrame(0), statusUpdating(false), isDead(false) {}

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
    currentFrame = 1;
    currentRow = 1;
}

int SDLGameObject::getHeight(){ return this->height; }

int SDLGameObject::getWidth(){ return this->width; }

Vector2D& SDLGameObject::getPosition(){ return this->position; }

void SDLGameObject::clean()
{
}

SDLGameObject::~SDLGameObject()
{
}
