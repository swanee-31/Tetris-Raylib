#include "Grid.h"
#include <iostream>
#include "constants.h"

Grid::Grid()
{
    /**
     * @brief Fonction Initialize.
     *
     */
    Initialize();
#ifndef NDEBUG
 //   Print(); // Affiche la grille dans la console pour vérifier son initialisation
    std::cout << DBG_PREFIX << "Grille initialisee :" << std::endl;
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

bool Grid::IsRowFull(int row)
{
    for (int col = 0; col < GRID_COLS; col++) {
        if (grid[row][col] == 0) {
            return false; // La ligne n'est pas complète si une cellule est vide
        }
    }
    return true; // La ligne est complète si toutes les cellules sont occupées
}

void Grid::ClearRow(int row)
{
    for (int col = 0; col < GRID_COLS; col++) {
        grid[row][col] = 0; // Efface la ligne en mettant toutes les cellules à 0
    }
}

void Grid::MoveRowsDown(int row, int numRows)
{
    for ( int col = 0; col < GRID_COLS; col++ )
    {
        grid[row + numRows][col] = grid[row][col]; // Déplace la ligne vers le bas
        grid[row][col] = 0; // Efface la ligne d'origine
    }   
}

#ifndef NDEBUG
// Affiche la grille dans la console pour vérifier son initialisation
void Grid::Print()
{
    for (int i = 0; i < GRID_ROWS; i++)
    {
        std::cout << DBG_PREFIX << " ";
        for (int j = 0; j < GRID_COLS; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
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
            DrawRectangle(j * CELL_SIZE + HALF_CELL + 1, i * CELL_SIZE + HALF_CELL + 1, CELL_SIZE - 1, CELL_SIZE - 1, cellColor);
        }
    }
}

bool Grid::IsCellOut(int row, int col) {
    // On check si la cellule est en dehors des limites de la grille
    return row < 0 || row >= GRID_ROWS || col < 0 || col >= GRID_COLS;
}

bool Grid::IsCellEmpty(int row, int col) {
        // Vérifie si une cellule est vide (valeur 0)
        return grid[row][col] == 0;
    }

int Grid::ClearFullRows()
{
    int completed = 0; // Compteur de lignes complètes
    for (int row = GRID_ROWS - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row); // Efface la ligne complète
            completed++; // Incrémente le compteur de lignes complètes
        }
        else if (completed > 0)
        {
            MoveRowsDown(row, completed); // Fait descendre la ligne du nombre de lignes complétées en dessous
        }
    }

    return completed;
}
