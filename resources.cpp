#include "raylib.h"
#include "resources.h"

Sound shootSound;
Music backgroundMusic;
Texture2D bgTexture;
Texture2D towerTexture; // Declare tower texture

void LoadResources() {
    InitAudioDevice();  // Initialize audio device
    shootSound = LoadSound("Assets\\Sound\\gun-shot-1-176892.mp3");
    backgroundMusic = LoadMusicStream("Assets/Sound/civil-war-fanfares-15645.mp3");

    // Load background image and convert it to texture
    Image bgImage = LoadImage("Map2.png");
    bgTexture = LoadTextureFromImage(bgImage);
    UnloadImage(bgImage);  // Unload image from RAM, it's now in VRAM

    // Load tower texture
    Image towerImage = LoadImage("RST1.png");  // Load tower image
    towerTexture = LoadTextureFromImage(towerImage); // Convert image to texture
    UnloadImage(towerImage);  // Unload image from RAM, it's now in VRAM
}

void UnloadResources() {
    UnloadTexture(towerTexture);  // Unload tower texture
    UnloadTexture(bgTexture);  // Unload background texture
    UnloadSound(shootSound);  // Unload sound
    UnloadMusicStream(backgroundMusic);  // Unload music stream
    CloseAudioDevice();  // Close audio device
}






// #include "raylib.h"
// #include "resources.h"

// Sound shootSound;
// Music backgroundMusic;
// Texture2D bgTexture;
// Texture2D towerTexture; // Declare tower texture

// void LoadResources() {
//     InitAudioDevice();  // Initialize audio device
//     shootSound = LoadSound("Assets\\Sound\\gun-shot-1-176892.mp3");
//     backgroundMusic = LoadMusicStream("Assets/Sound/civil-war-fanfares-15645.mp3");

//     // Load background image and convert it to texture
//     Image bgImage = LoadImage("Map2.png");
//     bgTexture = LoadTextureFromImage(bgImage);
//     UnloadImage(bgImage);  // Unload image from RAM, it's now in VRAM

//     // Load tower texture
//     Image towerImage = LoadImage("RST1.png");  // Load tower image
//     towerTexture = LoadTextureFromImage(towerImage); // Convert image to texture
//     UnloadImage(towerImage);  // Unload image from RAM, it's now in VRAM
// }

// void UnloadResources() {
//     UnloadTexture(towerTexture);  // Unload tower texture
//     UnloadTexture(bgTexture);  // Unload background texture
//     UnloadSound(shootSound);  // Unload sound
//     UnloadMusicStream(backgroundMusic);  // Unload music stream
//     CloseAudioDevice();  // Close audio device
// }
