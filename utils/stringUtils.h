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

#pragma once

constexpr char TERMINATE_SYMBOL = '\0';

unsigned int charToDigit(char ch);

unsigned int myAtoi(const char* str);

char* substringBeforeSymbol(const char* str, char symbol);

char* getColumn(const char* str, int columnIndex);

int myStrCmp(const char* first, const char* second);

int getStringLength(const char* str);

bool isPrefix(const char* pattern, const char* text);

bool searchInText(const char* text, const char* pattern);
