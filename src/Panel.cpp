#include "Panel.h"
#include "constants.h"
#include "raylib.h"
#include <iostream>

Panel::Panel()
{
    pDelta = ((CELL_SIZE * GRID_COLS) + HALF_CELL);
    scoreRect = {float(pDelta), float(CELL_SIZE * 4), float(pDelta + CELL_SIZE * 4), float(pDelta + CELL_SIZE * 8)};
    #ifndef NDEBUG
    std::cout << DBG_PREFIX << "Panel initialized with pDelta = " << pDelta << std::endl;
    #endif
}

void Panel::Draw()
{
   DrawText("TETRIS", pDelta + HALF_CELL, CELL_SIZE, CELL_SIZE, BLUE);
   DrawText("Score", pDelta + HALF_CELL, CELL_SIZE * 3, CELL_SIZE, BLUE);
   DrawRectangleRounded(scoreRect, 0.1f, 8, BLUE);
 //  DrawRectangleRounded({420, 55, 170,60}, 0.3, 6, BLUE);
}


void Panel::Update()
{
}

