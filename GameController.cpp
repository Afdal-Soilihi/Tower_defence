#include "GameController.h"
#include "raylib.h"

GameController::GameController() : model(), view(&model), currentState(GameState::Menu) {
    // Initialize the game model and view
    gameOverImage = LoadTexture("C:\\Users\\La Plateforme\\Desktop\\TryGameTwoer\\Assets\\Images\\g_over.png"); // Load the game over image
    PauseImage = LoadTexture("C:\\Users\\La Plateforme\\Desktop\\TryGameTwoer\\Assets\\Images\\pause_image.png");
    StartImage = LoadTexture("C:\\Users\\La Plateforme\\Desktop\\TryGameTwoer\\Assets\\Images\\cover.png");
    PlayImage = LoadTexture("C:\\Users\\La Plateforme\\Desktop\\TryGameTwoer\\Assets\\Images\\Map2.png");
}

GameController::~GameController() {
    UnloadTexture(gameOverImage); // Unload the game over image
    UnloadTexture(PauseImage);
    UnloadTexture(StartImage);
    UnloadTexture(PlayImage);
}

void GameController::Update() {
    switch (currentState) {
        case GameState::Menu:
            // Handle menu update logic
            break;
        case GameState::Playing:
            // Handle game playing update logic
            model.Update();
            break;
        case GameState::Paused:
            // Handle paused update logic
            break;
        case GameState::GameOver:
            // Handle game over update logic
            break;
    }
}

void GameController::Draw() {
    switch (currentState) {
        case GameState::Menu:
            // Draw menu screen
            ClearBackground(BLUE);
            // Draw the Start image 
            DrawTexture(StartImage, (GetScreenWidth() - StartImage.width) / 2, (GetScreenHeight() - StartImage.height) / 2, WHITE);
            DrawText("Menu ", 200, 200, 40, BLACK);
            DrawText("Press ENTER to Start ", 200, 250, 40, BLACK);
            DrawText("lEVEL I", 200, 300, 40, BLACK);
            break;
        case GameState::Playing:
            // Draw game playing screen
            DrawTexture(PlayImage, (GetScreenWidth() - PlayImage.width) / 2, (GetScreenHeight() - PlayImage.height) / 2, WHITE);
            ClearBackground(GREEN);
            view.Draw();
            break;
        case GameState::Paused:
            // Draw paused screen
            ClearBackground(GRAY);
            // Draw the pause image at the center of the screen
            DrawTexture(PauseImage, (GetScreenWidth() - PauseImage.width) / 2, (GetScreenHeight() - PauseImage.height) / 2, WHITE);
            // Draw text to the right of the image
            DrawText("BREAK - Press P to Resume", 100, 200, 40, GREEN);
            break;
        case GameState::GameOver:
            // Draw game over screen
            ClearBackground(RAYWHITE); // Set a neutral background color
            DrawTexture(gameOverImage, 0, 0, WHITE); // Draw the game over image
            DrawText("Game Over", 500, 200, 40, RED);
            DrawText("Score", 500, 250, 40, RED);
            DrawText("Press ENTER to Return to Menu", 500, 300, 40, RED);
            break;
    }
}

void GameController::ChangeState(GameState newState) {
    currentState = newState;
}

void GameController::HandleInput() {
    switch (currentState) {
        case GameState::Menu:
            if (IsKeyPressed(KEY_ENTER)) {
                ChangeState(GameState::Playing);
            }
            break;
        case GameState::Playing:
            if (IsKeyPressed(KEY_P)) {
                ChangeState(GameState::Paused);
            } else if (IsKeyPressed(KEY_ESCAPE)) {
                ChangeState(GameState::GameOver);
            } else if (IsKeyPressed(KEY_G)) {
                ChangeState(GameState::GameOver); // Handle the G key to trigger GameOver
            }
            break;
        case GameState::Paused:
            if (IsKeyPressed(KEY_P)) {
                ChangeState(GameState::Playing);
            }
            break;
        case GameState::GameOver:
            if (IsKeyPressed(KEY_ENTER)) {
                ChangeState(GameState::Menu);
            }
            break;
    }
}

GameState GameController::GetCurrentState() const {
    return currentState;
}
