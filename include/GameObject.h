#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include "Vector2D.h"
#include "LoaderParams.h"

using namespace std;

class GameObject
{
public:
    virtual ~GameObject();
    virtual void load(unique_ptr<LoaderParams> const &params) = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual void collision() = 0;
    virtual string type() = 0;
    Vector2D& getPosition() { return position; }
    Vector2D& getVelocity() { return velocity; }
    int getHeight() { return height; }
    int getWidth() { return width; }
    float getRestitution() { return restitution; }
    float getMass() { return mass; }
    bool isUpdating() { return updating; }
    bool isDead() { return dead; }
    void setUpdating(bool update) { updating = update; }
    void setVelocity(Vector2D newVelocity) { velocity = newVelocity; }
protected:
    GameObject();
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    
    int width;
    int height;
    
    int currentRow;
    int currentFrame;
        
    string textureId;
    
    double angle;
    
    bool updating;
    bool dead;
    
    float mass;
    float restitution;
      
};


class ShooterObject: public GameObject
{
public:
    ~ShooterObject();
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void load(unique_ptr<LoaderParams> const &params);
    virtual void collision();
    virtual string type() { return "ShooterObject"; }    
protected:
    ShooterObject();
    void doDyingAnimation();
    
    int bulletFiringSpeed;
    int bulletCounter;
    int moveSpeed;
    
    int dyingTime;
    int dyingCounter;
    
    bool playedDeathSound;
};

#endif
