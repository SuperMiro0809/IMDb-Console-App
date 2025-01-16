#include <utils/databaseUtils.h>

#include <iostream>
#include <fstream>
#include <constants.h>
#include <utils/stringUtils.h>
using namespace std;

int autoIncrement(const char* dbName) {
    ifstream DBFile(dbName);

    if (!DBFile.is_open()) {
        cout << "Error: Unable to open file: " << dbName << endl;
        return -1;
    }

    char line[DEFAULT_DB_ROW_SIZE];
    int currentId = 0;

    while (!DBFile.eof()) {
        DBFile >> line;

        char* idStr = substringBeforeSymbol(line, DEFAULT_DB_DELIMITER);
        int idColumn = myAtoi(idStr);
        
        if (idColumn > 0) {
            currentId = idColumn;
        }

        delete[] idStr;
    }

    DBFile.close();

    return currentId + 1;
}