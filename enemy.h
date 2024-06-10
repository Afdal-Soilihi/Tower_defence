#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

struct Enemy {
    Vector2 position;
    float speed;
    int health;

    bool operator==(const Enemy& other) const;
};

#endif // ENEMY_H
