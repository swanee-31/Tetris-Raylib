#include "raylib.h"
#include "Game.h"
#include <iostream>
#include <memory>


int main() {
    // Initialisation simple
    std::unique_ptr<Game> game = std::make_unique<Game>();

    game->Run();

    return 0;
}