#include <iostream>
#include <vector.h>
#include <Raylib/raylib.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct Mover
{
    Vector position = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    Vector velocity = {0, 0};
    Vector acceleration = {0, 0};
    float radius = 1;

    Mover(float radius)
    {
        this->radius = radius;
    }

    void applyForce(Vector force)
    {
        acceleration.add(force);
    }

    void display()
    {
        DrawCircle(position.x, position.y, radius, BLACK);
    };

    void update()
    {
        velocity.add(acceleration);
        position.add(velocity);

        acceleration.mult(0);
    }

    void checkBounds()
    {
        if (position.x >= SCREEN_WIDTH)
        {
            position.x = SCREEN_WIDTH;
            velocity.x = velocity.x * -1;
        }
        if (position.x <= 0)
        {
            position.x = 0;
            velocity.x = velocity.x * -1;
        }
        if (position.y >= SCREEN_HEIGHT)
        {
            position.y = SCREEN_HEIGHT;
            velocity.y = velocity.y * -1;
        }
        if (position.y <= 0)
        {
            position.y = 0;
            velocity.y = velocity.y * -1;
        }
    }
};

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "This is force");

    SetTargetFPS(FLAG_VSYNC_HINT);

    Mover mov(10);
    Vector gravity = {0, 0.1f};
    Vector wind = {0.1f, 0};

    while (!WindowShouldClose())
    {
        mov.applyForce(gravity);
        mov.update();
        mov.checkBounds();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            mov.applyForce(wind);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        mov.display();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}