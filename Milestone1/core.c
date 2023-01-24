#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
#include <string.h>

// User Libraries
#include "core.h"


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

        for (i = 0; i < stringLen(validCharacters); i++)
        {
            if(charValue == validCharacters[i]) {
                isValid = 1;
            }
        }

        if (!isValid) {
            printf("ERROR: Character must be one of [%s]: ", validCharacters);
        }
        
    }

    return charValue;
}

void inputCString(char* charString, int min, int max) {
    int isValid = 0;
    
    while (!isValid)
    {
        clearInputBuffer();
        scanf("%[^\n]", charString);
        if(min == max) {
            if(stringLen(charString) != max) {
                printf("ERROR: String length must be exactly %d chars: ", max);
            } else {
                isValid = 1;
            }
        } else {
            if (stringLen(charString) > max || stringLen(charString) < min) {
                
                if(stringLen(charString) > max ) {
                    printf("ERROR: String length must be no more than %d chars: ", max);
                } else {
                    printf("ERROR: String length must be between %d and %d chars: ", min, max);
                }
            } else {
                isValid = 1;
            }
        }
    }
}

void displayFormattedPhone(const char* charString) {
    int i = 0, count = 0;

    if (charString == NULL)
    {
        printf("(___)___-____");
    } else {
        for(i = 0; i < stringLen(charString); i++)
        {
            if(charString[i] >= '0' && charString[i] <= '9')
            {
                count++;
            }
        }

        if (stringLen(charString) != 10 || stringLen(charString) != count) {
            printf("(___)___-____");
        } else {
            printf("(");
            for(i = 0; i < stringLen(charString); i++)
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

int stringLen(const char* charPointer)
{
  int count = 0;
  while(*charPointer != '\0')
  {
      count++;
      charPointer++;
  }
  return count;
}