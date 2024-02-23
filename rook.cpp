#include"rook.h"


bool Rook::isValidMove(int r, int c) const {
    // check if move is valid for a Rook piece
    return (r == row || c == col);
}