#pragma once

#include <constants.h>

void printScreenHeader(const char* title, int titleColor, const char* subtitle, int subtitleColor);

void printScreenText(const char* text, int textColor = DEFAULT_COLOR);

void printScreenDivider(int length = DEFAULT_DIVIDER_LENGTH);

char* printTextField(const char* prompt, int textColor = DEFAULT_COLOR);

void printUserInfo(const char* username, const char* role);