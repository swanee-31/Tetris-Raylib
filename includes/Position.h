#pragma once

class Position {
public: 
    Position(int row, int col) : row(row), col(col) {};
    
    inline int getRow() const { return row; };
    inline int getCol() const { return col; };

private:
    int row;
    int col;
};