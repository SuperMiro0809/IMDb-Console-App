#include <stringUtils.h>

#include <constants.h>
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