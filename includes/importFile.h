#ifndef IMPORT_FILE_H_
#define IMPORT_FILE_H_

#include <iostream>
#include <fstream>

class ImportFile {
private:
int** positions;

public:
ImportFile();
ImportFile(const char*);
int** getPositions();
};

#endif
