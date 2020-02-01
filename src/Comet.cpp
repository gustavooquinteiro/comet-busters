#include "../include/Comet.h"

Comet::Comet(): ShooterObject()
{
    srand(time(NULL));
    acceleration.setX(rand() % 3);
}

void Comet::load(const unique_ptr<LoaderParams>& params)
{
    ShooterObject::load(move(params));
}

void Comet::draw()
{
    ShooterObject::draw();
}

void Comet::update()
{  
    ShooterObject::update();
}

void Comet::clean()
{
    ShooterObject::clean();
}

void Comet::collision()
{
    ShooterObject::collision();
}
