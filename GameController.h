#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameModel.h"
#include "GameView.h"
#include "GameState.h"
#include "raylib.h"

class GameController {
public:
    GameController();
    ~GameController();
    void Update();
    void Draw();
    void ChangeState(GameState newState);
    void HandleInput();
    GameState GetCurrentState() const;

private:
    GameModel model;
    GameView view;
    GameState currentState;
    Texture2D gameOverImage; // Texture for game over image
    Texture2D PauseImage; // Texture for pause image
    Texture2D StartImage; // Texture for start image
    Texture2D PlayImage; // Texture for play image
    Music backgroundMusic;   // Music stream for background music
};

#endif // GAMECONTROLLER_H
