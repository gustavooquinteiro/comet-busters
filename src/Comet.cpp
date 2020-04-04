#include "../include/Comet.h"
#include "../include/PlayState.h"

Comet::Comet(): Enemy()
{
    points = 100;
    health = 3;
    mass = 300.f;
    restitution = 5.f;
}

Comet::Comet(int points, int health, float mass): Enemy(), points(points)
{
    this->health = health;
    this->mass = mass;
}

void Comet::load(const unique_ptr<LoaderParams>& params)
{
    ShooterObject::load(move(params));
}

void Comet::draw()
{
    Enemy::draw();
}

void Comet::update()
{  
    Enemy::update();
}

void Comet::clean()
{
    ShooterObject::clean();
}

void Comet::collision()
{
    Enemy::collision();
    if (health != 0)
    {
        static int remainQuantity = 1;
        int remainPoints = points << 1;
        int remainHealth = health;
        int remainMass = mass / 2;
        remainQuantity <<= 1;
        for (int i = 0; i < remainQuantity; i++)
        {
            Comet* remain = new Comet(remainPoints, remainHealth, remainMass); 
            remain->load(unique_ptr<LoaderParams>(new LoaderParams(position.getX() + 12*i, 
                                                                   position.getY() + 10*i,
                                                                   width, height,
                                                                   "comet",1, 0, 0)));
            PlayState::Instance()->setObjects(remain);
        }
    }
}
