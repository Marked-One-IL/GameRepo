#include <raylib.h>
#include <Common/Png.hpp>
#include <Common/Gif.hpp>
#include <filesystem>

int main()
{
    #ifndef NDEBUG
        std::filesystem::current_path(PROJECT_ROOT);
    #endif

    InitWindow(500, 500, "Raylib test");
    SetTargetFPS(60);

    Common::Gif standing ("assets/standing.gif", 0.05f);
    Common::Gif walking ("assets/walking.gif", 0.05f);
    Common::Gif jumping ("assets/jumping.gif", 0.05f);

    int x = 0;
    int y = 20;
    const int MOVEMENT = 10;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (IsKeyDown(KEY_ESCAPE)) {
            break;
        }

        bool walked = false;
        bool jumped = false;
        if (IsKeyDown(KEY_A)) {
            x -= MOVEMENT;
            walked = true;
        }
        if (IsKeyDown(KEY_D)) {
            x += MOVEMENT;
            walked = true;
        }
        if (IsKeyDown(KEY_W)) {
            jumped = true;
        }

        if (!walked && !jumped) {
            standing.display(x, y);
            standing.advance();
            walking.reset();
            jumping.reset();
        }
        else if (jumped) {
            jumping.display(x, y);
            jumping.advance();
            standing.reset();
            walking.reset();
        }
        else {
            walking.display(x, y);
            walking.advance();
            standing.reset();
            jumping.reset();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}