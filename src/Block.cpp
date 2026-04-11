#include "Block.h"

Block::Block() {
}

void Block::Draw() {
    std::vector<Position> currentCells = cells[currentRotation];
    for (const Position& pos : currentCells) {
        int x = pos.GetCol() * CELL_SIZE;
        int y = pos.GetRow() * CELL_SIZE;
        DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, blockColor);
    }
}