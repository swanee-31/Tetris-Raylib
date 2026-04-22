#include "Panel.h"
#include "Game.h"
#include "constants.h"
#include "raylib.h"
#include <blocks.h>
#include <iostream>
#include <string>

/***********************
 * @brief Constructeur de la classe Panel.
 * * Initialise le panneau d'information en prenant un pointeur vers le jeu pour accéder aux informations
 * du score et du bloc suivant. Calcule également le décalage horizontal pour positionner le panneau à droite de la grille,
 * et définit la zone rectangulaire pour afficher le score.
 * @param game Pointeur vers le jeu pour accéder aux informations du score et du bloc suivant
 */
Panel::Panel(Game* game) : game(game)
{
    pDelta = ((CELL_SIZE * GRID_COLS) + HALF_CELL);
    scoreRect = {float(pDelta + HALF_CELL), float(CELL_SIZE * 4), float(CELL_SIZE * 4), float(CELL_SIZE * 2)};
    #ifndef NDEBUG
    std::cout << DBG_PREFIX << "Panel initialized with pDelta = " << pDelta << std::endl;
    #endif
}

/****************
 * @brief Fonction Panel::Draw.
 * * Dessine le panneau d'information à droite de la grille, affichant le titre du jeu, 
 * le score actuel et un rectangle pour encadrer le score et le block suivant
 */
void Panel::Draw()
{
  
   DrawText("TETRIS", pDelta + HALF_CELL, CELL_SIZE, CELL_SIZE, BLUE);
  
   DrawText("Score", pDelta + HALF_CELL, CELL_SIZE * 3, CELL_SIZE, BLUE);
  
   DrawRectangleRounded(scoreRect, 0.1f, 8, BLUE); // Dessine un rectangle arrondi pour afficher le score, avec une arrondie de 10% et 8 segments pour les coins arrondis
   DrawText(std::to_string(game->GetScore()).c_str(), pDelta + (2 * HALF_CELL), CELL_SIZE * 4 + HALF_CELL, CELL_SIZE, LIGHTGRAY);
 //  DrawRectangleRounded({420, 55, 170,60}, 0.3, 6, BLUE);
}

/*******************
 * @brief Fonction Panel::DisplayNextBlock.
 * * Affiche le bloc suivant dans le panneau d'information à droite de la grille.
 */

void Panel::DisplayNextBlock() 
{
    Block nextBlock = game->GetNextBlock();
    std::vector<Position> cells = nextBlock.GetCurrentCells();
        
}
