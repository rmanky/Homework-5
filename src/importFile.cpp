using namespace std;
#include "importFile.h"

ImportFile::ImportFile(const char* FILENAME) {
	positions = new int*[8];
	fstream pFile(FILENAME, ios_base::in);
	int num = 0;
	for (int r = 0; r < 8; r++) {
		positions[r] = new int[8];
		for (int c = 0; c < 8; c++) {
			pFile >> num;
			positions[r][c] = num;
		}
	}
	pFile.close();
}

ImportFile::ImportFile() {
	ImportFile("checkerBoard.txt");
}

int** ImportFile::getPositions() {
	return positions;
}
