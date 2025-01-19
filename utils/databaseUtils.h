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
* <Definition of Database Utility functions>
*
*/

#pragma once

int autoIncrement(const char* dbName);

void deleteRecord(const char* dbName, int queryId, int queryColumn);
