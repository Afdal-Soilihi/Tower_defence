#ifndef BALL_H
#define BALL_H

#include "raylib.h"

struct Ball {
    Vector2 position;
    Vector2 direction;
    float speed;
};

#endif // BALL_H
