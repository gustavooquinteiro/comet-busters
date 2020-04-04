#ifndef _VECTOR_2D_H_
#define _VECTOR_2D_H_

#include <math.h>

class Vector2D
{
public:
    Vector2D();
    Vector2D(float x, float y);
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    
    float length();    
    Vector2D operator+(const Vector2D& vector);
    Vector2D& operator+=(const Vector2D& vector2);
    Vector2D operator*(float scalar);
    Vector2D& operator*=(float scalar);
    Vector2D operator-(const Vector2D& vector);
    Vector2D& operator-=(const Vector2D& vector2);
    Vector2D operator/(float scalar);
    Vector2D& operator /=(float scalar);
    
    void normalize();
private:
    float x;
    float y;
};

float scalarProduct(const Vector2D& a, const Vector2D& b);

#endif
