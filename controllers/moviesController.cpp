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

int getMoviesCount(routeParamsType routeParams) {
    ifstream MyFile(MOVIES_DB);

    if (!MyFile.is_open()) {
        cout << "Error: Unable to open file: " << MOVIES_DB << endl;
        return 0;
    }

    char line[DEFAULT_DB_ROW_SIZE];
    int count = 0;

    while (MyFile.getline(line, DEFAULT_DB_ROW_SIZE)) {
        char* currentId = getColumn(line, MOVIES_ID_COLUMN);
        int idNumber = myAtoi(currentId);
        delete[] currentId;

        double currentRating = getMovieRating(idNumber);

        if (currentRating < routeParams.filterRating) {
            continue;
        }

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

int findMovieByIdOrTitle(const char* query) {
    if (!query) {
        return 0;
    }

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

        double currentRating = getMovieRating(idNumber);

        if (currentRating < routeParams.filterRating) {
            continue;
        }

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

    if (routeParams.sortRating) {
        sortMoviesByRating(movies, moviesCount, routeParams.sortRating);
    }

    return movies;
}

movieType getMovieById(int movieId) {
    ifstream MoviesDB(MOVIES_DB);

    movieType currentMovie;

    if (!MoviesDB.is_open()) {
        cout << "Error: Unable to open file: " << MOVIES_DB << endl;
        return currentMovie;
    }

    char line[DEFAULT_DB_ROW_SIZE];
    int index = 0;

    while (MoviesDB.getline(line, DEFAULT_DB_ROW_SIZE)) {
        char* currentId = getColumn(line, MOVIES_ID_COLUMN);
        int idNumber = myAtoi(currentId);
        delete[] currentId;

        if (idNumber == movieId) {
            char* currentTitle = getColumn(line, MOVIES_TITLE_COLUMN);

            double currentRating = getMovieRating(idNumber);

            char* currentYear = getColumn(line, MOVIES_YEAR_COLUMN);
            int yearNumber = myAtoi(currentYear);
            delete[] currentYear;

            char* currentGenre = getColumn(line, MOVIES_GENRE_COLUMN);

            char* currentDirector = getColumn(line, MOVIES_DIRECTOR_COLUMN);

            char* currentActorsCount = getColumn(line, MOVIES_ACTORS_COUNT_COLUMN);
            int actorsCountNumber = myAtoi(currentActorsCount);
            delete[] currentActorsCount;

            char** currentActors = getMovieActors(idNumber, actorsCountNumber);

            currentMovie.id = idNumber;
            currentMovie.title = currentTitle;
            currentMovie.year = yearNumber;
            currentMovie.genre = currentGenre;
            currentMovie.director = currentDirector;
            currentMovie.rating = currentRating;
            currentMovie.actorsCount = actorsCountNumber;
            currentMovie.actors = currentActors;

            return currentMovie;
        }
    }

    // not found
    return currentMovie;
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

int updateMovie(movieType movie) {
    ifstream MoviesDB(MOVIES_DB);
    if (!MoviesDB.is_open()) {
        cout << "Error: Unable to open file: " << MOVIES_DB << endl;
        return 0;
    }

    // temporary file to store updated content
    ofstream TempFile("temp.txt");
    if (!TempFile.is_open()) {
        cout << "Error: Unable to open file: temp.txt" << endl;
        return 0;
    }

    char line[DEFAULT_DB_ROW_SIZE];

    while (MoviesDB.getline(line, DEFAULT_DB_ROW_SIZE)) {
        char* currentId = getColumn(line, MOVIES_ID_COLUMN);
        int idNumber = myAtoi(currentId);
        delete[] currentId;

        if (idNumber == movie.id) {
            TempFile << movie.id << DEFAULT_DB_DELIMITER;
            TempFile << movie.title << DEFAULT_DB_DELIMITER;
            TempFile << movie.year << DEFAULT_DB_DELIMITER;
            TempFile << movie.genre << DEFAULT_DB_DELIMITER;
            TempFile << movie.director << DEFAULT_DB_DELIMITER;
            TempFile << movie.actorsCount << '\n';
        } else {
            TempFile << line << '\n';
        }
    }

    MoviesDB.close();
    TempFile.close();

    if (remove(MOVIES_DB) != 0) {
        cout << "Error: Deleting file: " << MOVIES_DB << endl;
        return 0;
    }

    if (rename("temp.txt", MOVIES_DB) != 0) {
        cout << "Error: Renaming file temp.txt to " << MOVIES_DB << endl;
        return 0;
    }

    // remove old movie actors
    deleteRecord(ACTORS_DB, movie.id, ACTORS_MOVIE_ID_COLUMN);

    // add new movie actors
    addActorsToMovie(movie.actors, movie.actorsCount, movie.id);

    return 0;
}

int deleteMovie(const char* query) {
    if (!query) {
        return 0;
    }

    int foundId = findMovieByIdOrTitle(query);

    if (foundId == 0) {
        return MOVIE_NOT_FOUND;
    }

    // delete information in Movies file
    deleteRecord(MOVIES_DB, foundId, MOVIES_ID_COLUMN);

    // delete information in Actors file
    deleteRecord(ACTORS_DB, foundId, ACTORS_MOVIE_ID_COLUMN);

    // delete information in Ratings file
    deleteRecord(RATINGS_DB, foundId, RATINGS_MOVIE_ID_COLUMN);

    return 0;
}

int addMovieRating(const char* query, int userId, int rating) {
    if (!query) {
        return 0;
    }

    if (rating < 1 || rating > 10) {
        return INVALID_RATING;
    }

    int foundId = findMovieByIdOrTitle(query);

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

void freeUpMovieSpace(movieType movie) {
    delete[] movie.title;
    delete[] movie.genre;
    delete[] movie.director;

    for (int i = 0; i < movie.actorsCount; i++) {
        delete[] movie.actors[i];
    }
    delete[] movie.actors;
}

void freeUpMoviesSpace(movieType* movies, int length) {
    if (!movies) {
        return;
    }

    for (int i = 0; i < length; i++) {
        freeUpMovieSpace(movies[i]);
    }

    delete[] movies;
}
