#include"Pawn.h"

bool Pawn::isValidMove(int r, int c) const {
    // check if move is valid for a Pawn piece
    int dr = r - row;
    int dc = c - col;
    if (dr == 0) {
        // moving forward
        if (dc == 1 || dc == -1) {
            // diagonal move (capture)
            return true;
        }
        else if (dc == 2 && isFirstMove) {
            // two squares forward on first move
            return true;
        }
    }
    else if (dr == 1 && (dc == 1 || dc == -1)) {
        // moving diagonally (capture)
        return true;
    }
    return false;
}
