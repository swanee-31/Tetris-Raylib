#pragma once
#include "Grid.h"
#include "memory"

class Game {
public:
    Game();
    ~Game() = default;
    
    void Run() ;
    

private:
    void Init();
    void Draw();
    void Update();
    std::unique_ptr<Grid> grid;
};