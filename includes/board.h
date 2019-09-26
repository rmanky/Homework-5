#ifndef BOARD_H_
#define BOARD_H_

#include "importFile.h"
#include "piece.h"
#include <string>

class Board {
private:
Piece** board;

public:
Board();
Piece** generateBoard(const char*);
Piece** getBoard();
void makeMove(bool);
void putMoveInFile(FILE*, int, int, int, int, const char*);
};


#endif
