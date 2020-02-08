#include "../include/Game.h"
#include "../include/GameObject.h"
#include "../include/TextureManager.h"

GameObject::~GameObject(){}

GameObject::GameObject():  updating(true), dead(false){}

ShooterObject::ShooterObject(): GameObject(),
                                bulletFiringSpeed(0),
                                bulletCounter(0),
                                moveSpeed(0),
                                dyingTime(0),
                                dyingCounter(0),
                                playedDeathSound(false){}

void ShooterObject::draw()
{
    TextureManager::Instance()->draw(textureId, 
                                     (Uint32) position.getX(), 
                                     (Uint32) position.getY(),
                                     width, 
                                     height,
                                     Game::Instance()->getRenderer(), angle);
}

void ShooterObject::update()
{
    position += velocity;
}

void ShooterObject::load(unique_ptr<LoaderParams> const &params)
{
    position = Vector2D(params->getX(), params->getY());
    
    width = params->getWidth();
    height = params->getHeight();
    textureId = params->getTextureID();
    currentFrame = 1;
    currentRow = 1;
}

void ShooterObject::clean()
{
}

ShooterObject::~ShooterObject()
{
}

void ShooterObject::collision()
{
}

void ShooterObject::doDyingAnimation()
{
    if (dyingCounter == dyingTime)
        dead = true;
    dyingCounter++;
}
