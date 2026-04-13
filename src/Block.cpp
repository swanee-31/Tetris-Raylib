#include "Block.h"

Block::Block() {
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw() {
    std::vector<Position> currentCells = GetCurrentCells();
    for (const Position& pos : currentCells) {
        int x = pos.GetCol() * CELL_SIZE;
        int y = pos.GetRow() * CELL_SIZE;
        DrawRectangle(x + 1 + HALF_CELL, y + 1 + HALF_CELL, CELL_SIZE, CELL_SIZE, blockColor);
    }
}

void Block::Move(int dRow, int dCol) {
    rowOffset += dRow;
    colOffset += dCol;
}

void Block::Rotate()
{
    currentRotation = (currentRotation + 1) % 4; // Passe à la rotation suivante (0, 1, 2, 3)
}

std::vector<Position> Block::GetCurrentCells() const {
    std::vector<Position> currentCells = cells.at(currentRotation);
    std::vector<Position> absoluteCells;
    for (const Position& pos : currentCells) {
        int absoluteRow = pos.GetRow() + rowOffset;
        int absoluteCol = pos.GetCol() + colOffset;
        absoluteCells.emplace_back(absoluteRow, absoluteCol);
    }
    return absoluteCells;
}
