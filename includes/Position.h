#pragma once

class Position {
public: 
    Position(int row, int col);
    ~Position() = default;
    inline int GetRow() const { return row; };
    inline int GetCol() const { return col; };

private:
    int row;
    int col;
};