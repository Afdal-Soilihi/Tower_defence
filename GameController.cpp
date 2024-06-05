#include "GameController.h"
#include "raylib.h"

GameController::GameController() : model(), view(&model), currentState(GameState::Menu) {
    // Initialize the game model and view
    gameOverImage = LoadTexture("C:\\Users\\La Plateforme\\Desktop\\TryGameTwoer\\Assets\\Images\\g_over.png"); // Load the game over image
}

GameController::~GameController() {
    UnloadTexture(gameOverImage); // Unload the game over image
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
            DrawText("Menu Screen", 200, 200, 40, RED);
            DrawText("Press ENTER to Start", 200, 250, 20, RED);
            break;
        case GameState::Playing:
            // Draw game playing screen
            ClearBackground(GREEN);
            view.Draw();
            break;
        case GameState::Paused:
            // Draw paused screen
            ClearBackground(GRAY);
            DrawText("Paused", 200, 200, 40, RED);
            DrawText("Press P to Resume", 200, 250, 20, RED);
            break;
        case GameState::GameOver:
            // Draw game over screen
            ClearBackground(RAYWHITE); // Set a neutral background color
            DrawTexture(gameOverImage, 0, 0, WHITE); // Draw the game over image
            DrawText("Game Over", 200, 200, 40, RED);
            DrawText("Press ENTER to Return to Menu", 200, 250, 20, RED);
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
