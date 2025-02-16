#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "Love Ranger v0.1");

    while (!WindowShouldClose())
    {
        Texture2D player = LoadTexture("../src/elflady.png");
        Color transparent = {255,255,255,255};

        BeginDrawing();
            ClearBackground(BLACK);
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            
            DrawTextureEx(player, 
                          { 0,0 }, 
                          0.0f,
                          0.5f,
                          transparent);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}