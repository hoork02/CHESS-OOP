#include"Piece.h"
#include"king.h"

bool King::isValidMove(int r, int c) const 
{
    // check if move is valid for a King piece
    return abs(r - row) <= 1 && abs(c - col) <= 1;
}