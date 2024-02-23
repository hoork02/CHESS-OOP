#pragma once
#include"Piece.h"

class Queen : public ChessPiece {
public:
    Queen(char s, int r, int c) : ChessPiece(s, r, c) {}
    bool isValidMove(int r, int c) const;

};

