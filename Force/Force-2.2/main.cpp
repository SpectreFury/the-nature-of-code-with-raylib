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

    Mover(float pos_x, float pos_y, float mass)
    {
        position = {pos_x, pos_y};
        this->mass = mass;
    }

    void applyForce(Vector force)
    {
        Vector f = force;
        f.div(mass);
        acceleration.add(f);
    }

    void display()
    {
        DrawCircle(position.x, position.y, mass * 16, BLACK);
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

    Vector gravity = {0, 0.1f};
    Vector wind = {0.1f, 0};

    Mover mover1(300, 500, 1);
    Mover mover2(500, 500, 2);

    while (!WindowShouldClose())
    {
        mover1.applyForce(gravity);
        mover1.update();
        mover1.checkBounds();

        mover2.applyForce(gravity);
        mover2.update();
        mover2.checkBounds();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            mover1.applyForce(wind);
            mover2.applyForce(wind);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        mover1.display();
        mover2.display();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}