#pragma once
#include"Piece.h"
#include"bishop.h"
#include"rook.h"
#include"king.h"
#include"queen.h"
#include"Pawn.h"
#include"knight.h"

#include<stack>

// define a struct to hold the details of a move
struct Move {
	int fromRow, fromCol;
	int toRow, toCol;
	ChessPiece* piece;
};
struct position
{
	int ri, ci;
};
class ChessBoard {
private:
	ChessPiece* board[8][8]; // 2D array of pointers to ChessPiece objects
	int sri, sci, dri, dci;
	stack<Move>undoStack;
	stack<Move> redoStack;
	stack<Move>moveStack;
	bool isWhite;
	bool whiteCanCastleKingside;
	bool whiteCanCastleQueenside;
	bool blackCanCastleKingside;
	bool blackCanCastleQueenside;
public:
	ChessBoard();
	ChessPiece* getPieceAt(int r, int c);
	void printBoard() const;
	bool movePiece(int r1, int c1, int r2, int c2);
	bool isInCheck(char color) const;
	bool isStalemate(char color);
	bool isCheckmate(char color);
	void undoMove(int r1, int c1, int r2, int c2, ChessPiece* &piece);
	void highlightLegalMoves(ChessPiece* piece, bool board[8][8]);
	bool selfCheck(bool isWhiteTurn) const;
	void makeMove(int fromRow, int fromCol, int toRow, int toCol, ChessPiece*& piece);
	void undo();
	void redo();
	void selectposition2(position& p, int dim);
	void redoMove(int r1, int c1, int r2, int c2, ChessPiece*& piece);
	void saveGame(string filename);
	void loadGame(string fileName);
	bool isLegalMove(int r1, int c1, int r2, int c2);
	bool isInBounds(int r, int c);
	bool isPathClear(int r1, int c1, int r2, int c2);
	bool isVerticalMove(int r1, int c1, int r2, int c2);
	
	bool isHorizontalMove(int r1, int c1, int r2, int c2);
	bool isDiagonalMove(int r1, int c1, int r2, int c2);
	bool isLShapedMove(int r1, int c1, int r2, int c2);

	bool isKingSideCastling(int r1, int c1, int r2, int c2);
	bool isQueenSideCastling(int r1, int c1, int r2, int c2, bool color);
	bool isPawnPromotion(int r1, int c1, int r2, int c2);

	void castleKingside(bool color);

	void castleQueenside(bool color);
	void promotePawn(int r2, int c2);
	bool isSquareAttacked(int r, int c, bool color);
	
	void drawPawn(int row, int col, int color);
	void hori(int sc, int ec, char sym);
	void vert(int r, int c, int sr, int er, char sym);
	void displayBoard();
	void drawdisplay();


};