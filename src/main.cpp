#include <raylib.h>
#include <Common/Image.hpp>
#include <Common/Animation.hpp>
#include <filesystem>

int main()
{
    #ifndef NDEBUG
        std::filesystem::current_path(PROJECT_ROOT);
    #endif

    int windowX = 1920;
    int windowY = 1080;
    InitWindow(windowX, windowY, "Raylib test");
    SetTargetFPS(60);
    ToggleFullscreen();

    Common::Animation standing ("assets/animations/standing.gif", 0.05f);
    Common::Animation walking ("assets/animations/walking.gif", 0.05f);
    Common::Animation jumping ("assets/animations/jumping.gif", 0.05f);
    Common::Image background ("assets/images/background.png");

    int x = 0;
    int y = 600;
    const int MOVEMENT = 20;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        background.display(0, 0);

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