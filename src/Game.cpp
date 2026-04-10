#include "Game.h"
#include "iostream"
#include "raylib.h"
#include "constants.h"

Game::Game() {
        Init();
}

void Game::Init() {
    // Logique d'initialisation du jeu
    InitWindow( SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(TARGET_FPS);
    std::cout << "Jeu initialisé !" << std::endl;

    grid.Print(); // Affiche la grille dans la console pour vérifier son initialisation
};

void  Game::Update() {
    // Logique de mise à jour du jeu
};

void Game::Tests() {
    // Dessin de primitives pour tests
    DrawText("Hello Ouaurld", 190, 200, 20, LIGHTGRAY);
    DrawCircle(400, 120, 35, LIME);
    DrawRectangle(300, 300, 200, 100, RED);
    DrawLine(10, 10, 790, 440, YELLOW);
};

void Game::Draw() {
    // Logique de dessin du jeu
     
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);    
           // Tests();
        grid.Draw(); // Dessine la grille
            
        EndDrawing();
    
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
    CloseWindow();
}