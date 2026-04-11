#include "Game.h"
#include "iostream"
#include "raylib.h"
#include "constants.h"
#include "Blocks.h"

Game::Game() {
        Init();
        grid = std::make_unique<Grid>();
        if (!grid) {
            std::cerr << "Erreur lors de la création de la grille !" << std::endl;
            exit(EXIT_FAILURE);
        }
}

void Game::Init() {
    // Logique d'initialisation du jeu
    InitWindow( SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(TARGET_FPS);
};

void  Game::Update() {
    // Logique de mise à jour du jeu
};

void Game::Draw() {
    // Logique de dessin du jeu
     
        BeginDrawing();

        ClearBackground(BACKGROUND_COLOR);    
        grid->Draw(); // Dessine la grille
            
        EndDrawing();
    
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
    CloseWindow();
}