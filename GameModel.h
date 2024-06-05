#pragma once

#include <vector>
#include "Enemy.h"
#include "Tower.h"

class GameModel {
private:
    std::vector<Enemy> enemies;
    std::vector<Tower> towers;
    int score;
    float spawnTimer;
    float timeBetweenSpawns;

public:
    GameModel();
    void Update();
    void HandleInput();
    void Draw();
    std::vector<Enemy>& GetEnemies();
    std::vector<Tower>& GetTowers(); // Add this getter

    void SpawnEnemy();
    // Other necessary methods
};
