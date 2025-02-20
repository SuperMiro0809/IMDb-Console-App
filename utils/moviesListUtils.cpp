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
* <Definition of Movies List Utility functions>
*
*/

#include <utils/moviesListUtils.h>

#include <global/uiComponents.h>
#include <global/constants.h>
#include <global/errorCodes.h>
#include <global/databaseArchitecture.h>
#include <controllers/moviesController.h>

#include <iostream>
using namespace std;

void rateMovieAction(int userId) {
    int result = 0;
    do {
        cin.ignore(); // discard newline character

        char* query = printTextField("Enter movie title or movie id:");
        int rating = printNumberField("Enter rating (1 - 10):");

        result = addMovieRating(query, userId, rating);

        delete[] query;

        if (result == MOVIE_NOT_FOUND || result == INVALID_RATING) {
            printError(result);
        }
    } while (result == MOVIE_NOT_FOUND || result == INVALID_RATING);
}

void updateColumnForm(movieType& movie, int column, int& result) {
    switch (column) {
        case MOVIES_TITLE_COLUMN: {
            cin.ignore(); // discard newline character

            delete[] movie.title;
            char* newTitle = printTextField("Enter new title:");
            movie.title = newTitle;

            result = updateMovie(movie);
            break;
        }
        case MOVIES_YEAR_COLUMN: {
            int newYear = printNumberField("Enter new year:");
            movie.year = newYear;

            result = updateMovie(movie);
            break;
        }
        case MOVIES_GENRE_COLUMN: {
            cin.ignore(); // discard newline character

            delete[] movie.genre;
            char* newGenre = printTextField("Enter new genre:");
            movie.genre = newGenre;

            result = updateMovie(movie);
            break;
        }
        case MOVIES_DIRECTOR_COLUMN: {
            cin.ignore(); // discard newline character

            delete[] movie.director;
            char* newDirector = printTextField("Enter new director:");
            movie.director = newDirector;

            result = updateMovie(movie);
            break;
        }
        case MOVIES_ACTORS_COUNT_COLUMN: {
            for (int i = 0; i < movie.actorsCount; i++) {
                delete[] movie.actors[i];
            }
            delete[] movie.actors;

            int newActorsCount = printNumberField("How many actors:");

            char** newActors = printActorsField(newActorsCount);

            movie.actorsCount = newActorsCount;
            movie.actors = newActors;

            result = updateMovie(movie);
            break;
        }
        default:
            result = INVALID_DATA_COLUMN;
    }

    // clean up
    freeUpMovieSpace(movie);
}

void updateMovieAction() {
    int result = 0;

    do {
        if (result == 0 || result == INVALID_DATA_COLUMN) { // first try or when invalid column is entered
            cin.ignore(); // discard newline character
        }

        char* query = printTextField("Enter the title or the id of the movie you want to update:");

        int movieId = findMovieByIdOrTitle(query);

        delete[] query;

        if (movieId == 0) {
            result = MOVIE_NOT_FOUND;
            printError(result);
            continue;
        }
        
        movieType currentMovie = getMovieById(movieId);

        // print movie information
        printMovieInfo(currentMovie);

        int column = printNumberField("Enter which information you want to update < 1 - Title | 2 - Year | 3 - Genre | 4 - Director | 5 - Actors>:");

        updateColumnForm(currentMovie, column, result);

        if (result == INVALID_DATA_COLUMN) {
            printError(result);
        }
    } while (result == MOVIE_NOT_FOUND || result == INVALID_DATA_COLUMN);
}

void deleteMovieAction() {
    int result = 0;

    do {
        cin.ignore(); // discard newline character

        char* query = printTextField("Enter the title or the id of the movie you want to delete:");

        result = deleteMovie(query);

        delete[] query;

        if (result == MOVIE_NOT_FOUND) {
            printError(result);
        }
    } while (result == MOVIE_NOT_FOUND);
}
