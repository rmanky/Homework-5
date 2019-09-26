using namespace std;

#include "tests.h"

const char* fName = "checkerBoard.txt";

bool tests()
{
	bool ok = testLoadFile(fName) && testPiece() && testBoard(fName)
	          && testMove(fName) && testThreeMoves(fName)
	          && testTenMoves(fName) && testHunderedMoves(fName);
	return ok;
}

bool testLoadFile(const char* FILENAME) {
	bool answer = false;
	ImportFile* iF = new ImportFile(FILENAME);
	int** positions = iF->getPositions();
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			cout << positions[r][c] << " ";
		}
		cout << endl;
	}
	delete iF;
	cout << "Does this look correct? (y/n)" << endl;
	char c = getchar();
	getchar();
	if(c == 'y') {
		answer = true;
	}
	return answer;
}

bool testPiece() {
	cout << "Creating a new Piece" << endl;
	bool answer = false;
	Piece* testPiece = new Piece();
	if(!testPiece->getKing()) {
		cout << "Value was false, which is correct" << endl;
		testPiece->setKing(true);
		if(testPiece->getKing()) {
			cout << "Value is now true, test passed" << endl;
			answer = true;
		}
	}
	delete testPiece;
	return answer;
}

bool testBoard(const char* FILENAME) {
	bool answer = false;
	Board* board = new Board();
	Piece** pieces = board->generateBoard(FILENAME);
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(pieces[r][c].getBlank()) {
				cout << "[ ]";
			}
			else if(pieces[r][c].getRedTeam()) {
				cout << "[O]";
			}
			else {
				cout << "[X]";
			}
		}
		cout << endl;
	}
	delete board;
	cout << "This is the starting board" << endl;
	cout << "Does this look correct? (y/n)" << endl;
	char c = getchar();
	getchar();
	if(c == 'y') {
		answer = true;
	}
	return answer;
}

bool testMove(const char* FILENAME) {
	bool answer = false;
	Board* board = new Board();
	Piece** pieces = board->generateBoard(FILENAME);
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(pieces[r][c].getBlank()) {
				cout << "[ ]";
			}
			else if(pieces[r][c].getRedTeam()) {
				cout << "[O]";
			}
			else {
				cout << "[X]";
			}
		}
		cout << endl;
	}
	cout << "--- MAKING MOVE ---" << endl;
	board->makeMove(true);
	pieces = board->getBoard();
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(pieces[r][c].getBlank()) {
				cout << "[ ]";
			}
			else if(pieces[r][c].getRedTeam()) {
				cout << "[O]";
			}
			else {
				cout << "[X]";
			}
		}
		cout << endl;
	}
	cout << "--- MAKING MOVE SECOND MOVE ---" << endl;
	board->makeMove(false);
	pieces = board->getBoard();
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(pieces[r][c].getBlank()) {
				cout << "[ ]";
			}
			else if(pieces[r][c].getRedTeam()) {
				cout << "[O]";
			}
			else {
				cout << "[X]";
			}
		}
		cout << endl;
	}
	delete board;
	cout << "The board has made two moves" << endl;
	cout << "Does this look correct? (y/n)" << endl;
	char c = getchar();
	getchar();
	if(c == 'y') {
		answer = true;
	}
	return answer;
}

bool testThreeMoves(const char* FILENAME) {
	cout << " --- TEST THREE MOVES ---" << endl;
	bool answer = false;
	Board* board = new Board();
	Piece** pieces = board->generateBoard(FILENAME);
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(pieces[r][c].getBlank()) {
				cout << "[ ]";
			}
			else if(pieces[r][c].getRedTeam()) {
				cout << "[O]";
			}
			else {
				cout << "[X]";
			}
		}
		cout << endl;
	}
	cout << "--- MAKING MOVE ---" << endl;
	board->makeMove(true);
	pieces = board->getBoard();
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(pieces[r][c].getBlank()) {
				cout << "[ ]";
			}
			else if(pieces[r][c].getRedTeam()) {
				cout << "[O]";
			}
			else {
				cout << "[X]";
			}
		}
		cout << endl;
	}
	cout << "--- MAKING MOVE SECOND MOVE ---" << endl;
	board->makeMove(false);
	pieces = board->getBoard();
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(pieces[r][c].getBlank()) {
				cout << "[ ]";
			}
			else if(pieces[r][c].getRedTeam()) {
				cout << "[O]";
			}
			else {
				cout << "[X]";
			}
		}
		cout << endl;
	}
	cout << "--- MAKING MOVE THIRD MOVE ---" << endl;
	board->makeMove(true);
	pieces = board->getBoard();
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(pieces[r][c].getBlank()) {
				cout << "[ ]";
			}
			else if(pieces[r][c].getRedTeam()) {
				cout << "[O]";
			}
			else {
				cout << "[X]";
			}
		}
		cout << endl;
	}
	delete board;
	cout << "The board has made three moves" << endl;
	cout << "Does this look correct? (y/n)" << endl;
	char c = getchar();
	getchar();
	if(c == 'y') {
		answer = true;
	}
	return answer;
}

bool testTenMoves(const char* FILENAME) {
	cout << " --- TEST TEN MOVES ---" << endl;
	bool answer = false;
	Board* board = new Board();
	Piece** pieces = board->generateBoard(FILENAME);
	for(int i = 0; i < 10; i++) {
		board->makeMove(i % 2 == 0);
		for(int r = 0; r < 8; r++) {
			for(int c = 0; c < 8; c++) {
				if(pieces[r][c].getBlank()) {
					cout << "[ ]";
				}
				else if(pieces[r][c].getRedTeam()) {
					cout << "[O]";
				}
				else {
					cout << "[X]";
				}
			}
			cout << endl;
		}
	}
	delete board;
	cout << "The board has made ten moves" << endl;
	cout << "Does this look correct? (y/n)" << endl;
	char c = getchar();
	getchar();
	if(c == 'y') {
		answer = true;
	}
	return answer;
}

bool testHunderedMoves(const char* FILENAME) {
	cout << " --- TEST ONE HUNDRED MOVES ---" << endl;
	bool answer = false;
	Board* board = new Board();
	Piece** pieces = board->generateBoard(FILENAME);
	for(int i = 0; i < 100; i++) {
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
	delete board;
	cout << "The board has made a hundred moves" << endl;
	cout << "King O's look like {O} and King X's look like {X}" << endl;
	cout << "Does this look correct? (y/n)" << endl;
	char c = getchar();
	getchar();
	if(c == 'y') {
		answer = true;
	}
	return answer;
}
