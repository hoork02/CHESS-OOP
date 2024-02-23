#pragma once
#include"Piece.h"
#include<iostream>
using namespace std;

class King : public ChessPiece {
public:
    King(char s, int r, int c) : ChessPiece(s, r, c) {}
    bool isValidMove(int r, int c) const;
};