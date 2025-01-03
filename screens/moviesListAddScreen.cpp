#include <screens/moviesListAddScreen.h>

#include <ui-components.h>
#include <colors.h>
#include <controllers/moviesController.h>

#include <iostream>
using namespace std;

void actionMoviesListAddScreen(const char* title, int year, const char* genre, const char* director, int& result) {
    if (!title || !genre || !director) {
        return;
    }

    // api add movie
    result = addMovie(title, year, genre, director);
}

void formMoviesListAddScreen() {
    int result = 0;

    do {
        char* title = printTextField("Enter title:");
        int year = printNumberField("Enter year:");

        cin.ignore(); // discard newline character

        char* genre = printTextField("Enter genre:");
        char* director = printTextField("Enter director:");

        actionMoviesListAddScreen(title, year, genre, director, result);

        delete[] title;
        delete[] genre;
        delete[] director;
    } while (result < 0);

    // success
}

void renderMoviesListAddScreen() {
    printScreenHeader("Add new movie to IMDb -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    cin.ignore(); // discard newline character

    formMoviesListAddScreen();
}