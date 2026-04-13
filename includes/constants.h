#pragma once
#include "raylib.h"

// --- Constantes globales pour le jeu ---
// TODO : utiliser une classe de configuration (singleton) pour regrouper ces constantes et faciliter leur gestion, 
// ou les rendre modifiables via une interface utilisateur pour plus de flexibilité
// TODO : déplacer ces constantes dans un fichier de configuration externe (ex: config.json) 
// pour permettre une personnalisation facile sans recompilation, 
// et implémenter un système de chargement de configuration au démarrage du jeu


static const int CELL_SIZE = 40; // Taille d'une cellule de la grille en pixels
static const int HALF_CELL = CELL_SIZE / 2; // Moitié de la taille d'une cellule, utilisée pour le positionnement des éléments dans la grille
static const int GRID_ROWS = 20;
static const int GRID_COLS = 10;
static const int SCREEN_WIDTH = GRID_COLS * CELL_SIZE + ( CELL_SIZE * 6 ); // Largeur de l'écran (grille + espace pour afficher le bloc suivant et les informations du jeu)
static const int SCREEN_HEIGHT = GRID_ROWS * CELL_SIZE + CELL_SIZE; // Hauteur de l'écran (grille + espace pour afficher les informations du jeu)
static const char* GAME_TITLE = "Tetris by F. Meynckens";
static const int TARGET_FPS = 60;
static const Color BACKGROUND_COLOR = GRAY;
static double MOVE_INTERVAL = 0.02; // Intervalle de temps (en secondes) entre les mouvements automatiques du bloc vers le bas
static const char* BLOCK_NAMES[] = { "LBlock", "JBlock", "IBlock", "OBlock", "SBlock", "TBlock", "ZBlock" }; // Noms des différents types de blocs pour l'affichage dans le panneau d'information
#ifndef NDEBUG
    static const char* DBG_PREFIX = "  --DEBUG: "; // Préfixe pour les messages de debug dans la console
#endif
static const Color COLORS[] = {
    BLACK, GREEN, RED, ORANGE, YELLOW, PINK, PURPLE, BLUE
};