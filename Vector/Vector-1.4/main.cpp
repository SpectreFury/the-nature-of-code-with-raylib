#include <iostream>
#include <Raylib/raylib.h>
#include <Raylib/raymath.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct Vector
{
    float x;
    float y;

    void add(Vector a)
    {
        x += a.x;
        y += a.y;
    }

    void sub(Vector a)
    {
        x -= a.x;
        y -= a.y;
    }

    void mult(float a)
    {
        x *= a;
        y *= a;
    }

    void div(float a)
    {
        x *= a;
        y *= a;
    }

    float mag()
    {
        return sqrt(x * x + y * y);
    }

    void normalize()
    {
        x = x / sqrt(x * x + y * y);
        y = y / sqrt(x * x + y * y);
    }

    void set(float _x, float _y)
    {
        x = _x;
        y = _y;
    }

    void limit(float value)
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

    float magSq()
    {
        return x * x + y * y;
    }

    void setMag(float value)
    {
        normalize();
        mult(value);
    }
};

void applyForce(Vector &acceleration, Vector force)
{
    acceleration.add(force);
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "This is the window");
    SetTargetFPS(FLAG_VSYNC_HINT);

    Vector position = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    Vector velocity = {0, 0};
    Vector acceleration = {0, 0};
    Vector gravity = {0, 0.1f};
    Vector wind = {1, 0};
    Vector mouse = {GetMouseX(), GetMouseY()};

    while (!WindowShouldClose())
    {
        mouse.set(GetMouseX(), GetMouseY());
        mouse.sub(position);

        std::cout << mouse.x << " " << mouse.y << std::endl;

        mouse.normalize();
        mouse.mult(0.5);

        applyForce(acceleration, mouse);

        velocity.add(acceleration);
        position.add(velocity);

        if (position.y > SCREEN_HEIGHT)
        {
            velocity.y *= -1;
        }

        BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(RAYWHITE);

        DrawCircle(position.x, position.y, 16, BLACK);

        EndDrawing();

        acceleration.set(0, 0);
    }

    CloseWindow();
}