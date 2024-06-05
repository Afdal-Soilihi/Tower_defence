#pragma once

#include "GameModel.h"
#include "Tower.h"

class GameView {
private:
    GameModel* model;

public:
    GameView(GameModel* model);
    void Draw();
    void DrawTower(const Tower& tower);
    void DrawEnemies();
};