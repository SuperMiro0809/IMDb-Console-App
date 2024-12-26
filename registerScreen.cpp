#include <registerScreen.h>

#include <ui-components.h>
#include <constants.h>

#include <iostream>
using namespace std;

void actionRegisterPage() {
    // validate

    // api register

    // retrive user id

    // navigate
}

void renderRegisterScreen() {
    char* username = new char[DEFAULT_TEXT_FIELD_LENGTH];
    char* password = new char[DEFAULT_TEXT_FIELD_LENGTH];
    char* repeatPassword = new char[DEFAULT_TEXT_FIELD_LENGTH];

    printScreenHeader("Register to IMDb -", 93, "Internet Movie Database!", 33);

    cin.ignore(); // discard newline character

    printScreenText("Enter username:");
    cin.getline(username, DEFAULT_TEXT_FIELD_LENGTH);

    printScreenText("Enter password:");
    cin.getline(password, DEFAULT_TEXT_FIELD_LENGTH);

    printScreenText("Repeat password:");
    cin.getline(repeatPassword, DEFAULT_TEXT_FIELD_LENGTH);

    actionRegisterPage();

    delete[] username;
    delete[] password;
    delete[] repeatPassword;
}