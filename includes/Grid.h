#pragma once
#include <vector>
#include "raylib.h"

class Grid {   
public:
    Grid();
    ~Grid() = default;
    void Draw();
    void Print();


private:
    void Initialize();
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors; // Couleurs pour les différentes pièces 
    std::vector<Color> getCellColors(); // Méthode pour obtenir les couleurs des cellules
    int grid[20][10]; // Matrice de 20x10 pour représenter la grille de jeu
};