#pragma once
#include"Piece.h"


class Pawn : public ChessPiece {

     // flag to track if pawn is making its first move
public:
    bool isFirstMove;
    Pawn(char s, int r, int c) : ChessPiece(s, r, c), isFirstMove(true) {}
    bool isValidMove(int r, int c) const; 


};