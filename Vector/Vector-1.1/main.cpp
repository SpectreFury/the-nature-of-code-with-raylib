#include <iostream>
#include <Raylib/raylib.h>
#include <Raylib/raymath.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

std::ostream &operator<<(std::ostream &cout, Vector2 vector)
{
    std::cout << vector.x << " " << vector.y << std::endl;
    return cout;
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "This is the window");
    SetTargetFPS(FLAG_VSYNC_HINT);

    float x = 100;
    float y = 100;
    float xSpeed = 1;
    float ySpeed = 4;

    while (!WindowShouldClose())
    {
        x = x + xSpeed;
        y = y + ySpeed;

        if ((x > SCREEN_WIDTH) || (x < 0))
        {
            xSpeed = xSpeed * -1;
        }

        if ((y > SCREEN_HEIGHT) || (y < 0))
        {
            ySpeed = ySpeed * -1;
        }

        BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(RAYWHITE);

        DrawCircle(x, y, 16, BLACK);
        EndDrawing();
    }

    CloseWindow();
}