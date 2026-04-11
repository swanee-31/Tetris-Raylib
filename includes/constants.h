#pragma once
#include "raylib.h"

// --- Constantes globales pour le jeu ---
// TODO : utiliser une classe de configuration (singleton) pour regrouper ces constantes et faciliter leur gestion, 
// ou les rendre modifiables via une interface utilisateur pour plus de flexibilité
// TODO : déplacer ces constantes dans un fichier de configuration externe (ex: config.json) 
// pour permettre une personnalisation facile sans recompilation, 
// et implémenter un système de chargement de configuration au démarrage du jeu

static const int SCREEN_WIDTH = 300;
static const int SCREEN_HEIGHT = 600;
static const int CELL_SIZE = 30;
static const int GRID_ROWS = 20;
static const int GRID_COLS = 10;
static const char* GAME_TITLE = "Tetris by F. Meynckens";
static const int TARGET_FPS = 60;
static const Color BACKGROUND_COLOR = GRAY;

static const Color COLORS[] = {
    BLACK, GREEN, RED, ORANGE, YELLOW, PINK, PURPLE, BLUE
};