#include "raylib.h"
#include "GameController.h"
#include "Tower.h"
#include "GameView.h"

int main() {
    // Initialize window
    const int screenWidth = 1200;  // 800 * 1.5
    const int screenHeight = 675;  // 450 * 1.5
    InitWindow(screenWidth, screenHeight, "Tower Defense");

    InitAudioDevice(); // Initialize audio device

    // Set target FPS
    SetTargetFPS(60); // Set target frames-per-second (FPS)

    // Initialize game controller
    GameController gameController;

    // Create a Tower instance
    Tower myTower({100, 150}, 50, 100);

    // Initialize game view
    GameView gameView(nullptr); // Assuming GameModel is not yet used

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Handle input
        gameController.HandleInput();

        // Update game state
        gameController.Update();

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE); // Set a neutral background color

        // Draw current state
        gameController.Draw();

        // If in playing state, draw the tower
        if (gameController.GetCurrentState() == GameState::Playing) {
            gameView.DrawTower(myTower);
        }

        EndDrawing();
    }

    CloseAudioDevice(); // Close the audio device
    // De-initialize Raylib
    CloseWindow();

    return 0;
}
