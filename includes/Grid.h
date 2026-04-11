#pragma once
#include <vector>
#include "raylib.h"
#include "constants.h"
#include "Blocks.h"

class Grid {   
public:
    Grid();
    ~Grid() = default;
    void Draw();
    

private:
    void Initialize();
    #ifndef NDEBUG
        void Print();
        void Test();
    #endif
    int grid[GRID_ROWS][GRID_COLS]; // Matrice pour représenter la grille de jeu

    std::vector<Block> blocks; // Vecteur pour stocker les blocs présents dans la grille
};