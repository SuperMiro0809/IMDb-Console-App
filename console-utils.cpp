#include <iostream>
#include <console-utils.h>
using namespace std;

void setConsoleColor(int textColor) {
    cout << "\033[" << textColor << "m";
}

void resetConsoleColor() {
    cout << "\033[" << DEFAULT_COLOR << "m";
}
