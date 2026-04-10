#include "Grid.h"
#include <iostream>

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = getCellColors();
}

// On initialise la grille en mettant tous les éléments à 0
void Grid::Initialize() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            grid[i][j] = 0;
        }
    }
}

// Affiche la grille dans la console pour vérifier son initialisation
void Grid::Print() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<Color> Grid::getCellColors() {
    // Exemple de couleurs pour les différentes pièces
    // La première (0) étant la couleur du fond (!= BACKGROUND_COLOR)
    return {
        BLACK,GREEN, RED, ORANGE, YELLOW, ORANGE, PURPLE, BLUE   
    };
}

void Grid::Draw() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int cellValue = grid[i][j];
            Color cellColor = colors[cellValue]; // Obtenir la couleur en fonction de la valeur de la cellule
            DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize -1, cellSize -1, cellColor);
        }
    }
}