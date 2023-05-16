#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <math.h>
#include <raylib.h>

#include "entity.h"
#include "tile.h"
#include "physics.h"
#include "camera.h"

int main(void)
{
    // Settings
    //---------------------------------------------------------------------------------------
    // video
    unsigned int screenWidth = 1280;
    unsigned int screenHeight = 720;
    uint8_t targetFPS = 0;
    // bool vsync = 0;
    bool showColliders = true;

    // game
    int worldSeed = 9999;
    uint16_t horizontalWorldSize = 512;
    uint16_t verticalWorldSize = 512;
    //---------------------------------------------------------------------------------------

    // Setup window
    //---------------------------------------------------------------------------------------
    //SetConfigFlags(FLAG_FULLSCREEN_MODE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "IAM");
    SetTargetFPS(targetFPS);
    //--------------------------------------------------------------------------------------

    // Textures
    //---------------------------------------------------------------------------------------
    Image tileset = LoadImage(TextFormat("%s../assets/tileset.png", GetApplicationDirectory()));

    Texture2D dirt = LoadTextureFromImage(ImageFromImage(tileset, (Rectangle){8, 8, 8, 8}));
    //---------------------------------------------------------------------------------------

    // Entity Types
    //---------------------------------------------------------------------------------------
    EntityType Player = {
        0,
        "Player",
        0.0f,
        0.0f,
        (Texture2D){0},
        (Vector2){8, 16}};
    //---------------------------------------------------------------------------------------

    // Tile Types
    //---------------------------------------------------------------------------------------
    CreateTileType("Blank", (Texture2D){0}, 0, 0, 0, 0);
    CreateTileType("Ground", (Texture2D){0}, Solid, UINT16_MAX, 0.3f, 10.0f);

    //---------------------------------------------------------------------------------------

    // Setup game
    //--------------------------------------------------------------------------------------
    // player
    EntityInstance player = {0};
    Camera2D camera = {0};
    player.type = Player;
    player.lvl = 1;
    player.position.y = 0;
    player.position.x = 256 * TILE_SIZE;
    camera.target = player.position;
    camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    camera.zoom = 3.0f;
    Rectangle camBounds = GetCameraBounds(camera, screenWidth, screenHeight, 0);

    // worldd
    GenerateWorld(worldSeed, horizontalWorldSize, verticalWorldSize);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        // player
        player.acceleration.x = 0.0f;
        player.acceleration.y = GRAVITY;
        if (IsKeyDown(KEY_D))
        {
            player.acceleration.x = 250.0f;
        }
        if (IsKeyDown(KEY_A))
        {
            player.acceleration.x = -250.0f;
        }
        if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D))
        {
            player.acceleration.x = 0.0f;
        }
        if (IsKeyDown(KEY_W) && player.verticallyAdjacentTile != NULL)
        {
            player.velocity.y -= 250.0f;
        }
        if (IsKeyDown(KEY_S) && player.verticallyAdjacentTile == NULL)
        {
            player.velocity.y += 1000.0f * deltaTime;
        }
        UpdateEntity(&player, deltaTime);

        // world

        // camera
        camera.target = (Vector2){
            player.position.x + player.type.size.x / 2.0f,
            player.position.y + player.type.size.y / 2.0f};
        camBounds = GetCameraBounds(camera, screenWidth, screenHeight, 0);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(camera);

        DrawTiles(showColliders, camBounds);
        DrawEntity(player, showColliders);

        EndMode2D();
        DrawFPS(0, 0);
        DrawText(TextFormat("Tile Count: %i", tileCount), 0, 22, 20, LIME);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}