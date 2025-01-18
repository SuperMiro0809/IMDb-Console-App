#include <controllers/moviesController.h>

#include <constants.h>
#include <utils/databaseUtils.h>
#include <utils/stringUtils.h>
#include <utils/moviesUtils.h>

#include <fstream>
#include <iostream>
using namespace std;

int getMoviesCount(routeParamsType routeParams) {
    ifstream MyFile(MOVIES_DB);

    if (!MyFile.is_open()) {
        cout << "Error: Unable to open file: " << MOVIES_DB << endl;
        return 0;
    }

    char line[DEFAULT_DB_ROW_SIZE];
    int count = 0;

    while (MyFile.getline(line, DEFAULT_DB_ROW_SIZE)) {
        char* currentTitle = getColumn(line, TITLE_COLUMN);

        if (routeParams.searchTitle && !searchInText(currentTitle, routeParams.searchTitle)) {
            delete[] currentTitle;
            continue;
        }

        char* currentGenre = getColumn(line, GENRE_COLUMN);

        if (routeParams.searchGenre && myStrCmp(currentGenre, routeParams.searchGenre) != 0) {
            delete[] currentTitle;
            delete[] currentGenre;
            continue;
        }

        count++;
    }

    return count;
}

void addActorsToMovie(const char* const* actors, int actorsCount, int movieId) {
    if (!actors) {
        return;
    }

    ofstream MyFile(ACTORS_DB, ios::app); // open file in append mode

    for (int i = 0; i < actorsCount; i++) {
        MyFile << movieId << DEFAULT_DB_DELIMITER;
        MyFile << actors[i] << '\n';
    }

    MyFile.close();
}

char** getMovieActors(int movieId, int actorsCount) {
    ifstream MyFile(ACTORS_DB);

    if (!MyFile.is_open()) {
        cout << "Error: Unable to open file: " << ACTORS_DB << endl;
        return nullptr;
    }

    char** actors = new char* [actorsCount];
    int index = 0;

    char line[DEFAULT_DB_ROW_SIZE];
    while (MyFile.getline(line, DEFAULT_DB_ROW_SIZE)) {
        char* currentId = getColumn(line, MOVIE_ID_COLUMN);
        int idNumber = myAtoi(currentId);

        delete[] currentId;

        if (idNumber == movieId) {
            char* currentName = getColumn(line, ACTOR_NAME_COLUMN);
            actors[index++] = currentName;
        }
    }

    MyFile.close();
    return actors;
}

movieType* getMovies(routeParamsType routeParams) {
    ifstream MoviesDB(MOVIES_DB);

    if (!MoviesDB.is_open()) {
        cout << "Error: Unable to open file: " << MOVIES_DB << endl;
        return nullptr;
    }

    int moviesCount = getMoviesCount(routeParams);
    movieType* movies = new movieType[moviesCount];

    char line[DEFAULT_DB_ROW_SIZE];
    int index = 0;

    while (MoviesDB.getline(line, DEFAULT_DB_ROW_SIZE)) {
        char* currentId = getColumn(line, ID_COLUMN);
        int idNumber = myAtoi(currentId);
        delete[] currentId;

        char* currentTitle = getColumn(line, TITLE_COLUMN);

        if (routeParams.searchTitle && !searchInText(currentTitle, routeParams.searchTitle)) {
            delete[] currentTitle;
            continue;
        }

        char* currentYear = getColumn(line, YEAR_COLUMN);
        int yearNumber = myAtoi(currentYear);
        delete[] currentYear;

        char* currentGenre = getColumn(line, GENRE_COLUMN);

        if (routeParams.searchGenre && myStrCmp(currentGenre, routeParams.searchGenre) != 0) {
            delete[] currentTitle;
            delete[] currentGenre;
            continue;
        }

        char* currentDirector = getColumn(line, DIRECTOR_COLUMN);
        char* currentRating = getColumn(line, RATING_COLUMN);

        char* currentActorsCount = getColumn(line, ACTORS_COUNT_COLUMN);
        int actorsCountNumber = myAtoi(currentActorsCount);
        delete[] currentActorsCount;

        char** currentActors = getMovieActors(idNumber, actorsCountNumber);

        movieType currentMovie;
        currentMovie.id = idNumber;
        currentMovie.title = currentTitle;
        currentMovie.year = yearNumber;
        currentMovie.genre = currentGenre;
        currentMovie.director = currentDirector;
        currentMovie.actorsCount = actorsCountNumber;
        currentMovie.actors = currentActors;

        movies[index++] = currentMovie; 
    }

    if (routeParams.sortTitle) {
        sortMoviesByTitle(movies, moviesCount, routeParams.sortTitle);
    }

    return movies;
}

int addMovie(const char* title, int year, const char* genre, const char* director, const char* const* actors, int actorsCount) {
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
    MyFile << 5 << DEFAULT_DB_DELIMITER;
    MyFile << actorsCount << '\n';

    MyFile.close();

    addActorsToMovie(actors, actorsCount, nextId);

    return nextId;
}

int updateMovie(int id) {

}

int deleteMovie(int id) {

}

void freeUpMoviesSpace(movieType* movies, int length) {
    if (!movies) {
        return;
    }

    for (int i = 0; i < length; i++) {
        delete[] movies[i].title;
        delete[] movies[i].genre;
        delete[] movies[i].director;

        for (int j = 0; j < movies[i].actorsCount; j++) {
            delete[] movies[i].actors[j];
        }
        delete[] movies[i].actors;
    }

    delete[] movies;
}
