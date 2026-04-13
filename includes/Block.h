#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include "constants.h"
#include "raylib.h"

class Block {   

public:
    Block();
    ~Block() = default;
    
    inline int GetId() const { return id; }
    void Draw();

    void Move(int dRow, int dCol);
    void Rotate();

    std::vector<Position> GetCurrentCells() const;

protected:
    int id; 
    std::map<int, std::vector<Position>> cells; // Map pour stocker les 4 positions relatives
    int currentRotation; // Pour suivre la rotation actuelle du bloc
    Color blockColor; // Couleur du bloc
    int rowOffset; // Décalage de ligne pour positionner le bloc dans la grille
    int colOffset; // Décalage de colonne pour positionner le bloc dans la grille
};