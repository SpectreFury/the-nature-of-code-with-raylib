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
    float mass = 1;

    void display()
    {
        DrawCircle(position.x, position.y, 10, BLACK);
    }

    void update()
    {
        velocity.add(acceleration);
        position.add(velocity);

        acceleration = {0, 0};
    }

    void applyForce(Vector force)
    {
        force.div(mass);
        acceleration.add(force);
    }

    void checkBounds()
    {
        if (position.x > SCREEN_WIDTH || position.x < 0)
        {
            velocity.x = velocity.x * -1;
        }
        if (position.y > SCREEN_HEIGHT || position.y < 0)
        {
            velocity.y = velocity.y * -1;
        }
    }
};

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "This is force");

    SetTargetFPS(FLAG_VSYNC_HINT);

    Mover circle;
    circle.mass = 1;
    Mover circleHeavy;
    circle.mass = 2;
    Vector gravity = {0, 0.1};
    Vector wind = {0.1, 0};

    while (!WindowShouldClose())
    {
        circleHeavy.checkBounds();
        circleHeavy.applyForce(gravity);
        circleHeavy.update();
        circle.checkBounds();
        circle.applyForce(gravity);
        circle.update();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            circle.applyForce(wind);
            circleHeavy.applyForce(wind);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        circle.display();
        circleHeavy.display();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}