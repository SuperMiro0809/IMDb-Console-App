#include <loginScreen.h>

#include <ui-components.h>
#include <constants.h>

#include <iostream>
using namespace std;

void actionLoginScreen() {
    // api login

    // check if success

    // retrieve user

    // navigate
}

void renderLoginScreen() {
    char* username = new char[DEFAULT_TEXT_FIELD_LENGTH];
    char* password = new char[DEFAULT_TEXT_FIELD_LENGTH];

    printScreenHeader("Login to IMDb -", 93, "Internet Movie Database!", 33);

    cin.ignore(); // discard newline character

    printScreenText("Enter username:");
    cin.getline(username, DEFAULT_TEXT_FIELD_LENGTH);

    printScreenText("Enter password:");
    cin.getline(password, DEFAULT_TEXT_FIELD_LENGTH);

    cout << "Username: " << username <<endl;
    cout << "Password: " << password <<endl;

    actionLoginScreen();

    delete[] username;
    delete[] password;
}