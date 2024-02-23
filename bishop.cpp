#include"bishop.h"

bool Bishop::isValidMove(int r, int c) const {
    // check if move is valid for a Bishop piece
    return (abs(r - row) == abs(c - col));
}