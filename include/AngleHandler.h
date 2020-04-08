#ifndef _ANGLE_HANDLER_H_
#define _ANGLE_HANDLER_H_

#include <cmath>
#include "Vector2D.h"
#include "Game.h"

#define PI 3.14159265358979323846
#define PHI 1.61803399
#define HEADING_DEFAULT 10
#define ZERO 0

static float convertDegreesToRadians(float degrees)
{
    return (degrees * PI)/ 180;
}

static Vector2D rotate(Vector2D position, float beta)
{
    float length = position.length();
    beta = convertDegreesToRadians(beta);
    float alpha = acos(convertDegreesToRadians(position.getX() / length));
    
    float x = abs(length * cos(alpha + beta)); 
    float y = length * sin(alpha + beta);
    if (y > 0) y *= -1;
    
    cout << "cuu -- " << alpha + beta << "e bucecta ==" << length << endl;
    cout << "x = " << x << " e ";
    cout << "y = " << y << endl;


    return Vector2D(x, y);
    
}

static Vector2D rotateVector(Vector2D vector, float width, float angle)
{
    angle = convertDegreesToRadians(angle);
    static float angleCossine = cos(angle); 
    static float angleSine = sin(angle);
    float y = vector.getY() + width;    
    float xRotated = vector.getX() + vector.getX() * angleCossine - y * angleSine;
    float yRotated = vector.getY() + y * angleCossine + vector.getX() * angleSine;
    
    return Vector2D(xRotated, yRotated);
}

static Vector2D setBulletHeading(float angle)
{
    float x;
    float y;
    if (angle == 0 || angle == 180) x = ZERO;
    else  x = (angle > 180)? -HEADING_DEFAULT : HEADING_DEFAULT;
    
    if (angle == 90 || angle == 270) y = ZERO;
    else y = (angle < 90 || angle > 270)? -HEADING_DEFAULT: HEADING_DEFAULT;
    
    return Vector2D(x, y);
}

static float calculateXShift(float angle)
{
    return HEADING_DEFAULT * cos(convertDegreesToRadians(angle));
}

static float calculateYShift(float angle)
{
    return HEADING_DEFAULT * sin(convertDegreesToRadians(angle));
}
#endif

