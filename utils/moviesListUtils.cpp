#include <utils/moviesListUtils.h>

#include <ui-components.h>
#include <constants.h>
#include <errorCodes.h>
#include <controllers/moviesController.h>

#include <iostream>
using namespace std;

void rateMovieAction(int userId) {
    int result = 0;
    do {
        cin.ignore(); // discard newline character

        char* query = printTextField("Enter movie title or movie id:");
        int rating = printNumberField("Enter rating (1 - 10): ");

        result = addMovieRating(query, userId, rating);

        delete[] query;

        if (result == MOVIE_NOT_FOUND || result == INVALID_RATING) {
            printError(result);
        }
    } while (result == MOVIE_NOT_FOUND || result == INVALID_RATING);
}

void deleteMovieAction() {
    int result = 0;
    do {
        cin.ignore(); // discard newline character

        char* query = printTextField("Enter movie title or movie id:");

        result = deleteMovie(query);

        delete[] query;

        if (result == MOVIE_NOT_FOUND) {
            printError(result);
        }
    } while (result == MOVIE_NOT_FOUND);
}
