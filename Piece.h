#pragma once
#include <iostream>
using namespace std;

class ChessPiece {
protected:
    char symbol; // symbol representing the piece on the board
    int row, col;
    bool isWhite;// current position of the piece on the board
    bool moved;
public:
    ChessPiece(char s, int r, int c) : symbol(s), row(r), col(c) {}
    virtual ~ChessPiece() {} // virtual destructor for polymorphism
    char getSymbol() const;
        int getRow() const;
        int getCol() const;
        void setPosition(int r, int c);
        bool getColor() const {
            return isWhite;
        }
    virtual bool isValidMove(int r, int c) const = 0; // pure virtual function for polymorphism
    bool hasMoved() const;
    void setHasMoved(bool hasMoved);
};

