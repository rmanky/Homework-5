#ifndef BOARD_H_
#define BOARD_H_

#include "importFile.h"
#include "piece.h"
#include <time.h>

class Board {
private:
Piece** board;

public:
Board();
Piece** generateBoard(const char*);
Piece** getBoard();
void makeMove(FILE*, bool);
void putMoveInFile(FILE*, int, int, int, int, const char*);
void displayBoard(FILE*);
};


#endif
