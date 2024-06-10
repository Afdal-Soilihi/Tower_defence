#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include <vector>
#include "enemy.h"
#include "tower.h"
#include "ball.h"

extern std::vector<Enemy> enemies;
extern std::vector<Tower> towers;
extern std::vector<Ball> balls;
extern bool shooting;
extern float shootTimer;
extern float shootInterval;
extern int score;

void InitGame();
void UpdateGame(float deltaTime);
void DrawGame();

#endif // GAME_H
