#include "../include/GameObject.h"
#include "../include/TextureManager.h"

GameObject::GameObject(int x, int y, int width, int height, std::string textureId): x(x), y(y), width(width), height(height), textureId(textureId){}

void GameObject::draw(SDL_Renderer* renderer)
{
    TextureManager::Instance()->draw(textureId, x, y, width, height, renderer);    
}

void GameObject::update()
{
    x++;
}

void GameObject::clean()
{
}

