#include "GameView.h"
#include "raylib.h"

GameView::GameView(GameModel* modelPtr) : model(modelPtr) {}

void GameView::Draw() {
    // Draw the game elements based on the model
    for (const auto& tower : model->GetTowers()) {
        DrawTower(tower);
    }
    DrawEnemies();
}

void GameView::DrawTower(const Tower& tower) {
    tower.Draw();
}

void GameView::DrawEnemies() {
    for (const auto& enemy : model->GetEnemies()) {
        DrawCircleV(enemy.GetPosition(), 10, RED); // Example drawing logic
    }
}
