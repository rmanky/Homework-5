using namespace std;

#include "tests.h"

const char* fName = "checkerBoard.txt";

bool tests()
{
	bool ok = testLoadFile(fName) && testPiece() && testBoard(fName)
	          && testMove(fName) && testThreeMoves(fName)
	          && testTenMoves(fName) && testThirtyMoves(fName) && testOutputFile(fName, "output.txt");
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
	cout << " --- TEST STARTING BOARD ---" << endl;
	bool answer = false;
	Board* board = new Board();
	board->generateBoard(FILENAME);
	board->displayBoard(NULL);
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
	cout << " --- TEST TWO MOVES ---" << endl;
	bool answer = false;
	Board* board = new Board();
	board->generateBoard(FILENAME);
	board->makeMove(NULL, true);
	board->makeMove(NULL, false);
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
	board->generateBoard(FILENAME);
	board->makeMove(NULL, true);
	board->makeMove(NULL, false);
	board->makeMove(NULL, true);
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
	board->generateBoard(FILENAME);
	for(int i = 0; i < 10; i++) {
		board->makeMove(NULL, i % 2 == 0);
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

bool testThirtyMoves(const char* FILENAME) {
	cout << " --- TEST THIRTY MOVES ---" << endl;
	bool answer = false;
	Board* board = new Board();
	board->generateBoard(FILENAME);
	for(int i = 0; i < 30; i++) {
		board->makeMove(NULL, i % 2 == 0);
	}
	delete board;
	cout << "The board has made thirty moves" << endl;
	cout << "King O's look like {O} and King X's look like {X}" << endl;
	cout << "Does this look correct? (y/n)" << endl;
	char c = getchar();
	getchar();
	if(c == 'y') {
		answer = true;
	}
	return answer;
}

bool testOutputFile(const char* FILENAME, const char* OUTPUTFILE) {
	cout << " --- TEST TEN MOVES AND OUTPUT ---" << endl;
	bool answer = false;
	Board* board = new Board();
	board->generateBoard(FILENAME);
	FILE* oFile = fopen(OUTPUTFILE, "w");
	for(int i = 0; i < 10; i++) {
		board->makeMove(oFile, i % 2 == 0);
	}
	delete board;
	cout << "The board has made ten moves" << endl;
	cout << "They have been placed in output.txt" << endl;
	cout << "King O's look like {O} and King X's look like {X}" << endl;
	cout << "Does this look correct? (y/n)" << endl;
	fclose(oFile);
	char c = getchar();
	getchar();
	if(c == 'y') {
		answer = true;
	}
	return answer;
}
