#include "../include/Vector2D.h"
#include <stdexcept> 

using namespace std;

Vector2D::Vector2D(float x_position, float y_position): x(x_position), y(y_position) {}

float Vector2D::getX() const
{
    return this->x;
}

float Vector2D::getY() const
{
    return this->y;
}

void Vector2D::setX(float x)
{
    this->x = x;
}

void Vector2D::setY(float y)
{
    this->y = y;
}

float Vector2D::length()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

Vector2D Vector2D::operator+(const Vector2D& vector) const
{
    return Vector2D(this->x + vector.getX(), this->y + vector.getY());
}

Vector2D operator+=(Vector2D& vector1, const Vector2D& vector2)
{
    vector1.setX(vector1.getX() + vector2.getX());
    vector1.setY(vector1.getY() + vector2.getY());
    return vector1;
}

Vector2D Vector2D::operator*(float scalar)
{
   return Vector2D(this->getX() * scalar, this->getY() * scalar);
}

Vector2D& Vector2D::operator*=(float scalar)
{
    this->setX(this->getX() * scalar);
    this->setY(this->getY() * scalar);
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D& vector) const
{
    return Vector2D(this->getX() - vector.getX(), this->getY() - vector.getY());
}

Vector2D operator-=(Vector2D& vector1, const Vector2D& vector2)
{
    vector1.setX(vector1.getX() - vector2.getX());
    vector1.setY(vector1.getY() - vector2.getY());
    return vector1;
}

Vector2D Vector2D::operator/(float scalar)
{
    return Vector2D(this->getX() / scalar, this->getY() / scalar);
}

Vector2D& Vector2D::operator/=(float scalar)
{
    this->setX(this->getX() / scalar);
    this->setY(this->getY() / scalar);
    return *this;
}

void Vector2D::normalize()
{
    if (this->length() == 0)
        throw runtime_error("Math error: Attempted to divide by zero\n"); 
    (*this) *= 1 / this->length();
}


