#include <iostream>
#include <Raylib/raylib.h>
#include <Raylib/raymath.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

std::ostream& operator<< (std::ostream& cout, Vector2 vector) {
    std::cout << vector.x << " " << vector.y << std::endl;
    return cout;
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "This is the window");
    SetTargetFPS(FLAG_VSYNC_HINT);

    Vector2 location{100, 100};
    Vector2 velocity{1, 4};

    while (!WindowShouldClose())
    {
        location = Vector2Add(location, velocity);

        if ((location.x > SCREEN_WIDTH) || (location.x < 0))
        {
            velocity.x = velocity.x * -1;
        }

        if ((location.y > SCREEN_HEIGHT) || (location.y < 0))
        {
            velocity.y = velocity.y * -1;
        }

        BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(RAYWHITE);

        DrawCircle(location.x, location.y, 16, BLACK);
        EndDrawing();
    }

    CloseWindow();
}