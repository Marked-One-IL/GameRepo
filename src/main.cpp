#include <raylib.h>
#include <filesystem>

int main()
{
    #ifndef NDEBUG
        std::filesystem::current_path(PROJECT_ROOT);
    #endif

    InitWindow(1000, 1000, "Raylib test");
    SetTargetFPS(60);

    Image image = LoadImage("assets/pic.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    int x = 0;
    int y = 0;
    const int MOVEMENT = 10;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (IsKeyDown(KEY_ESCAPE)) {
            break;
        }
        if (IsKeyDown(KEY_W)) {
            y -= MOVEMENT;
        }
        if (IsKeyDown(KEY_S)) {
            y += MOVEMENT;
        }
        if (IsKeyDown(KEY_A)) {
            x -= MOVEMENT;
        }
        if (IsKeyDown(KEY_D)) {
            x += MOVEMENT;
        }

        DrawText("I love femboys", 220, 180, 30, DARKBLUE);
        DrawTexture(texture, x, y, WHITE);

        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}