#include "raylib.h"
#include "game.h"
#include "resources.h"
#include <cmath>  // for cosf and sinf
#include <string> // for std::to_string

std::vector<Enemy> enemies;
std::vector<Tower> towers;
std::vector<Ball> balls;
bool shooting = false;
float shootTimer = 0.0f;
float shootInterval = 0.8f; // Interval in seconds between each ball shot
int score = 0;

void InitGame() {
    // Initialize enemies for two waves
    for (int i = 0; i < 30; i++) {
        // First wave from left to right
        Enemy enemy1 = {{-100.0f - i * 50.0f, 200.0f}, 1.0f, 100};
        enemies.push_back(enemy1);

        // Second wave from right to left
        Enemy enemy2 = {{800.0f + i * 50.0f, 250.0f}, -1.0f, 100};
        enemies.push_back(enemy2);
    }
}

void UpdateGame(float deltaTime) {
    // Move enemies
    for (Enemy &enemy : enemies) {
        enemy.position.x += enemy.speed;
    }

    // Move balls
    for (Ball &ball : balls) {
        ball.position.x += ball.direction.x * ball.speed;
        ball.position.y += ball.direction.y * ball.speed;
    }

    // Check for collisions between balls and enemies
    for (auto ballIt = balls.begin(); ballIt != balls.end();) {
        bool ballRemoved = false;
        for (auto enemyIt = enemies.begin(); enemyIt != enemies.end();) {
            if (CheckCollisionCircles(ballIt->position, 5, enemyIt->position, 20)) {
                // Remove the ball and enemy
                enemyIt = enemies.erase(enemyIt);
                ballIt = balls.erase(ballIt);
                ballRemoved = true;
                score += 100; // Increment score by 100
                break;
            } else {
                ++enemyIt;
            }
        }
        if (!ballRemoved) {
            ++ballIt;
        }
    }

    // Tower attack logic
    for (Tower &tower : towers) {
        for (auto it = enemies.begin(); it != enemies.end();) {
            if (CheckCollisionCircles(tower.position, tower.range, it->position, 20)) {
                // Reduce enemy health
                it->health -= tower.damage;
                if (it->health <= 0) {
                    // Remove enemy if health is zero or less
                    it = enemies.erase(it);
                } else {
                    ++it;
                }
            } else {
                ++it;
            }
        }
    }

    // Handle shooting balls
    if (shooting) {
        shootTimer += deltaTime;
        if (shootTimer >= shootInterval) {
            shootTimer = 0.0f;
            Tower &tower = towers[0]; // Assuming there's only one tower
            Vector2 ballPosition = tower.position;

            // Randomly generate direction for each ball
            for (int i = 0; i < 8; i++) { // Adjust the number of balls shot at each interval
                float angle = GetRandomValue(0, 360) * DEG2RAD;
                Vector2 ballDirection = {cosf(angle), sinf(angle)};
                float ballSpeed = 12.0f;
                Ball ball = {ballPosition, ballDirection, ballSpeed};
                balls.push_back(ball);
                PlaySound(shootSound);
            }

            shooting = false; // Reset shooting flag
        }
    }
}

void DrawGame() {
    // Draw background image
    DrawTexture(bgTexture, 0, 0, WHITE);

    // Draw enemies
    for (const Enemy &enemy : enemies) {
        DrawCircleV(enemy.position, 20, RED);
    }

    // Draw towers
    for (const Tower &tower : towers) {
        // Draw tower using texture
        DrawTexture(tower.texture, tower.position.x - tower.texture.width / 2, tower.position.y - tower.texture.height / 2, WHITE);
        DrawCircleLines(tower.position.x, tower.position.y, tower.range, DARKGRAY);
    }

    // Draw balls
    for (const Ball &ball : balls) {
        DrawCircleV(ball.position, 5, GREEN);
    }

    // Draw score
    DrawText(std::to_string(score).c_str(), GetScreenWidth() - MeasureText(std::to_string(score).c_str(), 20) - 10, 10, 20, BLUE);
}








// #include "game.h"
// #include "resources.h"
// #include <cmath>  // for cosf and sinf
// #include <string> // for std::to_string

// std::vector<Enemy> enemies;
// std::vector<Tower> towers;
// std::vector<Ball> balls;
// bool shooting = false;
// float shootTimer = 0.0f;
// float shootInterval = 0.8f; // Interval in seconds between each ball shot
// int score = 0;

// void InitGame() {
//     // Initialize enemies for two waves
//     for (int i = 0; i < 30; i++) {
//         // First wave from left to right
//         Enemy enemy1 = {{-100.0f - i * 50.0f, 200.0f}, 1.0f, 100};
//         enemies.push_back(enemy1);

//         // Second wave from right to left
//         Enemy enemy2 = {{800.0f + i * 50.0f, 250.0f}, -1.0f, 100};
//         enemies.push_back(enemy2);
//     }
// }

// void UpdateGame(float deltaTime) {
//     // Move enemies
//     for (Enemy &enemy : enemies) {
//         enemy.position.x += enemy.speed;
//     }

//     // Move balls
//     for (Ball &ball : balls) {
//         ball.position.x += ball.direction.x * ball.speed;
//         ball.position.y += ball.direction.y * ball.speed;
//     }

//     // Check for collisions between balls and enemies
//     for (auto ballIt = balls.begin(); ballIt != balls.end();) {
//         bool ballRemoved = false;
//         for (auto enemyIt = enemies.begin(); enemyIt != enemies.end();) {
//             if (CheckCollisionCircles(ballIt->position, 5, enemyIt->position, 20)) {
//                 // Remove the ball and enemy
//                 enemyIt = enemies.erase(enemyIt);
//                 ballIt = balls.erase(ballIt);
//                 ballRemoved = true;
//                 score += 100; // Increment score by 100
//                 break;
//             } else {
//                 ++enemyIt;
//             }
//         }
//         if (!ballRemoved) {
//             ++ballIt;
//         }
//     }

//     // Tower attack logic
//     for (Tower &tower : towers) {
//         for (auto it = enemies.begin(); it != enemies.end();) {
//             if (CheckCollisionCircles(tower.position, tower.range, it->position, 20)) {
//                 // Reduce enemy health
//                 it->health -= tower.damage;
//                 if (it->health <= 0) {
//                     // Remove enemy if health is zero or less
//                     it = enemies.erase(it);
//                 } else {
//                     ++it;
//                 }
//             } else {
//                 ++it;
//             }
//         }
//     }

//     // Handle shooting balls
//     if (shooting) {
//         shootTimer += deltaTime;
//         if (shootTimer >= shootInterval) {
//             shootTimer = 0.0f;
//             Tower &tower = towers[0]; // Assuming there's only one tower
//             Vector2 ballPosition = tower.position;

//             // Randomly generate direction for each ball
//             for (int i = 0; i < 8; i++) { // Adjust the number of balls shot at each interval
//                 float angle = GetRandomValue(0, 360) * DEG2RAD;
//                 Vector2 ballDirection = {cosf(angle), sinf(angle)};
//                 float ballSpeed = 12.0f;
//                 Ball ball = {ballPosition, ballDirection, ballSpeed};
//                 balls.push_back(ball);
//                 PlaySound(shootSound);
//             }

//             shooting = false; // Reset shooting flag
//         }
//     }
// }

// void DrawGame() {
//     // Draw background image
//     DrawTexture(bgTexture, 0, 0, WHITE);

//     // Draw enemies
//     for (const Enemy &enemy : enemies) {
//         DrawCircleV(enemy.position, 20, RED);
//     }

//     // Draw towers
//     for (const Tower &tower : towers) {
//         DrawCircleV(tower.position, 30, BLUE);
//         DrawCircleLines(tower.position.x, tower.position.y, tower.range, DARKGRAY);
//     }

//     // Draw balls
//     for (const Ball &ball : balls) {
//         DrawCircleV(ball.position, 5, GREEN);
//     }

//     // Draw score
//     DrawText(std::to_string(score).c_str(), GetScreenWidth() - MeasureText(std::to_string(score).c_str(), 20) - 10, 10, 20, BLUE);
// }
