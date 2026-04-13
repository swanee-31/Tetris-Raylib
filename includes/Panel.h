#pragma once

#include "raylib.h"
#include "constants.h"

class Panel {
public:
    Panel();
    ~Panel() = default;
    void Draw();
    void Update();  

private:
    int pDelta; // Décalage horizontal pour positionner le panneau à droite de la grille
    Rectangle scoreRect;
};