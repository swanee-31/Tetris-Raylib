#include "Grid.h"
#include <iostream>
#include "constants.h"

Grid::Grid()
{
    Initialize();
#ifndef NDEBUG
    Test();  // Remplit la grille de valeurs pour les tests
    Print(); // Affiche la grille dans la console pour vérifier son initialisation
    std::cout << "Grille initialisee :" << std::endl;
#endif
}

// On initialise la grille en mettant tous les éléments à 0
void Grid::Initialize()
{
    for (int i = 0; i < GRID_ROWS; i++)
    {
        for (int j = 0; j < GRID_COLS; j++)
        {
            grid[i][j] = 0;
        }
    }
}

#ifndef NDEBUG
// Affiche la grille dans la console pour vérifier son initialisation
void Grid::Print()
{
    for (int i = 0; i < GRID_ROWS; i++)
    {
        for (int j = 0; j < GRID_COLS; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Test()
{
    /*
    // Méthode de test pour vérifier les couleurs
    grid[0][0] = 1; // Vert
    grid[0][1] = 2; // Rouge
    grid[0][2] = 3; // Orange
    grid[2][3] = 4; // Jaune
    grid[5][5] = 5; // Rose
    grid[6][5] = 6; // Violet
    grid[7][5] = 7; // Bleu
    */

    TBlock block; // Création d'un bloc T
    blocks.push_back(block); // Ajout du bloc à la grille pour le dessiner
    
}
#endif

void Grid::Draw()
{
    for (int i = 0; i < GRID_ROWS; i++)
    {
        for (int j = 0; j < GRID_COLS; j++)
        {
            int cellValue = grid[i][j];
            Color cellColor = COLORS[cellValue]; // Obtenir la couleur en fonction de la valeur de la cellule
            DrawRectangle(j * CELL_SIZE + 1, i * CELL_SIZE + 1, CELL_SIZE - 1, CELL_SIZE - 1, cellColor);
            #ifndef NDEBUG
            for(Block block : blocks) {
                block.Draw(); // Dessine les blocs présents dans la grille
            }
            #endif
        }
    }
}