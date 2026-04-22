#pragma once
#include "Grid.h"
#include "memory"
#include "Blocks.h"
#include <random>
#include <vector>
#include "Panel.h"

class Game {
public:
    Game();
    ~Game() = default;
    void Run() ;
    Block GetRandomBlock();
    inline int GetScore() const { return clearedRows; } // Calcule le score en fonction du nombre de lignes effacées
    inline Block GetNextBlock() const { return nextBlock; } // Renvoie le bloc suivant à afficher dans le panneau

 
private:
    bool isPaused; // Indique si le jeu est en pause ou non
    void Init(); // Logique d'initialisation du jeu
    void Draw(); 
    void Update();
    void HandleInput();
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void Rotate();
    bool isBlockOut();
    bool EventTriggered(double interval);
    bool BlockNotColliding(); // Verifie si le bloc actuel ne rentre pas en collision avec les blocs déjà présents dans la grille
    void LockBlock();
    void Reset();

    bool isGameOver; // Indique si le jeu est terminé
    int clearedRows; // Nombre de lignes effacées
    double lastMoveTime; // Temps du dernier mouvement automatique du bloc
    Block currentBlock; // Bloc actuellement en jeu
    Block nextBlock; // Bloc suivant à afficher
    std::vector<Block> GetAllBlocks(); // Renvoie la liste de tous les types de blocs disponibles dans le jeu
    std::unique_ptr<Grid> grid; // Pointeur unique vers la grille de jeu
    std::vector<Block> blocks; // Vecteur pour stocker les blocs restants à générer (pour éviter les répétitions jusqu'à ce que tous les blocs aient été utilisés)
    std::unique_ptr<Panel> panel; // Pointeur unique vers le panneau d'affichage des informations du jeu (score, bloc suivant, etc.)
};