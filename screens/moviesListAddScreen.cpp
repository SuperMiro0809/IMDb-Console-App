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
* <Movies List Add Screen>
*
*/

#include <screens/moviesListAddScreen.h>

#include <global/uiComponents.h>
#include <global/colors.h>
#include <global/routes.h>
#include <controllers/moviesController.h>

#include <iostream>
using namespace std;

void actionMoviesListAddScreen(const char* title, int year, const char* genre, const char* director, const char* const* actors, int actorsCount, int& result) {
    if (!title || !genre || !director || !actors) {
        return;
    }

    // api add movie
    result = addMovie(title, year, genre, director, actors, actorsCount);
}

int formMoviesListAddScreen() {
    int result = 0;

    do {
        char* title = printTextField("Enter title:");
        int year = printNumberField("Enter year:");

        cin.ignore(); // discard newline character

        char* genre = printTextField("Enter genre:");
        char* director = printTextField("Enter director:");

        int actorsCount = printNumberField("How many actors:");

        char** actors = printActorsField(actorsCount);

        actionMoviesListAddScreen(title, year, genre, director, actors, actorsCount, result);

        delete[] title;
        delete[] genre;
        delete[] director;

        for (int i = 0; i < actorsCount; i++) {
            delete[] actors[i];
        }
        delete[] actors;
    } while (result < 0);

    // success - navigate back to Movies List
    return MOVIES_LIST_PAGE;
}

int renderMoviesListAddScreen() {
    printScreenHeader("Add new movie to IMDb -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    cin.ignore(); // discard newline character

    return formMoviesListAddScreen();
}