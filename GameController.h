#pragma once

#include "GameModel.h"
#include "GameView.h"
#include "GameState.h"

class GameController {
private:
    GameModel model;
    GameView view;
    GameState currentState;
    Texture2D gameOverImage; // Include the game over image

public:
    GameController();
    ~GameController(); // Destructor to unload the texture
    void Update();
    void Draw();
    void ChangeState(GameState newState);
    void HandleInput();
    GameState GetCurrentState() const;
};
