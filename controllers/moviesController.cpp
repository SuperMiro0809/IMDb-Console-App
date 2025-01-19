#include <controllers/moviesController.h>

#include <constants.h>
#include <databaseArchitecture.h>
#include <utils/databaseUtils.h>
#include <utils/stringUtils.h>
#include <utils/moviesUtils.h>
#include <errorCodes.h>

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
        char* currentTitle = getColumn(line, MOVIES_TITLE_COLUMN);

        if (routeParams.searchTitle && !searchInText(currentTitle, routeParams.searchTitle)) {
            delete[] currentTitle;
            continue;
        }

        char* currentGenre = getColumn(line, MOVIES_GENRE_COLUMN);

        if (routeParams.searchGenre && myStrCmp(currentGenre, routeParams.searchGenre) != 0) {
            delete[] currentTitle;
            delete[] currentGenre;
            continue;
        }

        count++;
    }

    return count;
}

int getMovieByIdOrTitle(const char* query) {
    ifstream MoviesDB(MOVIES_DB);

    if (!MoviesDB.is_open()) {
        cout << "Error: Unable to open file: " << MOVIES_DB << endl;
        return 0;
    }

    char line[DEFAULT_DB_ROW_SIZE];
    int foundId = 0;

    while (MoviesDB.getline(line, DEFAULT_DB_ROW_SIZE)) {
        char* currentId = getColumn(line, MOVIES_ID_COLUMN);
        int idNumber = myAtoi(currentId);

        if (myStrCmp(currentId, query) == 0) {
            delete[] currentId;
            foundId = idNumber;
            break;
        }

        char* currentTitle = getColumn(line, MOVIES_TITLE_COLUMN);

        if (myStrCmp(currentTitle, query) == 0) {
            delete[] currentId;
            delete[] currentTitle;
            foundId = idNumber;
            break;
        }
    }

    MoviesDB.close();

    return foundId;
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
        char* currentId = getColumn(line, ACTORS_MOVIE_ID_COLUMN);
        int idNumber = myAtoi(currentId);

        delete[] currentId;

        if (idNumber == movieId) {
            char* currentName = getColumn(line, ACTORS_NAME_COLUMN);
            actors[index++] = currentName;
        }
    }

    MyFile.close();
    return actors;
}

double getMovieRating(int movieId) {
    ifstream MyFile(RATINGS_DB);

    if (!MyFile.is_open()) {
        cout << "Error: Unable to open file: " << RATINGS_DB << endl;
        return 0;
    }

    int count = 1;
    int ratingSum = DEFAULT_MOVIE_RATING;

    char line[DEFAULT_DB_ROW_SIZE];
    while (MyFile >> line) {
        char* currentId = getColumn(line, RATINGS_MOVIE_ID_COLUMN);
        int idNumber = myAtoi(currentId);
        delete[] currentId;

        if (movieId == idNumber) {
            char* currentRating = getColumn(line, RATINGS_RATING_COLUMN);
            int ratingNumber = myAtoi(currentId);
            delete[] currentRating;

            count++;
            ratingSum += ratingNumber;
        }
    }

    return ratingSum / count;
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
        char* currentId = getColumn(line, MOVIES_ID_COLUMN);
        int idNumber = myAtoi(currentId);
        delete[] currentId;

        char* currentTitle = getColumn(line, MOVIES_TITLE_COLUMN);

        if (routeParams.searchTitle && !searchInText(currentTitle, routeParams.searchTitle)) {
            delete[] currentTitle;
            continue;
        }

        char* currentYear = getColumn(line, MOVIES_YEAR_COLUMN);
        int yearNumber = myAtoi(currentYear);
        delete[] currentYear;

        char* currentGenre = getColumn(line, MOVIES_GENRE_COLUMN);

        if (routeParams.searchGenre && myStrCmp(currentGenre, routeParams.searchGenre) != 0) {
            delete[] currentTitle;
            delete[] currentGenre;
            continue;
        }

        char* currentDirector = getColumn(line, MOVIES_DIRECTOR_COLUMN);

        char* currentActorsCount = getColumn(line, MOVIES_ACTORS_COUNT_COLUMN);
        int actorsCountNumber = myAtoi(currentActorsCount);
        delete[] currentActorsCount;

        char** currentActors = getMovieActors(idNumber, actorsCountNumber);

        double currentRating = getMovieRating(idNumber);

        movieType currentMovie;
        currentMovie.id = idNumber;
        currentMovie.title = currentTitle;
        currentMovie.year = yearNumber;
        currentMovie.genre = currentGenre;
        currentMovie.director = currentDirector;
        currentMovie.rating = currentRating;
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
    MyFile << actorsCount << '\n';

    MyFile.close();

    addActorsToMovie(actors, actorsCount, nextId);

    return nextId;
}

int updateMovie(int id) {

}

int deleteMovie(int id) {

}

int addMovieRating(const char* query, int userId, int rating) {
    // no nullptr check because because movie search is by title OR by id
    if (rating < 1 || rating > 10) {
        return INVALID_RATING;
    }

    int foundId = getMovieByIdOrTitle(query);

    if (foundId == 0) {
        return MOVIE_NOT_FOUND;
    }

    ofstream RatingsDB(RATINGS_DB, ios::app); // open file in append mode

    RatingsDB << foundId << DEFAULT_DB_DELIMITER;
    RatingsDB << userId << DEFAULT_DB_DELIMITER;
    RatingsDB << rating << '\n';

    RatingsDB.close();

    return 0;
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
