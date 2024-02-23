#include "Piece.h"
#include<iostream>

using namespace std;


char ChessPiece::getSymbol() const 
{ 
	return symbol;
}
int ChessPiece::getRow() const
{
	return row; 
}
int ChessPiece::getCol() const
{
	return col; 
}
void ChessPiece::setPosition(int r, int c)
{ 
	row = r; col = c; 
}
bool ChessPiece::hasMoved() const {
	return moved;
}

// Set a piece to have moved
void ChessPiece::setHasMoved(bool hasMoved)
{
	moved = hasMoved;
}