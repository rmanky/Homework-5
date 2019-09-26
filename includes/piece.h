#ifndef PIECE_H_
#define PIECE_H_

class Piece {
private:
bool isKing;
bool teamRed;
bool isBlank;

public:
Piece();
void setKing(bool);
bool getKing();
void setRedTeam(bool);
bool getRedTeam();
bool getBlank();
void setBlank(bool);
};

#endif
