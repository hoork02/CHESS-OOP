#pragma once
#include"Piece.h"

#include<iostream>
using namespace std;

class Bishop : public ChessPiece {
public:
    Bishop(char s, int r, int c) : ChessPiece(s, r, c) {}
    bool isValidMove(int r, int c) const;
};