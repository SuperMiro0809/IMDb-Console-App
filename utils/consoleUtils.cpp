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
* <Definition of Console Utility functions>
*
*/

#include <utils/consoleUtils.h>

#include <global/colors.h>

#include <iostream>
using namespace std;

void setConsoleColor(int textColor) {
    cout << "\033[" << textColor << "m";
}

void resetConsoleColor() {
    cout << "\033[" << DEFAULT_COLOR << "m";
}
