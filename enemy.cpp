#include "enemy.h"

bool Enemy::operator==(const Enemy& other) const {
    return position.x == other.position.x && position.y == other.position.y && speed == other.speed && health == other.health;
}
