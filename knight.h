#pragma once
#include"Piece.h"

class Knight : public ChessPiece {
public:
    Knight(char s, int r, int c) : ChessPiece(s, r, c) {}
    bool isValidMove(int r, int c) const;
};