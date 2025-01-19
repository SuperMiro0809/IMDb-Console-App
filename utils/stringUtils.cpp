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
* <Definition of String Utility functions>
*
*/

#include <utils/stringUtils.h>

#include <global/constants.h>
#include <iostream>
using namespace std;

unsigned int charToDigit(char ch) {
    if (ch < '0' || ch > '9') return 0;

    return ch - '0';
}

unsigned int myAtoi(const char* str) {
    if (!str) return 0;

    unsigned result = 0;

    while (*str != TERMINATE_SYMBOL) {
        if (*str < '0' || *str > '9') {
            return 0;
        }

        result = result * 10 + charToDigit(*str);
        str++;
    }

    return result;
}

char* substringBeforeSymbol(const char* str, char symbol) {
    if (!str) {
        return nullptr;
    }

    int length = 0;
    while (str[length] != TERMINATE_SYMBOL && str[length] != symbol) {
        length++;
    }

    char* result = new char[length + 1]; // +1 for terminate symbol

    for (int i = 0; i < length; i++) {
        result[i] = str[i];
    }

    result[length] = TERMINATE_SYMBOL;
    return result;
}

char* getColumn(const char* str, int columnIndex) {
    if (!str) {
        return nullptr;
    }

    char* columnValue = new char[100];
    int currColumnIndex = 0;
    int index = 0;

    while (*str != TERMINATE_SYMBOL) {
        if (*str == DEFAULT_DB_DELIMITER) {
            currColumnIndex++;
        } else {
            if (currColumnIndex == columnIndex) {
                columnValue[index] = *str;
                index++;
            } else if (currColumnIndex > columnIndex) {
                break; // we finished reading column
            }
        }

        str++;
    }

    return columnValue;
}

int myStrCmp(const char* first, const char* second) {
    if (!first || !second) return 0;

    while(*first != TERMINATE_SYMBOL && *first == *second) {
        first++;
        second++;
    }

    return *first - *second;
}

int getStringLength(const char* str) {
    if (!str) {
        return 0;
    }

    int length = 0;
    while (*str != TERMINATE_SYMBOL) {
        length++;
        str++;
    }

    return length;
}

bool isPrefix(const char* pattern, const char* text) {
    if (!pattern || !text) return 0;

    while (*pattern != TERMINATE_SYMBOL) {
        if (*pattern != *text) {
            return false;
        }

        pattern++;
        text++;
    }

    return true;
}

bool searchInText(const char* text, const char* pattern) {
    if (!text || !pattern) return 0;

    while (*text != TERMINATE_SYMBOL) {
        if (isPrefix(pattern, text)) {
            return true;
        }

        text++;
    }
    
    return false;
}
