#pragma once
#include "Grid.h"

class Game {
public:
    Game();
    ~Game() = default;
    
    void Run() ;
    

private:
    void Init();
    void Draw();
    void Update();
    Grid grid; 

    void Tests(); // pour faire des tests de dessins
    
};

