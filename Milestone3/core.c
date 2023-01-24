#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "core.h"
#include "clinic.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

int inputInt(void) {
    int intValue = 0, isValid = 0;
    char charValue = ' ';

    while (!isValid)
    {
        scanf("%d%c", &intValue, &charValue);

        if(charValue != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        } else {
            isValid = 1;
        }
    }

    return intValue;
}

int inputIntPositive(void) {
    int intValue = 0, isValid = 0;
    char charValue = ' ';

    while (!isValid)
    {
        scanf("%d%c", &intValue, &charValue);

        if(charValue == '\n') {
            if (intValue < 0) {
                printf("ERROR! Value must be > 0: ");
            } else {
                isValid = 1;
            }
        } else {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }

    return intValue;
}

int inputIntRange(int lowerBound, int upperBound) {
    int intValue = 0, isValid = 0;
    char charValue = ' ';

    while (!isValid)
    {
        scanf("%d%c", &intValue, &charValue);

        if(charValue != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        } else {
            if (intValue < lowerBound || intValue > upperBound) {
                printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
            } else {
                isValid = 1;
            }
        }
    }
    return intValue;
}

char inputCharOption(char validCharacters[]) {
    int isValid = 0, i = 0;
    char charValue = ' ';

    isValid = 0;
    i = 0;
    while (!isValid)
    {
        scanf(" %c", &charValue);

        if (getchar() == '\n')
        {
            for (i = 0; i < strlen(validCharacters); i++)
            {
                if(charValue == validCharacters[i]) {
                    isValid = 1;
                }
            }
        } else {
            clearInputBuffer();
        }

        if (!isValid) {
            printf("ERROR: Character must be one of [%s]: ", validCharacters);
        }
        
    }

    return charValue;
}

void inputCString(char* charString, int min, int max, int isPhone) {
    char stringHolder[NAME_LEN + 1];
    int isValid = 0;
    
    while (!isValid)
    {
        scanf(" %[^\n]%*c", stringHolder);
        if(min == max) {
            if(strlen(stringHolder) != max) {
                if(isPhone) {
                    printf("Invalid %d-digit number! Number: ", max);
                } else {
                    printf("ERROR: String length must be exactly %d chars: ", max);
                }
            } else {
                isValid = 1;
            }
        } else {
            if (strlen(stringHolder) > max || strlen(stringHolder) < min) {
                
                if(strlen(stringHolder) > max ) {
                    printf("ERROR: String length must be no more than %d chars: ", max);
                } else {
                    printf("ERROR: String length must be between %d and %d chars: ", min, max);
                }
            } else {
                isValid = 1;
            }
        }
    }
    strcpy(charString, stringHolder);
}

void displayFormattedPhone(const char* charString) {
    int i = 0, count = 0;

    if (charString == NULL)
    {
        printf("(___)___-____");
    } else {
        for(i = 0; i < strlen(charString); i++)
        {
            if(charString[i] >= '0' && charString[i] <= '9')
            {
                count++;
            }
        }

        if (strlen(charString) != 10 || strlen(charString) != count) {
            printf("(___)___-____");
        } else {
            printf("(");
            for(i = 0; i < strlen(charString); i++)
            {
                if(i < 3) {
                    printf("%c", charString[i]);
                } else if (i == 3) {
                    printf(")%c", charString[i]);
                } else if (i > 3 && i < 6) {
                    printf("%c", charString[i]);
                } else if (i == 6) {
                    printf("-%c", charString[i]);
                } else {
                    printf("%c", charString[i]);
                }
            }
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

