#include "../include/Player.h"
#include "../include/InputHandler.h"

Player::Player(int x, int y, int width, int height, std::string textureId): GameObject(x, y, width, height, textureId) {}

void Player::load()
{
    GameObject::load();
}

void Player::draw(SDL_Renderer* renderer)
{
    GameObject::draw(renderer);
}

void Player::update()
{
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
        velocity.setX(2);
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        velocity.setX(-2);
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
        velocity.setX(-2);
    
}

void Player::clean()
{
    GameObject::clean();
}

long int Player::getScore() const{ return this->score; }
