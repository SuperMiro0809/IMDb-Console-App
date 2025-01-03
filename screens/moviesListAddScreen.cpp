#include <screens/moviesListAddScreen.h>

#include <ui-components.h>
#include <colors.h>

#include <iostream>
using namespace std;

void formMoviesListAddScreen() {
    do {
        char* title = printTextField("Enter title:");
        int year = printNumberField("Enter year:");

        cin.ignore(); // discard newline character

        char* genre = printTextField("Enter genre:");
        char* director = printTextField("Enter director:");

        delete[] title;
        delete[] genre;
        delete[] director;
    } while (true);
}

void renderMoviesListAddScreen() {
    printScreenHeader("Add new movie to IMDb -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    cin.ignore(); // discard newline character

    formMoviesListAddScreen();
}