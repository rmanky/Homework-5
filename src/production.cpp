using namespace std;
#include "production.h"

void production(int argc, char** argv)
{
	cout << " --- --- --- --- --- ---" << endl;
	cout << " --- --- --- --- --- ---" << endl;
	cout << " --- --- --- --- --- ---" << endl;
	cout << " --- STARTING GAME ---" << endl;
	Board* board = new Board();
	Piece** pieces = board->generateBoard("checkerBoard.txt");
	char *p;
	int numMoves;
	long conv = strtol(argv[1], &p, 10);
	numMoves = conv;
	if(numMoves > 0) {
		cout << " --- NUMBER OF MOVES IS " << numMoves << " ---" << endl;
		int i = 0;
		while(i < numMoves) {
			i++;
			board->makeMove(i % 2 != 0);
			board->displayBoard();
		}
		cout << "GAME OVER" << endl;
		delete board;
	}
	else {
		cout << " --- GOING UNTIL A TEAM IS ELIMINATED ---" << endl;
		int i = 0;
		while(checkForMissing(pieces)) {
			i++;
			board->makeMove(i % 2 != 0);
			board->displayBoard();
		}
		cout << "GAME OVER" << endl;
		delete board;
	}
}

bool checkForMissing(Piece** board) {
	bool foundX = false;
	bool foundO = false;
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(!board[r][c].getBlank()) {
				if(board[r][c].getRedTeam()) {
					foundO = true;
				}
				else {
					foundX = true;
				}
			}
		}
	}
	return foundX && foundO;
}
