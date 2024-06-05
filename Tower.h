#pragma once

#include <raylib.h>
#include <vector>
#include "Enemy.h"

class Tower {
private:
    Vector2 position;
    int damage;
    int range;

public:
    // Constructor
    Tower(Vector2 position, int damage, int range);

    // Methods
    void Update(std::vector<Enemy>& enemies);
    void Draw() const;  // Marked as const

    // Getter for position
    Vector2 GetPosition() const;
};