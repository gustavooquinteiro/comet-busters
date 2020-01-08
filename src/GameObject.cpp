#include "../include/GameObject.h"
#include "../include/TextureManager.h"

GameObject::GameObject(int x, int y, int width, int height, std::string textureId): width(width), height(height), textureId(textureId)
{
    position = Vector2D(x, y);
    
}

void GameObject::draw(SDL_Renderer* renderer)
{
    TextureManager::Instance()->draw(textureId, (int)position.getX(), (int)position.getY(), width, height, renderer);    
}

void GameObject::update()
{
    position.setX(position.getX() + 1);
    position.setY(position.getY() + 1);
}

void GameObject::clean()
{
}

void GameObject::load()
{
}

