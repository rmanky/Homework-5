using namespace std;
#include "production.h"

void production(int argc, char** argv)
{
	cout << " --- --- --- --- --- ---" << endl;
	cout << " --- --- --- --- --- ---" << endl;
	cout << " --- --- --- --- --- ---" << endl;
	cout << " --- STARTING GAME UNTIL NO-ONE REMAINS ---" << endl;
	Board* board = new Board();
	Piece** pieces = board->generateBoard("checkerBoard.txt");
	int i = 0;
	while(checkForMissing(pieces)) {
		i++;
		board->makeMove(i % 2 == 0);
		for(int r = 0; r < 8; r++) {
			for(int c = 0; c < 8; c++) {
				if(pieces[r][c].getBlank()) {
					cout << "[ ]";
				}
				else if(pieces[r][c].getRedTeam()) {
					if(pieces[r][c].getKing()) {
						cout << "{O}";
					}
					else {
						cout << "[O]";
					}
				}
				else {
					if(pieces[r][c].getKing()) {
						cout << "{X}";
					}
					else {
						cout << "[X]";
					}
				}
			}
			cout << endl;
		}
	}
	cout << "GAME OVER" << endl;
	delete board;
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
