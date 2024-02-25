#pragma once;

struct Vector
{
    float x;
    float y;

    void add(Vector a);
    void sub(Vector a);
    void mult(float a);
    void div(float a);
    float mag();
    void normalize();
    void set(float _x, float _y);
    void limit(float value);
    float magSq();
    void setMag(float value);
    Vector copy();
};