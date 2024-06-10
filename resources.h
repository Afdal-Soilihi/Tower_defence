#ifndef RESOURCES_H
#define RESOURCES_H

#include "raylib.h"

extern Sound shootSound;
extern Music backgroundMusic;
extern Texture2D bgTexture;
extern Texture2D towerTexture; // Declare tower texture

void LoadResources();
void UnloadResources();

#endif // RESOURCES_H
