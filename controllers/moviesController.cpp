#include <controllers/moviesController.h>

#include <constants.h>
#include <utils/databaseUtils.h>

#include <fstream>
#include <iostream>
using namespace std;

int getMovies() {

}

int addMovie(const char* title, int year, const char* genre, const char* director) {
    if (!title || !genre || !director) {
        return 0;
    }

    ofstream MyFile(MOVIES_DB, ios::app); // open file in append mode

    // save record
    int nextId = autoIncrement(MOVIES_DB);
    MyFile << nextId << DEFAULT_DB_DELIMITER;
    MyFile << title << DEFAULT_DB_DELIMITER;
    MyFile << year << DEFAULT_DB_DELIMITER;
    MyFile << genre << DEFAULT_DB_DELIMITER;
    MyFile << director << DEFAULT_DB_DELIMITER;
    MyFile << 5 << '\n';

    MyFile.close();
    return nextId;
}

int updateMovie(int id) {

}

int deleteMovie(int id) {

}