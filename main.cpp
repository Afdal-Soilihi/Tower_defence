#include "raylib.h"
#include "game.h"
#include "resources.h"
#include <ctime>
#include <cstdlib> // for srand

int main() {
    // Initialization
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Tower Defense Game");

    LoadResources();

    SetTargetFPS(60);

    // Seed random number generator
    srand(static_cast<unsigned>(time(NULL)));

    // Place a tower at the beginning
    bool placingTowers = true;

    while (!WindowShouldClose()) {
        // Update
        float deltaTime = GetFrameTime();
        if (placingTowers) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePosition = GetMousePosition();
                if (towers.size() < 1) { // Change to 1 tower
                    Tower tower(mousePosition, 100, 10, towerTexture); // Using tower texture here
                    towers.push_back(tower);

                    // Start playing background music
                    PlayMusicStream(backgroundMusic);
                }
                if (towers.size() == 1) { // Change to check 1 tower
                    InitGame();
                    placingTowers = false;
                }
            }
        } else {
            UpdateGame(deltaTime);
            UpdateMusicStream(backgroundMusic); // Update the music stream buffer with new audio data
            if (IsKeyPressed(KEY_H)) { // Check if H key is pressed
                shooting = true; // Set shooting flag to true
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGame();
        EndDrawing();
    }

    // De-Initialization
    UnloadResources();
    CloseWindow();  // Close window

    return 0;
}
