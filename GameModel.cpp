#include "GameModel.h"

GameModel::GameModel() : score(0), spawnTimer(0.0f), timeBetweenSpawns(2.0f) {
    // Initialize other game model components if needed
}

void GameModel::Update() {
    // Update enemies
    for (auto& enemy : enemies) {
        enemy.Update();
    }

    // Update towers
    for (auto& tower : towers) {
        tower.Update(enemies);
    }

    // Handle enemy spawning
    spawnTimer += GetFrameTime();
    if (spawnTimer >= timeBetweenSpawns) {
        spawnTimer = 0.0f;
        SpawnEnemy();
    }
}

void GameModel::HandleInput() {
    // Handle user input for tower placement or other actions
}

void GameModel::Draw() {
    // Draw game objects
    for (const auto& tower : towers) {
        tower.Draw();
    }
    for (const auto& enemy : enemies) {
        enemy.Draw();
    }
}

std::vector<Enemy>& GameModel::GetEnemies() {
    return enemies;
}

std::vector<Tower>& GameModel::GetTowers() {
    return towers;
}

void GameModel::SpawnEnemy() {
    // Add a new enemy to the list
    enemies.emplace_back(Vector2{0, 0}, 100, 1.0f); // Example position and health
}
