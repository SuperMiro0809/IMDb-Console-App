#include <ui-components.h>

#include <iomanip>
#include <utils/consoleUtils.h>

#include <iostream>
using namespace std;

void printScreenHeader(const char* title, int titleColor, const char* subtitle, int subtitleColor) {
    if (!title || !subtitle) {
        return;
    }

    setConsoleColor(titleColor);
    cout << "*******************************" << endl;
    cout << setw(DEFAULT_HEADER_LEFT_MARGIN) << "" << title << endl;

    setConsoleColor(subtitleColor);
    cout << setw(DEFAULT_HEADER_LEFT_MARGIN) << "" << subtitle << endl;

    setConsoleColor(titleColor);
    cout << "*******************************" << endl;
    cout << endl;

    resetConsoleColor();
}

void printScreenText(const char* text, int textColor) {
    if (!text) {
        return;
    }

    setConsoleColor(textColor);
    cout << text << endl;
    resetConsoleColor();
}

void printScreenDivider(int length) {
    for (int i = 0; i < length; i++) {
        cout << DEFAULT_DIVIDER_CHAR;
    }
    cout << endl;
}

char* printTextField(const char* prompt, int textColor) {
    if (!prompt) {
        return nullptr;
    }

    char* input = new char[DEFAULT_TEXT_FIELD_LENGTH];

    printScreenText(prompt, textColor);
    cin.getline(input, DEFAULT_TEXT_FIELD_LENGTH);

    return input;
}

int printNumberField(const char* prompt, int textColor) {
    if (!prompt) {
        return -1;
    }

    int number;

    printScreenText(prompt, textColor);
    cin >> number;

    return number;
}

char** printActorsField(int actorsCount, int textColor) {
    char** actors = new char*[actorsCount];

    for (int i = 0; i < actorsCount; i++) {
        actors[i] = new char[DEFAULT_TEXT_FIELD_LENGTH];

        printScreenText("Enter name for author :", textColor);
        
        if (i == 0) {
            cin.ignore(); // discard newline character only at first index
        }

        cin.getline(actors[i], DEFAULT_TEXT_FIELD_LENGTH);
    }

    return actors;
}

void printUserInfo(const char* username, const char* role) {
    if (!username || !role) {
        return;
    }

    cout << "Welcome back, ";
    setConsoleColor(PRIMARY_YELLOW_COLOR);
    cout << username << "! ";

    resetConsoleColor();

    cout << "Logged as: ";
    setConsoleColor(PRIMARY_YELLOW_COLOR);
    cout << role << endl;
    resetConsoleColor();
}

void printMoviesTable(const movieType* movies, int length) {
    if (!movies) {
        return;
    }

    cout << endl;

    // print the table header
    cout << setw(DEFAULT_TABLE_ID_COLUMN_SIZE) << left << "ID"
         << setw(DEFAULT_TABLE_COLUMN_SIZE) << left << "Title"
         << setw(DEFAULT_TABLE_COLUMN_SIZE) << left << "Year"
         << setw(DEFAULT_TABLE_COLUMN_SIZE) << left << "Genre" << endl;

    printScreenDivider(80);

    for (int i = 0; i < length; i++) {
        cout << setw(DEFAULT_TABLE_ID_COLUMN_SIZE) << left << movies[i].id
             << setw(DEFAULT_TABLE_COLUMN_SIZE) << left << movies[i].title
             << setw(DEFAULT_TABLE_COLUMN_SIZE) << left << movies[i].year
             << setw(DEFAULT_TABLE_COLUMN_SIZE) << left << movies[i].genre << endl;

        cout << setw(DEFAULT_TABLE_ID_COLUMN_SIZE) << ""
             << "Director: " << movies[i].director << endl;

        cout << setw(DEFAULT_TABLE_ID_COLUMN_SIZE) << ""
             << "Actors: ";
        
        for (int j = 0; j < movies[i].actorsCount; j++) {
            cout << movies[i].actors[j];

            if (j != movies[i].actorsCount - 1) {
                cout << ", ";
            }
        }

        cout << endl;
        printScreenDivider(80);
    }

    cout << endl;
}

void printRouteParams(routeParamsType routeParams) {
    cout << endl;

    if (routeParams.searchTitle) {
        cout << "Search title query: " << routeParams.searchTitle << endl;
    }

    if (routeParams.searchGenre) {
        cout << "Search genre query: " << routeParams.searchGenre << endl;
    }

    if (routeParams.sortTitle) {
        cout << "Sort title direction: " << routeParams.sortTitle << endl;
    }

    cout << endl;
}
