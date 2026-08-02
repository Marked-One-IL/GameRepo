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
    Common::Animation jumping ("assets/animations/jumping.gif", 0.2f);
    Common::Animation crouch ("assets/animations/crouch.gif", 0.05f);
    Common::Image background ("assets/images/background.png");

    int x = 0;
    int y = 800;

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
        bool crouched = false;
        int movement = 20;
        if (IsKeyDown(KEY_S)) {
            crouched = true;
            movement = 10;
        }
        if (IsKeyDown(KEY_A)) {
            x -= movement;
            walked = true;
        }
        if (IsKeyDown(KEY_D)) {
            x += movement;
            walked = true;
        }
        if (IsKeyDown(KEY_W)) {
            jumped = true;
        }
    
        if (!walked && !jumped && !crouched) {
            standing.display(x, y);
            standing.advance();
            walking.reset();
            jumping.reset();
            crouch.reset();
        }
        else if (jumped) {
            jumping.display(x, y);
            jumping.advance();
            standing.reset();
            walking.reset();
            crouch.reset();
        }
        else if (crouched && !walked) {
            crouch.reset();
            crouch.display(x, y);
            standing.reset();
            jumping.reset();
            walking.reset();
        }
        else if (crouched) {
            crouch.display(x, y);
            crouch.advance();
            standing.reset();
            jumping.reset();
            walking.reset();
        }
        else  {
            walking.display(x, y);
            walking.advance();
            standing.reset();
            jumping.reset();
            crouch.reset();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}