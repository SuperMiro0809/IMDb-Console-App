/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
*
* @author Miroslav Balev
* @idnumber 9MI0600470
* @compiler GCC
*
* <Definition of Database Utility functions>
*
*/

#include <utils/databaseUtils.h>

#include <global/constants.h>
#include <utils/stringUtils.h>

#include <fstream>
#include <iostream>
using namespace std;

int autoIncrement(const char* dbName) {
    if (!dbName) {
        return 0;
    }

    ifstream DBFile(dbName);

    if (!DBFile.is_open()) {
        cout << "Error: Unable to open file: " << dbName << endl;
        return -1;
    }

    char line[DEFAULT_DB_ROW_SIZE];
    int currentId = 0;

    while (DBFile.getline(line, DEFAULT_DB_ROW_SIZE)) {
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

void deleteRecord(const char* dbName, int queryId, int queryColumn) {
    if (!dbName) {
        return;
    }

    ifstream DBFile(dbName);
    if (!DBFile.is_open()) {
        cout << "Error: Unable to open file: " << dbName << endl;
        return;
    }

    // temporary file to store updated content
    ofstream TempFile("temp.txt");
    if (!TempFile.is_open()) {
        cout << "Error: Unable to open file: temp.txt" << endl;
        return;
    }

    char line[DEFAULT_DB_ROW_SIZE];
    while (DBFile.getline(line, DEFAULT_DB_ROW_SIZE)) {
        char* currentQueryColumn = getColumn(line, queryColumn);
        int queryColumnNumber = myAtoi(currentQueryColumn);
        delete[] currentQueryColumn;

        if (queryColumnNumber != queryId) {
            TempFile << line << '\n';
        }
    }

    DBFile.close();
    TempFile.close();

    if (remove(dbName) != 0) {
        cout << "Error: Deleting file: " << dbName << endl;
        return;
    }

    if (rename("temp.txt", dbName) != 0) {
        cout << "Error: Renaming file temp.txt to " << dbName << endl;
        return;
    }
}
