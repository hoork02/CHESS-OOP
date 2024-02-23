#include "queen.h"


bool Queen::isValidMove(int r, int c) const {
    // check if move is valid for a Queen piece
    return (r == row || c == col || abs(r - row) == abs(c - col));
}