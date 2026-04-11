#include "Blocks.h"

// Définition des différents types de blocs avec leurs positions relatives pour chaque rotation

LBlock::LBlock() {
    id = 1; // ID pour le bloc L
    blockColor = ORANGE; // Couleur du bloc L
    currentRotation = 0; // Rotation initiale
    cells[0] = { Position(0, 2), Position(1, 0), Position(1,1), Position(1,2) }; // Rotation 0
    cells[1] = { Position(0, 1), Position(1,1), Position(2,1), Position(2, 2) }; // Rotation 90
    cells[2] = { Position(1, 0), Position(1,1), Position(1,2), Position(2,0) }; // Rotation 180
    cells[3] = { Position(0, 0), Position(0,1), Position(1,1), Position(2,1) }; // Rotation 270
}

JBlock::JBlock() {
    id = 2; // ID pour le bloc J
    blockColor = BLUE; // Couleur du bloc J
    currentRotation = 0; // Rotation initiale
    cells[0] = { Position(0, 0), Position(1, 0), Position(1,1), Position(1,2) }; // Rotation 0
    cells[1] = { Position(0, 1), Position(0,2), Position(1,1), Position(2,1) }; // Rotation 90
    cells[2] = { Position(1, 0), Position(1,1), Position(1,2), Position(2,2) }; // Rotation 180
    cells[3] = { Position(0, 1), Position(1,1), Position(2,0), Position(2,1) }; // Rotation 270
}

IBlock::IBlock() {
    id = 3; // ID pour le bloc I
    blockColor = GREEN; // Couleur du bloc I
    currentRotation = 0; // Rotation initiale
    cells[0] = { Position(1, 0), Position(1,1), Position(1,2), Position(1,3) }; // Rotation 0
    cells[1] = { Position(0, 2), Position(1,2), Position(2,2), Position(3,2) }; // Rotation 90
    cells[2] = { Position(2, 0), Position(2,1), Position(2,2), Position(2,3) }; // Rotation 180
    cells[3] = { Position(0, 1), Position(1,1), Position(2,1), Position(3,1) }; // Rotation 270
}

OBlock::OBlock() {
    id = 4; // ID pour le bloc O
    blockColor = YELLOW; // Couleur du bloc O
    currentRotation = 0; // Rotation initiale (le bloc O n'a pas de rotation)
    cells[0] = { Position(0, 0), Position(0,1), Position(1,0), Position(1,1) }; // Rotation 0
    cells[1] = cells[0]; // Rotation 90 (identique à la rotation 0)
    cells[2] = cells[0]; // Rotation 180 (identique à la rotation 0)
    cells[3] = cells[0]; // Rotation 270 (identique à la rotation 0)
}

SBlock::SBlock() {
    id = 5; // ID pour le bloc S
    blockColor = RED; // Couleur du bloc S
    currentRotation = 0; // Rotation initiale
    cells[0] = { Position(0, 1), Position(0,2), Position(1,0), Position(1,1) }; // Rotation 0
    cells[1] = { Position(0, 1), Position(1,1), Position(1,2), Position(2,2) }; // Rotation 90
    cells[2] = { Position(1, 1), Position(1,2), Position(2,0), Position(2,1) }; // Rotation 180
    cells[3] = { Position(0, 0), Position(1,0), Position(1,1), Position(2,1) }; // Rotation 270
}

TBlock::TBlock() {
    id = 6; // ID pour le bloc T
    blockColor = PINK; // Couleur du bloc T
    currentRotation = 0; // Rotation initiale
    cells[0] = { Position(0, 1), Position(1,0), Position(1,1), Position(1,2) }; // Rotation 0
    cells[1] = { Position(0, 1), Position(1,1), Position(1,2), Position(2,1) }; // Rotation 90
    cells[2] = { Position(1, 0), Position(1,1), Position(1,2), Position(2,1) }; // Rotation 180
    cells[3] = { Position(0, 1), Position(1,0), Position(1,1), Position(2,1) }; // Rotation 270
}

ZBlock::ZBlock() {
    id = 7; // ID pour le bloc Z
    blockColor = PURPLE; // Couleur du bloc Z
    currentRotation = 0; // Rotation initiale
    cells[0] = { Position(0, 0), Position(0,1), Position(1,1), Position(1,2) }; // Rotation 0
    cells[1] = { Position(0, 2), Position(1,1), Position(1,2), Position(2,1) }; // Rotation 90
    cells[2] = { Position(1, 0), Position(1,1), Position(2,1), Position(2,2) }; // Rotation 180
    cells[3] = { Position(0, 1), Position(1,0), Position(1,1), Position(2,0) }; // Rotation 270
}