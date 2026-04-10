#pragma once
#include <vector>
#include <map>

class Block {   

public:
    Block();
    ~Block() = default;
    
    inline int GetId() const { return id; }
    

private:
    int id; 
    
};