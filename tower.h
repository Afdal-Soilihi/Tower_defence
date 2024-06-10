#ifndef TOWER_H
#define TOWER_H

#include "raylib.h"

struct Tower {
    Vector2 position;
    int range;
    int damage;
    Texture2D texture; // Add texture member

    Tower(Vector2 pos, int r, int d, Texture2D tex) : position(pos), range(r), damage(d), texture(tex) {} // Constructor
};

#endif // TOWER_H
