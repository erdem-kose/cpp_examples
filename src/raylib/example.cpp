#include "example.hpp"

void raylib_example()
{
    InitWindow(800, 450, "Love Ranger v0.1");

    while (!WindowShouldClose())
    {
        Texture2D player = LoadTexture("../src/raylib/elflady.png");
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
}

/*
TEST(raylibtest, test1) {
    raylib_example();
    
    EXPECT_EQ(1, 1);
}
*/