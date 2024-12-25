#include <iostream>
#include <iomanip>
using namespace std;

constexpr int HEADER_LEFT_MARGIN = 3;

void setConsoleColor(int textColor) {
    cout << "\033[" << textColor << "m";
}

void resetConsoleColor() {
    cout << "\033[" << 0 << "m"; // 0 = default color
}

void printScreenHeader(const char* title, int titleColor, const char* subtitle, int subtitleColor) {
    setConsoleColor(titleColor);
    cout << "*******************************" << endl;
    cout << setw(HEADER_LEFT_MARGIN) << "" << title << endl;

    setConsoleColor(subtitleColor);
    cout << setw(HEADER_LEFT_MARGIN) << "" << subtitle << endl;

    setConsoleColor(titleColor);
    cout << "*******************************" << endl;
    cout << endl;

    resetConsoleColor();
}