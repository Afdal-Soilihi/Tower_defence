#pragma once

#include "raylib.h"

class Enemy {
private:
    Vector2 position;
    int health;
    float speed;

public:
    Enemy(Vector2 pos, int hp, float spd) : position(pos), health(hp), speed(spd) {}

    void Update();
    void Draw() const; // Mark Draw as const

    // Add a getter for position
    Vector2 GetPosition() const {
        return position;
    }
};