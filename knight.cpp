#include"knight.h"

bool Knight::isValidMove(int r, int c) const {
    // check if move is valid for a Knight piece
    return ((abs(r - row) == 2 && abs(c - col) == 1) ||
        (abs(r - row) == 1 && abs(c - col) == 2));
}