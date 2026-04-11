#include "Position.h "
#include "constants.h"
#include <stdexcept>

Position::Position(int row, int col) : row(row), col(col) {
    // Constructeur pour initialiser la position avec les coordonnées de ligne et de colonne

    if (row < 0 || row >= GRID_ROWS || col < 0 || col >= GRID_COLS) {
        throw std::out_of_range("Position en dehors de la grille !");
    }   
}

