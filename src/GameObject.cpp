#include "../include/GameObject.h"
#include "../include/TextureManager.h"

GameObject::GameObject(int x, int y, int width, int height, std::string textureId): position(x, y), velocity(0,0), acceleration(0,0), width(width), height(height), textureId(textureId){}

void GameObject::draw(SDL_Renderer* renderer)
{
    TextureManager::Instance()->draw(textureId, (int)position.getX(), (int)position.getY(), width, height, renderer);    
}

void GameObject::update()
{
    velocity += acceleration;
    position += velocity;
}

void GameObject::clean()
{
}

void GameObject::load()
{
}

