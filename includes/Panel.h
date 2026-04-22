#pragma once

#include "raylib.h"
#include "constants.h"
#include <memory>

class Game;

class Panel {
public:
    Panel(Game* game);
    Panel() = delete; // Supprime le constructeur par défaut pour forcer l'utilisation du constructeur avec le paramètre Game
    ~Panel() = default;
    void Draw();

private:
    Game* game; // Pointeur simple vers le jeu pour accéder aux informations du score et du bloc suivant
    int pDelta; // Décalage horizontal pour positionner le panneau à droite de la grille
    Rectangle scoreRect;
    void DisplayNextBlock(); // Fonction pour afficher le bloc suivant dans le panneau
};