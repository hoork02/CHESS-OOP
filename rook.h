#pragma once
#include<iostream>
#include"Piece.h"

using namespace std;

class Rook : public ChessPiece {
public:
    Rook(char s, int r, int c) : ChessPiece(s, r, c) {}
    bool isValidMove(int r, int c) const;
};