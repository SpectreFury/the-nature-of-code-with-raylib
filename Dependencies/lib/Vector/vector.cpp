#include <iostream>
#include <vector.h>

void Vector::add(Vector a)
{
    x += a.x;
    y += a.y;
}

void Vector::sub(Vector a)
{
    x -= a.x;
    y -= a.y;
}

void Vector::mult(float a)
{
    x *= a;
    y *= a;
}

void Vector::div(float a)
{
    x /= a;
    y /= a;
}

float Vector::mag()
{
    return sqrt(x * x + y * y);
}

void Vector::normalize()
{
    x = x / sqrt(x * x + y * y);
    y = y / sqrt(x * x + y * y);
}

void Vector::set(float _x, float _y)
{
    x = _x;
    y = _y;
}

void Vector::limit(float value)
{
    if (x > value)
    {
        x = value;
    }
    if (y > value)
    {
        y = value;
    }
}

float Vector::magSq()
{
    return x * x + y * y;
}

void Vector::setMag(float value)
{
    normalize();
    mult(value);
}

Vector Vector::copy()
{
    return Vector{x, y};
}
