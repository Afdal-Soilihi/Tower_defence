#include "Tower.h"

// Constructor
Tower::Tower(Vector2 pos, int dmg, int rng) : position(pos), damage(dmg), range(rng) {}

// Update method (you'll need to implement the logic)
void Tower::Update(std::vector<Enemy>& enemies) {
    // Implement the logic to update the tower, such as targeting enemies within range
}

// Draw method
void Tower::Draw() const {  // Marked as const
    DrawCircleV(position, 20, DARKGRAY);  // Drawing the tower as a dark gray circle, adjust as needed
}

// Getter for position
Vector2 Tower::GetPosition() const {
    return position;
}