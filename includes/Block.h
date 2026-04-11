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
    

protected:
    int id; 
    std::map<int, std::vector<Position>> cells; // Map pour stocker les 4 positions relatives
    int currentRotation; // Pour suivre la rotation actuelle du bloc
    Color blockColor; // Couleur du bloc
};