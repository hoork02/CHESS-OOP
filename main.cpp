#include"chessboard.h"
#include<iostream>
#include<conio.h>
#include"Header.h"
#include<windows.h>
using namespace std;





string rowColToSquare(int row, int col) {
    char file = col + 'a';
    char rank = '8' - row;
    string square = "";
    square += file;
    square += rank;
    return square;
}

int main() {
    ChessBoard board;
    board.drawdisplay();
    board.displayBoard();
    char op;
    char player = 'W';
    bool checkmate = false;
    bool stalemate = false;
    position sc, dc;
    //int r1, c1, r2, c2;
    while (!checkmate && !stalemate) {
        // Get starting position by left mouse click
        cout << "It's " << player << "'s turn. Click the piece you want to move." << endl;
        board.selectposition2(sc, 8);

        ChessPiece* piece = board.getPieceAt(sc.ri, sc.ci);
        if (piece != nullptr && piece->getColor() == player) {
            bool legalMoves[8][8] = {};
            board.highlightLegalMoves(piece, legalMoves);
            cout << "Legal moves:" << endl;
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    if (legalMoves[row][col]) {
                        string square = rowColToSquare(row, col);
                        cout << square << " ";
                    }
                }
            }
            cout << endl;

            // Get ending position by left mouse click
            cout << "Click the square you want to move the piece to." << endl;
            board.selectposition2(dc, 8);

            if (legalMoves[dc.ri][dc.ci]) {
                if (board.movePiece(sc.ri, sc.ci, dc.ri, dc.ci)) {
                    if (board.isInCheck(player)) {
                        cout << "Check!" << endl;
                    }

                    if (board.isCheckmate(player)) {
                        cout << "Checkmate!" << endl;
                        checkmate = true;
                    }
                    else if (board.isStalemate(player)) {
                        cout << "Stalemate!" << endl;
                        stalemate = true;
                    }
                    else {
                        player = (player == 'W' ? 'B' : 'W');
                    }
                }
                else {
                    cout << "Invalid move. Try again." << endl;
                }
            }
            else {
                cout << "Invalid square. Try again." << endl;
            }
        }
        else {
            cout << "Invalid piece. Try again." << endl;
        }
       
        board.drawdisplay();
    }
    return _getch();
}
/*int main()
{
	void chess::play()
	{

		while (true)
		{
			system("cls");
			B->drawdisplay();
			B->displayBoard();
			gotoRowCol(0, 100);
			do {
				DisplayTurnMsg(Ps[Turn]);
				do
				{
					do
					{
						gotoRowCol(1, 100);
						cout << " select Piece(ri,ci):  ";
						selectPiece1();
					} while (!validSourceSelect(Ps[Turn], sri, sci));
					cout << endl;
					gotoRowCol(2, 100);
					cout << "select destination(ri,ci):  ";
					selectDestination1();
				} while (!validDsceSelect(Ps[Turn], dri, dci));
			} while (!B->islegalmove(sri, sci, Turn));

			B->move(sri, sci, dri, dci);

			turnChange();



		}





	}
}*/



