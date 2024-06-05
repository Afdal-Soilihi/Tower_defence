#include "GameInput.h"

GameInput::GameInput() {
    // Initialize GameModel pointer to nullptr or any default value
    model = nullptr; // Example: Initializing model to nullptr
}

GameInput::GameInput(GameModel* modelPtr) {
    model = modelPtr;
    // Add any other initialization logic here
}
