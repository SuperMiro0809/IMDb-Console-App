#include <ui-components.h>

#include <iostream>
#include <iomanip>
#include <console-utils.h>
using namespace std;

void printScreenHeader(const char* title, int titleColor, const char* subtitle, int subtitleColor) {
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
    setConsoleColor(textColor);
    cout << text << endl;
    resetConsoleColor();
}

void printScreenDivider(int length) {
    for (int i = 0; i < DEFAULT_DIVIDER_LENGTH; i++) {
        cout << DEFAULT_DIVIDER_CHAR;
    }
    cout << endl;
}