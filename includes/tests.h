#ifndef TESTS_H_
#define TESTS_H_

#include "board.h"
#include "importFile.h"
#include "piece.h"

#include <iostream>

bool tests();

bool testLoadFile(const char*);

bool testPiece();

bool testBoard(const char*);

bool testMove(const char*);

bool testThreeMoves(const char*);

bool testTenMoves(const char*);

bool testThirtyMoves(const char*);

bool testOutputFile(const char*, const char*);

#endif
