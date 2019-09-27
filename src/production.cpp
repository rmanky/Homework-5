using namespace std;
#include "production.h"

void production(int argc, char** argv)
{
	FILE* oFile = fopen("output.txt", "w");
	cout << " --- --- --- --- --- ---" << endl;
	cout << " --- --- --- --- --- ---" << endl;
	cout << " --- --- --- --- --- ---" << endl;
	cout << " ---- STARTING GAME ----" << endl;
	Board* board = new Board();
	board->generateBoard("checkerBoard.txt");
	char *p;
	int numMoves;
	long conv = strtol(argv[1], &p, 10);
	numMoves = conv;
	if(numMoves > 0) {
		// User entereted command line argument
	}
	else {
		cout << "Please enter a maximum number of moves: " << endl;
		cin >> numMoves;
	}
	cout << " --- NUMBER OF MOVES IS " << numMoves << " ---" << endl;
	int i = 0;
	while(i < numMoves) {
		i++;
		board->makeMove(oFile, i % 2 == 0);
	}
	cout << "GAME OVER" << endl;
	delete board;
	fclose(oFile);
}
