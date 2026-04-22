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
    int grid[GRID_ROWS][GRID_COLS]; // Matrice pour représenter la grille de jeu
    bool IsCellOut(int row, int col);
    bool IsCellEmpty(int row, int col); // Vérifie si une cellule est vide (valeur 0) ou occupée (valeur > 0)
    int ClearFullRows(); // Vérifie les lignes complètes, les efface et fait descendre les lignes au-dessus

private:
    void Initialize();
    bool IsRowFull(int row); // Vérifie si une ligne est complète (toutes les cellules sont occupées)
    void ClearRow(int row); // Efface une ligne complète
    void MoveRowsDown(int startRow, int numRows); // Fait descendre les lignes au-dessus de la ligne effacée
    #ifndef NDEBUG
        void Print();
        void Test();
    #endif
    std::vector<Block> blocks; // Vecteur pour stocker les blocs présents dans la grille
};