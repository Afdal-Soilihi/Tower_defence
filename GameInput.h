#pragma once

#include "GameModel.h"

class GameInput {
private:
    GameModel* model;
public:
    GameInput(); // Constructor declaration without arguments
    GameInput(GameModel* modelPtr); // Constructor declaration with argument
};
