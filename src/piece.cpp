#include "piece.h"

Piece::Piece() {
	isKing = false;
}

void Piece::setKing(bool k) {
	isKing = k;
}

bool Piece::getKing() {
	return isKing;
}

void Piece::setRedTeam(bool r) {
	teamRed = r;
}

bool Piece::getRedTeam() {
	return teamRed;
}

bool Piece::getBlank() {
	return isBlank;
}

void Piece::setBlank(bool b) {
	isBlank = b;
}
