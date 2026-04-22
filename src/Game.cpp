#include "Game.h"
#include "iostream"
#include "raylib.h"
#include "constants.h"
#include "Blocks.h"

Game::Game()
{
    /**
     * @brief Fonction Init.
     *
     */
    Init();
    grid = std::make_unique<Grid>();
    panel = std::make_unique<Panel>(this);
    
    if (!grid)
    {
        std::cerr << "Erreur lors de la création de la grille !" << std::endl;
        exit(EXIT_FAILURE);
    }
    blocks = GetAllBlocks();         // Récupère tous les types de blocs disponibles
    currentBlock = GetRandomBlock(); // Sélectionne un bloc aléatoire pour commencer le jeu
    nextBlock = GetRandomBlock();    // Sélectionne un bloc aléatoire pour le bloc suivant
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()}; // Initialisation des blocs disponibles
}

void Game::Init()
{
    // Logique d'initialisation du jeu
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    /**
     * @brief Fonction SetTargetFPS.
     *
     */
    SetTargetFPS(TARGET_FPS);
    isPaused = false;
    clearedRows = 0;
    isGameOver = false;
};

void Game::Update()
{
    // Logique de mise à jour du jeu
    if (isPaused)
    {
        return; // Ne met pas à jour le jeu si il est en pause
    }
};

void Game::Draw()
{
    // Logique de dessin du jeu
    BeginDrawing();
    ClearBackground(BACKGROUND_COLOR);
    grid->Draw();        // Dessine la grille
    currentBlock.Draw(); // Dessine le bloc actuel
    panel->Draw();
    EndDrawing();
}

void Game::Run()
{
    while (!WindowShouldClose())
    {
    
        HandleInput();
     
        Update();
        if (EventTriggered(MOVE_INTERVAL) && !isPaused)
        {
            MoveDown(); // Déplace le bloc vers le bas à intervalles réguliers
        }
    
        Draw();
    }
 
    CloseWindow();
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks(); // Recharger les blocs disponibles si la liste est vide
    }
    int randomIndex = rand() % blocks.size();   // Génère un index aléatoire pour sélectionner un bloc
    Block randomBlock = blocks[randomIndex];    // Récupère le bloc correspondant à l'index aléatoire
    blocks.erase(blocks.begin() + randomIndex); // Retire le bloc sélectionné de la liste des blocs disponibles
    return randomBlock;                         // Retourne le bloc sélectionné
}

void Game::HandleInput()
{
    // Logique de gestion des entrées utilisateur
    int keyPressed = GetKeyPressed();
    if (isGameOver && keyPressed != 0) Reset();

    switch (keyPressed)
    {
    case KEY_LEFT:
   
        MoveLeft();
        break;
    case KEY_RIGHT:
    
        MoveRight();
        break;
    case KEY_DOWN:
   
        MoveDown();
        break;
    case KEY_UP:
   
        Rotate();
        break;
    case KEY_SPACE:
        isPaused = !isPaused;
        break;
    default:
        break;
    }
}

void Game::Reset() {
    #ifndef NDEBUG
    std::cout << DBG_PREFIX << "Resetting game..." << std::endl;
    #endif
    isGameOver = false;
    clearedRows = 0;
    grid.reset(); // Libère la mémoire de la grille actuelle
    grid = std::make_unique<Grid>(); // Réinitialise la grille
    currentBlock = GetRandomBlock(); // Sélectionne un bloc aléatoire pour commencer le jeu
    nextBlock = GetRandomBlock();    // Sélectionne un bloc aléatoire pour le bloc suivant
};

void Game::MoveLeft()
{
    if (!isGameOver)
    {
        currentBlock.Move(0, -1); // Déplace le bloc vers la gauche
        if (isBlockOut() || !BlockNotColliding())
        {
            currentBlock.Move(0, 1); // Si le bloc est en dehors de la grille ou entre en collision, on le remet à sa position précédente
        }
    }
}

void Game::MoveRight()
{
    if (!isGameOver)
    {
        currentBlock.Move(0, 1); // Déplace le bloc vers la droite
        if (isBlockOut() || !BlockNotColliding())
        {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveDown()
{
    if (!isGameOver)
    {
        currentBlock.Move(1, 0); // Déplace le bloc vers le bas
        if (isBlockOut() || !BlockNotColliding())
        {
            currentBlock.Move(-1, 0);
            LockBlock(); // Verrouille le bloc actuel dans la grille et génère un nouveau bloc
        }
    }
}

void Game::Rotate()
{
    if (!isGameOver)
    {
        currentBlock.Rotate(); // Effectue une rotation du bloc
        if (isBlockOut() || !BlockNotColliding())
        {
            // Si le bloc est en dehors de la grille ou entre en collision après la rotation, on annule la rotation
            for (int i = 0; i < 3; i++)
            { // Effectue 3 rotations pour revenir à la position initiale
                currentBlock.Rotate();
            }
        }
    }
}

bool Game::isBlockOut()
{
    std::vector<Position> currentCells = currentBlock.GetCurrentCells();
    for (const Position &pos : currentCells)
    {
        if (grid->IsCellOut(pos.GetRow(), pos.GetCol()))
        {
            return true; // Le bloc est en dehors de la grille
        }
    }
    return false; // Le bloc est à l'intérieur de la grille
}

bool Game::EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastMoveTime >= interval)
    {
        lastMoveTime = currentTime;
        return true; // L'événement est déclenché
    }
    return false;
}

bool Game::BlockNotColliding()
{
    std::vector<Position> currentCells = currentBlock.GetCurrentCells();
    for (const Position &pos : currentCells)
    {
        if (!grid->IsCellEmpty(pos.GetRow(), pos.GetCol()))
        {
            return false; // Le bloc entre en collision avec un bloc déjà présent dans la grille
        }
    }
    return true; // Le bloc ne rentre pas en collision avec les blocs déjà présents dans la grille
}

void Game::LockBlock()
{
    // Logique pour verrouiller le bloc actuel dans la grille et générer un nouveau bloc
    std::vector<Position> currentCells = currentBlock.GetCurrentCells();
    for (Position pos : currentCells)
    {
        // Marque les cellules occupées par le bloc dans la grille
        // TODO : ajouter une vérification pour s'assurer que les positions sont valides avant de les marquer
        grid->grid[pos.GetRow()][pos.GetCol()] = currentBlock.GetId(); // Marque la cellule avec l'ID du bloc pour la couleur
    }
    currentBlock = nextBlock; // Le bloc suivant devient le bloc actuel
    if (isBlockOut() || !BlockNotColliding())
    {
        isGameOver = true; // Si le nouveau bloc est en dehors de la grille ou entre en collision dès sa génération, le jeu est terminé
        #ifndef NDEBUG
        std::cout << DBG_PREFIX <<  "Game Over! Total cleared rows: " << clearedRows << std::endl;
        #endif
    }
    nextBlock = GetRandomBlock();         // Génère un nouveau bloc aléatoire pour le bloc suivant
    clearedRows += grid->ClearFullRows(); // Vérifie et efface les lignes complètes après avoir verrouillé le bloc
}
