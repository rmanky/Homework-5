#include "board.h"

Board::Board() {

}

Piece** Board::generateBoard(const char* FILENAME) {
	srand(time(0));
	ImportFile* iF = new ImportFile(FILENAME);
	int** places = iF->getPositions();
	Piece** positions = new Piece*[8];
	for(int r = 0; r < 8; r++) {
		positions[r] = new Piece[8];
		for(int c = 0; c < 8; c++) {
			if(places[r][c] == 0) {
				positions[r][c].setBlank(true);
			}
			else {
				positions[r][c].setBlank(false);
				if (places[r][c] == 1) {
					positions[r][c].setRedTeam(true);
				}
				else if(places[r][c] == -1) {
					positions[r][c].setRedTeam(false);
				}
			}
		}
	}
	delete iF;
	board = positions;
	return board;
}

Piece** Board::getBoard() {
	return board;
}

void Board::makeMove(FILE* oFile, bool teamRed) {
	fprintf(oFile, "--- NEW MOVE --- \n");
	std::cout << " --- NEW MOVE --- " << std::endl;
	int numMovesConsidered = 0;
	int moves[4][2] = {{1,-1},{1,1},{-1,-1},{-1,1}};
	bool willJump = false;
	bool willMove = false;
	int moveFromX = 0;
	int moveFromY = 0;
	int bestMoveX = 0;
	int bestMoveY = 0;
	int destroyX = 0;
	int destroyY = 0;
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(!board[r][c].getBlank() && board[r][c].getRedTeam() == teamRed) {
				int dir = 2;
				if(!board[r][c].getKing()) {
					if(teamRed) {
						moves[0][0] = 1;
						moves[0][1] = -1;
						moves[1][0] = 1;
						moves[1][1] = 1;
					}
					else {
						moves[0][0] = -1;
						moves[0][1] = -1;
						moves[1][0] = -1;
						moves[1][1] = 1;
					}
				}
				else {
					dir = 4;
				}
				int d = rand() % dir;
				for(int b = 0; b < dir; b++) {
					int x = (b + d) % dir;
					int testMoveX = r + moves[x][0];
					int testMoveY = c + moves[x][1];
					int testJumpX = r + moves[x][0] * 2;
					int testJumpY = c + moves[x][1] * 2;
					bool canMove = testMoveX >= 0 && testMoveX < 8 && testMoveY >= 0 && testMoveY < 8;
					if(canMove) {
						bool canJump = testJumpX >= 0 && testJumpX < 8 && testJumpY >= 0 && testJumpY < 8 && board[testJumpX][testJumpY].getBlank();
						if(canJump && board[testMoveX][testMoveY].getRedTeam() != teamRed && !board[testMoveX][testMoveY].getBlank()) {
							putMoveInFile(oFile, r, c, testJumpX, testJumpY, " -->? ");
							numMovesConsidered++;
							willJump = true;
							willMove = true;
							moveFromX = r;
							moveFromY = c;
							destroyX = testMoveX;
							destroyY = testMoveY;
							bestMoveX = testJumpX;
							bestMoveY = testJumpY;
						}
					}
					if(!willJump && canMove && !willMove) {
						if(board[testMoveX][testMoveY].getBlank()) {
							putMoveInFile(oFile, r, c, testMoveX, testMoveY, " ->? ");
							numMovesConsidered++;
							bestMoveX = testMoveX;
							bestMoveY = testMoveY;
							willMove = true;
							moveFromX = r;
							moveFromY = c;
						}
					}
				}
			}
		}
	}
	if(willMove) {
		std::cout << "Piece at " << moveFromX << " " << moveFromY << " has moved to " << bestMoveX << " " << bestMoveY << "\n";
		board[bestMoveX][bestMoveY].setKing(board[moveFromX][moveFromY].getKing());
		board[bestMoveX][bestMoveY].setBlank(board[moveFromX][moveFromY].getBlank());
		board[moveFromX][moveFromY].setBlank(true);
		board[bestMoveX][bestMoveY].setRedTeam(board[moveFromX][moveFromY].getRedTeam());
		if(bestMoveX == 7 && teamRed) {
			board[bestMoveX][bestMoveY].setKing(true);
		}
		if(bestMoveX == 0 && !teamRed) {
			board[bestMoveX][bestMoveY].setKing(true);
		}
		if(willJump) {
			std::cout << "It jumped over the piece at " << destroyX << " " << destroyY << std::endl;
			board[destroyX][destroyY].setBlank(true);
			putMoveInFile(oFile, moveFromX, moveFromY, bestMoveX, bestMoveY, " --> ");
			displayBoard(oFile);
			// Multi-jump?
			bool multiJump = true;
			bool canJump = false;
			int det = 2;
			if(!board[bestMoveX][bestMoveY].getKing()) {
				det = 4;
			}
			while(multiJump) {
				int d = rand() % det;
				for(int b = 0; b < det; b++) {
					int x = (b + d) % det;
					if(!canJump) {
						int testMoveX = bestMoveX + moves[x][0];
						int testMoveY = bestMoveY + moves[x][1];
						int testJumpX = bestMoveX + moves[x][0] * 2;
						int testJumpY = bestMoveY + moves[x][1] * 2;
						bool testJump = testJumpX >= 0 && testJumpX < 8 && testJumpY >= 0 && testJumpY < 8 && board[testJumpX][testJumpY].getBlank();
						canJump = testJump && board[testMoveX][testMoveY].getRedTeam() != teamRed && !board[testMoveX][testMoveY].getBlank();
						if(canJump) {
							moveFromX = bestMoveX;
							moveFromY = bestMoveY;
							bestMoveX = testJumpX;
							bestMoveY = testJumpY;
							destroyX = testMoveX;
							destroyY = testMoveY;
							putMoveInFile(oFile, moveFromX, moveFromY, bestMoveX, bestMoveY, " --->? ");
							numMovesConsidered++;
						}
					}
				}
				if(!canJump) {
					// No double Jump
					multiJump = false;
				}
				else {
					// Can do another jumped
					std::cout << "Piece at " << moveFromX << " " << moveFromY << " has jumped again to " << bestMoveX << " " << bestMoveY << "\n";
					std::cout << "It jumped over the piece at " << destroyX << " " << destroyY << std::endl;
					board[bestMoveX][bestMoveY].setKing(board[moveFromX][moveFromY].getKing());
					board[bestMoveX][bestMoveY].setBlank(board[moveFromX][moveFromY].getBlank());
					board[moveFromX][moveFromY].setBlank(true);
					board[bestMoveX][bestMoveY].setRedTeam(board[moveFromX][moveFromY].getRedTeam());
					if(bestMoveX == 7 && teamRed) {
						board[bestMoveX][bestMoveY].setKing(true);
					}
					if(bestMoveX == 0 && !teamRed) {
						board[bestMoveX][bestMoveY].setKing(true);
					}
					board[destroyX][destroyY].setBlank(true);
					putMoveInFile(oFile, moveFromX, moveFromY, bestMoveX, bestMoveY, " ---> ");
					displayBoard(oFile);
					canJump = false;
				}
			}
		}
		else {
			putMoveInFile(oFile, moveFromX, moveFromY, bestMoveX, bestMoveY, " -> ");
			displayBoard(oFile);
		}
		fprintf(oFile, "Considered moves: ");
		fprintf(oFile, "%d", numMovesConsidered);
		fprintf(oFile, "\n");
		std::cout << "Considered moves: " << numMovesConsidered << std::endl;
	}
	else {
		std::cout << "A move could not be found for team ";
		fprintf(oFile, "--- NO MOVE FOR TEAM ");
		if(teamRed) {
			std::cout << "O" << "\n";
			fprintf(oFile, "O ---\n");
		}
		else {
			std::cout << "X" << "\n";
			fprintf(oFile, "X ---\n");
		}
	}
}

void Board::putMoveInFile(FILE* oFile, int r, int c, int testMoveX, int testMoveY, const char* arrow) {
	fprintf(oFile, "%d", r);
	fprintf(oFile, " ");
	fprintf(oFile, "%d", c);
	fprintf(oFile, arrow);
	fprintf(oFile, "%d", testMoveX);
	fprintf(oFile, " ");
	fprintf(oFile, "%d", testMoveY);
	fprintf(oFile, "\n");
}

void Board::displayBoard(FILE* oFile) {
	Piece** pieces = getBoard();
	for(int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
			if(pieces[r][c].getBlank()) {
				fprintf(oFile, "[ ]");
				std::cout << "[ ]";
			}
			else if(pieces[r][c].getRedTeam()) {
				if(pieces[r][c].getKing()) {
					fprintf(oFile, "{0}");
					std::cout << "{O}";
				}
				else {
					fprintf(oFile, "[0]");
					std::cout << "[O]";
				}
			}
			else {
				if(pieces[r][c].getKing()) {
					fprintf(oFile, "{X}");
					std::cout << "{X}";
				}
				else {
					fprintf(oFile, "[X]");
					std::cout << "[X]";
				}
			}
		}
		fprintf(oFile, "\n");
		std::cout << std::endl;
	}
}
