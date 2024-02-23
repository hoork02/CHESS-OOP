#include"chessboard.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stack>
#include<string>
#include<vector>
#include"Header.h"
using namespace std;

#define GREEN "\033[32m";
#define RESET "\033[0m";
#define	WHITE 15
#define BLACK 0




ChessBoard::ChessBoard() {
	// initialize board with Chess pieces
	board[0][0] = new Rook('r', 0, 0);
	board[0][1] = new Knight('n', 0, 1);
	board[0][2] = new Bishop('b', 0, 2);
	board[0][3] = new Queen('q', 0, 3);
	board[0][4] = new King('k', 0, 4);
	board[0][5] = new Bishop('b', 0, 5);
	board[0][6] = new Knight('n', 0, 6);
	board[0][7] = new Rook('r', 0, 7);
	for (int i = 0; i < 8; i++) {
		board[1][i] = new Pawn('p', 1, i);
		board[6][i] = new Pawn('P', 6, i);
	
	}
	board[7][0] = new Rook('R', 7, 0);
	board[7][1] = new Knight('N', 7, 1);
	board[7][2] = new Bishop('B', 7, 2);
	board[7][3] = new Queen('Q', 7, 3);
	board[7][4] = new King('K', 7, 4);
	board[7][5] = new Bishop('B', 7, 5);
	board[7][6] = new Knight('N', 7, 6);
	board[7][7] = new Rook('R', 7, 7);
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = nullptr;
		}
	}
}
void ChessBoard::drawPawn(int row, int col, int color) {
	// Set the background color based on the square's color
	int bgColor = ((row + col) % 2 == 0) ? 48 : 52; // black or dark gray
	SetClr(15, bgColor); // Set text color to white

	// Draw the top of the pawn
	gotoRowCol(row, col + 1);
	cout << "___";

	// Draw the middle of the pawn
	gotoRowCol(row + 1, col + 1);
	cout << "/___\\";

	// Draw the bottom of the pawn
	gotoRowCol(row + 2, col + 1);
	cout << "\\___/";

	// Set the text color to the appropriate color (white or black)
	int textColor = (color == WHITE) ? 15 : 3;
	SetClr(textColor, bgColor);

	// Draw the pawn's head
	gotoRowCol(row + 1, col + 2);
	cout << "<>";
}

void ChessBoard::selectposition2(position& p, int dim)
{
	int r, c;
	getRowColbyLeftClick(r, c);
	
	p.ri = r / 10;
	p.ci = c / 10 - 1 ;
}
void ChessBoard::hori(int sc, int ec, char sym)
{
	for (int i = sc; i <= ec; i++)
	{
		cout << sym;
	}
}
void ChessBoard::vert(int r, int c, int sr, int er, char sym)
{
	for (int i = sr; i <= er; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		cout << endl;
		r++;
	}
}
void ChessBoard::displayBoard()
{

	for (int r = 0, i = 0; r < 8; r++, i += 10)
	{

		for (int c = 0, j = 10; c < 8; c++, j += 10)
		{


			if (board[r][c] == nullptr)
			{
				gotoRowCol(i + 5, j + 5);
				cout << "-";
			}
			else
			{
				gotoRowCol(i + 5, j + 5);
				cout<<board[r][c]->getSymbol();
			}
		}
		cout << endl;
	}
}
void ChessBoard::drawdisplay()
{
	SetClr(15, 0);
	gotoRowCol(0, 10);
	hori(5, 85, -37);
	gotoRowCol(80, 10);
	hori(5, 85, -37);
	gotoRowCol(10, 10);
	hori(5, 85, -37);
	gotoRowCol(20, 10);
	hori(5, 85, -37);
	gotoRowCol(30, 10);
	hori(5, 85, -37);
	gotoRowCol(40, 10);
	hori(5, 85, -37);
	gotoRowCol(50, 10);
	hori(5, 85, -37);
	gotoRowCol(60, 10);
	hori(5, 85, -37);
	gotoRowCol(70, 10);
	hori(5, 85, -37);
	vert(0, 10, 0, 80, -37);
	vert(0, 90, 0, 80, -37);
	vert(0, 20, 0, 80, -37);
	vert(0, 30, 0, 80, -37);
	vert(0, 40, 0, 80, -37);
	vert(0, 50, 0, 80, -37);
	vert(0, 60, 0, 80, -37);
	vert(0, 70, 0, 80, -37);
	vert(0, 80, 0, 80, -37);
	SetClr(15, 0);
}

void ChessBoard::printBoard() const
{
	SetClr(15, 0); // set text color to white and background to black

	// Print the column headers
	cout << "    a  b  c  d  e  f  g  h" << endl;

	// Print each row of the board
	for (int r = 0; r < 8; r++) {
		// Print the row number on the left-hand side
		cout << " " << 8 - r << " ";

		for (int c = 0; c < 8; c++) {
			// Determine the background color for the current square
			int bgColor = ((r + c) % 2 == 0) ? 48 : 52; // black or dark gray

			// Get the ChessPiece object at the current square
			ChessPiece* piece = board[r][c];

			// Determine the text color and symbol for the current piece
			int textColor = (piece && piece->getColor() == WHITE) ? 15 : 3; // white or black
			char symbol = (piece) ? piece->getSymbol() : ' ';

			// Print the square with the appropriate colors and symbol
			SetClr(textColor, bgColor);
			cout << " " << symbol << " ";
		}

		// Print the row number on the right-hand side
		SetClr(15, 0); // set text color back to white
		cout << " " << 8 - r << endl;
	}

	// Print the column headers again at the bottom
	cout << "    a  b  c  d  e  f  g  h" << endl;

}





bool ChessBoard::movePiece(int r1, int c1, int r2, int c2) 
{
	if (!isInBounds(r1, c1) || !isInBounds(r2, c2)) {
		std::cout << "Invalid move. Try again." << std::endl;
		return false;
	}

	// Check if there is a piece at the starting position
	ChessPiece* piece = board[r1][c1];
	if (piece == nullptr) {
		std::cout << "Invalid move. Try again." << std::endl;
		return false;
	}

	// Check if the piece can legally move to the ending position
	if (!isLegalMove(r1, c1, r2, c2)) {
		std::cout << "Invalid move. Try again." << std::endl;
		return false;
	}

	// Move the piece to the new position
	makeMove(r1, c1, r2, c2, piece);

	// Check for pawn promotion
	if (isPawnPromotion(r1, c1, r2, c2)) {
		promotePawn(r2, c2);
	}

	// Check for castling
	if (isKingSideCastling(r1, c1, r2, c2)) {
		castleKingside(piece->getColor());
	}
	else if (isQueenSideCastling(r1, c1, r2, c2, piece->getColor())) {
		castleQueenside(piece->getColor());
	}

	// Check for checkmate or stalemate
	if (isCheckmate(piece->getColor())) {
		std::cout << "Checkmate! " << (piece->getColor() ? "Black" : "White") << " wins." << std::endl;
		return true;
	}
	else if (isStalemate(piece->getColor())) {
		std::cout << "Stalemate!" << std::endl;
		return true;
	}

	// Switch turns
	isWhite = !isWhite;

	return true;
	
}
bool ChessBoard::isInCheck(char color) const {
	// check if the King of the given color is in check
	int kr=0, kc=0; // position of the King
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != nullptr && board[i][j]->getColor() == color
				&& board[i][j]->getSymbol() == 'K') {
				kr = i;
				kc = j;
			}
		}
	}
	// check if any opponent's Chess piece can capture the King
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != nullptr && board[i][j]->getColor() != color
				&& board[i][j]->isValidMove(kr, kc)) {
				return true;
			}
		}
	}
	return false;

}

bool ChessBoard::isCheckmate(char color) 
{   
	ChessPiece* piece;
	if (!isInCheck(color)) {
		return false;
	}
	// Check if any of the player's pieces can make a legal move
	for (int r1 = 0; r1 < 8; r1++) {
		for (int c1 = 0; c1 < 8; c1++) {
			if (board[r1][c1] != nullptr && board[r1][c1]->getColor() == color) {
				for (int r2 = 0; r2 < 8; r2++) {
					for (int c2 = 0; c2 < 8; c2++) {
						if (movePiece(r1, c1, r2, c2)) {
							undoMove(r1, c1, r2, c2, piece);
							return false;
						}
					}
				}
			}
		}
	}
	// If no legal move can be made, it is checkmate
	return true;

}




bool ChessBoard::isStalemate(char color) 
{
	
	ChessPiece* piece=0;
	if (isInCheck(color)) {
		return false;
	}
	// Check if any of the player's pieces can make a legal move
	for (int r1 = 0; r1 < 8; r1++) {
		for (int c1 = 0; c1 < 8; c1++) {
			if (board[r1][c1] != nullptr && board[r1][c1]->getColor() == color) {
				for (int r2 = 0; r2 < 8; r2++) {
					for (int c2 = 0; c2 < 8; c2++) {
						if (movePiece(r1, c1, r2, c2)) {
							undoMove(r1, c1, r2, c2, piece);
							return false;
						}
					}
				}
			}
		}
	}
	// If no legal move can be made, it is stalemate
	return true;
	
}
void ChessBoard::highlightLegalMoves(ChessPiece* piece, bool board[8][8])
{
	vector<position>legalMoves;
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (board[r][c]) {
				legalMoves.push_back({ r, c });
			}
		}
	}

	// Highlight the legal moves on the console
	for (position p : legalMoves) {
		int r = p.ri;
		int c = p.ci;
		gotoRowCol(r, c * 3 + 1);
		if (piece->getColor()) {
			SetClr(0, 14); // white piece, blue highlight
		}
		else {
			SetClr(0, 12); // black piece, red highlight
		}
		cout << "   ";
	}
	gotoRowCol(8, 0); // move cursor out of the way
	SetClr(15, 0); // reset c
}
ChessPiece* ChessBoard::getPieceAt(int r, int c) {
	// Check if the given row and column are within the bounds of the board
	if (r < 0 || r > 7 || c < 0 || c > 7) {
		return nullptr; // Return nullptr if the coordinates are invalid
	}

	// Get the piece object at the specified location on the board
	ChessPiece* piece = board[r][c];

	return piece;
}

bool ChessBoard::selfCheck(bool isWhiteTurn) const
{
	// Find the current player's king
	ChessPiece* king = nullptr;
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			ChessPiece* piece = board[row][col];
			if (piece && piece->getColor() == isWhiteTurn && piece->getSymbol() == 'K') {
				king = piece;
				break;
			}
		}
		if (king) break;
	}

	// Check if any of the opponent's pieces can attack the king
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			ChessPiece* piece = board[row][col];
			if (piece && piece->getColor() != isWhiteTurn && piece->isValidMove(king->getRow(), king->getCol())) {
				return true; // King is in check
			}
		}
	}

	return false; // King is not in check
}
void ChessBoard::makeMove(int fromRow, int fromCol, int toRow, int toCol, ChessPiece*& piece) {
	// create a new move and add it to the stack
	board[toRow][toCol] = board[fromRow][fromCol];
	board[fromRow][fromCol] = nullptr;

	piece->setPosition(toRow, toCol);
}
void ChessBoard::undo() {
	// check if there are any moves to undo
	if (moveStack.empty()) {
		return;
	}

	// pop the last move off the stack
	Move move = moveStack.top();
	moveStack.pop();

	// undo the move
	undoMove(move.toRow, move.toCol, move.fromRow, move.fromCol, move.piece);
}

// redo the last move that was undone
void ChessBoard::redo() {
	// check if there are any moves to redo
	if (redoStack.empty()) {
		return;
	}

	// pop the last move off the redo stack
	Move move = redoStack.top();
	redoStack.pop();

	// redo the move
	redoMove(move.fromRow, move.fromCol, move.toRow, move.toCol, move.piece);
}
void ChessBoard::redoMove(int r1, int c1, int r2, int c2, ChessPiece*& piece) {
	// move the piece to the new location
	board[r2][c2] = piece;
	board[r1][c1] = nullptr;
	piece->setPosition(r2, c2);
}

void ChessBoard::undoMove(int r1, int c1, int r2, int c2, ChessPiece* &piece) {
	board[r1][c1] = piece;
	board[r2][c2] = nullptr;
	piece->setPosition(r1, c1);
}
void ChessBoard::saveGame(string filename)
{
	ofstream fout(filename);

	if (!fout) {
		cerr << "Error: could not open file " << filename << " for writing." << endl;
		return;
	}

	// Write the board state to the file
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			ChessPiece* piece = board[row][col];
			if (piece != nullptr) {
				fout << piece->getSymbol() << " " << row << " " << col << endl;
			}
		}
	}

	// Write the current turn to the file
	fout << (isWhite ? "white" : "black") << endl;

	fout.close();

	cout << "Game saved to " << filename << endl;
}
void ChessBoard::loadGame(string fileName)
{
	ifstream infile(fileName);
	if (infile.is_open()) {
		// Reset the chess board
		//resetBoard();

		// Load the player turn
		string turn;
		getline(infile, turn);
		isWhite = (turn == "white");

		// Load the chess board configuration
		for (int row = 0; row < 8; row++) {
			string line;
			getline(infile, line);
			for (int col = 0; col < 8; col++) {
				char symbol = line[col];
				if (symbol != '-') {
					bool isWhite = (symbol >= 'A' && symbol <= 'Z');
					switch (symbol) {
					case 'P':
						board[row][col] = new Pawn(isWhite, row, col);
						break;
					case 'R':
						board[row][col] = new Rook(isWhite, row, col);
						break;
					case 'N':
						board[row][col] = new Knight(isWhite, row, col);
						break;
					case 'B':
						board[row][col] = new Bishop(isWhite, row, col);
						break;
					case 'Q':
						board[row][col] = new Queen(isWhite, row, col);
						break;
					case 'K':
						board[row][col] = new King(isWhite, row, col);
						break;
					default:
						break;
					}
				}
			}
		}
		infile.close();
	}
	else {
		cout << "Unable to open file for loading." << endl;
	}
}
bool ChessBoard::isLegalMove(int r1, int c1, int r2, int c2)
{
	ChessPiece* piece = board[r1][c1];

	// Check if there is a piece at the starting position
	if (!piece) {
		return false;
	}

	// Check if the destination is out of bounds
	if (!isInBounds(r2, c2)) {
		return false;
	}

	// Check if the piece is moving to its current position
	if (r1 == r2 && c1 == c2) {
		return false;
	}

	// Check if the piece is moving to a square occupied by a piece of the same color
	if (board[r2][c2] && board[r2][c2]->getColor() == piece->getColor()) {
		return false;
	}

	// Check if the move is valid for the piece's specific movement pattern
	if (!piece->isValidMove(r2, c2)) {
		return false;
	}

	// Check if the path is clear for pieces that require a clear path
	if (!isPathClear(r1, c1, r2, c2)) {
		return false;
	}

	// Check if the move would result in the moving player being in check
	ChessPiece* capturedPiece = board[r2][c2];
	board[r2][c2] = piece;
	board[r1][c1] = nullptr;
	piece->setPosition(r2, c2);
	bool inCheck = isInCheck(piece->getColor());
	board[r1][c1] = piece;
	board[r2][c2] = capturedPiece;
	piece->setPosition(r1, c1);

	if (inCheck) {
		return false;
	}

	return true;
}
bool ChessBoard::isInBounds(int r, int c) {
	return (r >= 0 && r < 8 && c >= 0 && c < 8);
}

bool ChessBoard::isPathClear(int r1, int c1, int r2, int c2) {
	int rowDiff = r2 - r1;
	int colDiff = c2 - c1;

	if (rowDiff == 0) { // horizontal move
		int step = colDiff > 0 ? 1 : -1;
		for (int c = c1 + step; c != c2; c += step) {
			if (board[r1][c] != nullptr) {
				return false;
			}
		}
	}
	else if (colDiff == 0) { // vertical move
		int step = rowDiff > 0 ? 1 : -1;
		for (int r = r1 + step; r != r2; r += step) {
			if (board[r][c1] != nullptr) {
				return false;
			}
		}
	}
	else if (abs(rowDiff) == abs(colDiff)) { // diagonal move
		int rowStep = rowDiff > 0 ? 1 : -1;
		int colStep = colDiff > 0 ? 1 : -1;
		int r = r1 + rowStep;
		int c = c1 + colStep;
		while (r != r2 && c != c2) {
			if (board[r][c] != nullptr) {
				return false;
			}
			r += rowStep;
			c += colStep;
		}
	}

	return true;
}

bool ChessBoard::isVerticalMove(int r1, int c1, int r2, int c2) {
	int rowDiff = r2 - r1;
	int colDiff = c2 - c1;

	return (colDiff == 0 && abs(rowDiff) > 0);
}

bool ChessBoard::isHorizontalMove(int r1, int c1, int r2, int c2) {
	// Check if the move is horizontal
	return r1 == r2 && c1 != c2;
}

bool ChessBoard::isDiagonalMove(int r1, int c1, int r2, int c2) {
	// Check if the move is diagonal
	int rowDistance = abs(r2 - r1);
	int colDistance = abs(c2 - c1);
	return rowDistance == colDistance;
}

bool ChessBoard::isLShapedMove(int r1, int c1, int r2, int c2) {
	// Check if the move is L-shaped
	int rowDistance = abs(r2 - r1);
	int colDistance = abs(c2 - c1);
	return (rowDistance == 2 && colDistance == 1) || (rowDistance == 1 && colDistance == 2);
}

void ChessBoard::castleKingside(bool color) {
	if (color) { // White kingside castling
		ChessPiece* rook = board[7][7];
		board[7][5] = rook;
		board[7][7] = nullptr;
		rook->setPosition(7, 5);
		whiteCanCastleKingside = false;
		whiteCanCastleQueenside = false;
	}
	else { // Black kingside castling
		ChessPiece* rook = board[0][7];
		board[0][5] = rook;
		board[0][7] = nullptr;
		rook->setPosition(0, 5);
		blackCanCastleKingside = false;
		blackCanCastleQueenside = false;
	}
}
bool ChessBoard::isKingSideCastling(int r1, int c1, int r2, int c2) {
	// Check if the move is castling kingside
	if (board[r1][c1]->getSymbol() != 'K' || r1 != r2 || abs(c2 - c1) != 2) {
		return false;
	}

	// Check if the king has moved before
	if (board[r1][c1]->getColor() == true) {
		if (whiteCanCastleKingside == false) {
			return false;
		}
	}
	else {
		if (blackCanCastleKingside == false) {
			return false;
		}
	}

	// Check if the squares between the king and rook are clear
	int c_min = min(c1, c2);
	int c_max = max(c1, c2);
	for (int i = c_min + 1; i < c_max; i++) {
		if (board[r1][i] != nullptr) {
			return false;
		}
	}

	// Check if the king is in check or will move through check
	bool color = board[r1][c1]->getColor();
	int r = board[r1][c1]->getRow();
	int c = board[r1][c1]->getCol();
	board[r][c] = nullptr;
	board[r1][c1] = nullptr;
	board[r1][c2] = new King('K', r1, c2);
	bool check = isInCheck(color);
	board[r][c] = new King('K', r, c);
	board[r1][c1] = board[r1][c2] = nullptr;
	if (check) {
		return false;
	}

	return true;
}
// Check if a square is attacked by the opponent's pieces
bool ChessBoard::isSquareAttacked(int r, int c, bool color) {
	// Check all opponent pieces
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ChessPiece* piece = board[i][j];
			if (piece != nullptr && piece->getColor() != color) {
				if (piece->isValidMove(r, c)) {
					return true;
				}
			}
		}
	}
	return false;
}

// Check if a piece has moved before


bool ChessBoard::isQueenSideCastling(int r1, int c1, int r2, int c2,bool color) {
	// check if the piece is a king and it hasn't moved
	if (board[r1][c1] == nullptr || board[r1][c1]->getSymbol() != 'K' || board[r1][c1]->hasMoved()) {
		return false;
	}
	// check if the piece being captured is a rook and it hasn't moved
	if (board[r2][c2] == nullptr || board[r2][c2]->getSymbol() != 'R' || board[r2][c2]->hasMoved()) {
		return false;
	}
	// check if the king is not in check and will not move through or into check
	if (isInCheck(board[r1][c1]->getColor()) || !isPathClear(r1, c1, r2, c2)) {
		return false;
	}
	// check if there are no pieces between the king and the rook
	if (!isPathClear(r2, c2, r1, 3)) {
		return false;
	}
	// check if the squares the king will move through or end up on are not attacked by opponent's pieces
	if (isSquareAttacked(r1, c1,color) || isSquareAttacked(r1, 3,color) || isSquareAttacked(r1, 2,color)) {
		return false;
	}
	return true;
}
bool ChessBoard::isPawnPromotion(int r1, int c1, int r2, int c2)
{
	// Check if the piece being moved is a pawn
	ChessPiece* piece = board[r1][c1];
	if (piece == nullptr || piece->getSymbol() != 'P') {
		return false;
	}

	// Check if the pawn is moving to the opposite end of the board
	bool isWhite = piece->getColor();
	if ((isWhite && r2 != 0) || (!isWhite && r2 != 7)) {
		return false;
	}

	return true;
}
void ChessBoard::castleQueenside(bool color) {
	int row = color ? 0 : 7;
	int rookCol = 0;
	int kingCol = 4;

	// Check if castling is allowed
	if (color == true) {
		if (whiteCanCastleQueenside == false) {
			std::cout << "White cannot castle queenside!" << std::endl;
			return;
		}
	}
	else {
		if (blackCanCastleQueenside == false) {
			std::cout << "Black cannot castle queenside!" << std::endl;
			return;
		}
	}

	// Check if path is clear
	if (board[row][1] != nullptr || board[row][2] != nullptr || board[row][3] != nullptr) {
		std::cout << "Cannot castle queenside - path is not clear!" << std::endl;
		return;
	}

	// Move king and rook
	board[row][kingCol - 2] = board[row][kingCol];
	board[row][kingCol] = nullptr;
	board[row][rookCol + 3] = board[row][rookCol];
	board[row][rookCol] = nullptr;

	// Update king's position and hasMoved flag
	board[row][kingCol - 2]->setPosition(row, kingCol - 2);
	board[row][kingCol - 2]->setHasMoved(true);

	// Update rook's position and hasMoved flag
	board[row][rookCol + 3]->setPosition(row, rookCol + 3);
	board[row][rookCol + 3]->setHasMoved(true);

	// Update castling flags
	if (color == true) {
		whiteCanCastleKingside = false;
		whiteCanCastleQueenside = false;
	}
	else {
		blackCanCastleKingside = false;
		blackCanCastleQueenside = false;
	}

	// Print success message
	std::cout << "Castled queenside!" << std::endl;
}

void ChessBoard::promotePawn(int r2, int c2) {
	ChessPiece* piece = board[r2][c2];
	if (piece != nullptr && piece->getSymbol() == 'P' && ((r2 == 0 && piece->getColor() == true) || (r2 == 7 && piece->getColor() == false))) {
		char choice;
		std::cout << "Choose promotion (Q, R, B, N): ";
		std::cin >> choice;
		while (choice != 'Q' && choice != 'R' && choice != 'B' && choice != 'N') {
			std::cout << "Invalid choice. Choose promotion (Q, R, B, N): ";
			std::cin >> choice;
		}
		ChessPiece* newPiece;
		switch (choice) {
		case 'Q':
			newPiece = new Queen(piece->getColor(), r2, c2);
			break;
		case 'R':
			newPiece = new Rook(piece->getColor(), r2, c2);
			break;
		case 'B':
			newPiece = new Bishop(piece->getColor(), r2, c2);
			break;
		case 'N':
			newPiece = new Knight(piece->getColor(), r2, c2);
			break;
		}
//		board[r2][c2] = newPiece;
		delete piece;
	}
}
