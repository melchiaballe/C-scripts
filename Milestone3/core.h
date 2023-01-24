// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Gets any integer value
int inputInt(void);

// Gets only positive integer
int inputIntPositive(void);

// Gets a number within the range of lower and upper bound
int inputIntRange(int lowerBound, int upperBound);

// Gets a character within the string provided
char inputCharOption(char validCharacters[]);

// Get a string value based on min and max number of characters and proper error message for phone and string
void inputCString(char* charString, int min, int max, int isPhone);

// Shows a formatted version of the phone number character string
void displayFormattedPhone(const char* charString);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
