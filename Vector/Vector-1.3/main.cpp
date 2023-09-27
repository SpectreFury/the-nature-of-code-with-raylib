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

    Vector2 mouse = {GetMouseX(), GetMouseY()};
    Vector2 center{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

    while (!WindowShouldClose())
    {

        mouse = Vector2{(float)GetMouseX(), (float)GetMouseY()};

        BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(RAYWHITE);

        DrawLineV(mouse, center, BLACK);

        EndDrawing();
    }

    CloseWindow();
}