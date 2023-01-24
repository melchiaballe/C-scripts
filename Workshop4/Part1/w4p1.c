
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int isQuitting = 0, iteratationVal = 0, counter = 0;
    char iterationOperation = 0;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    while (isQuitting == 0)
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &iterationOperation, &iteratationVal);


        if((iterationOperation == 'D' || iterationOperation == 'W' || iterationOperation == 'F') && 
        (iteratationVal >= 3 && iteratationVal <= 20)) {
            switch (iterationOperation)
            {
                case 'D':
                    printf("DO-WHILE: ");
                    do {
                        printf("D");
                        ++counter;
                    } while (counter < iteratationVal);
                    break;
                case 'W':
                    printf("WHILE   : ");
                    while (counter < iteratationVal)
                    {
                        printf("W");
                        counter++;
                    }
                    break;
                case 'F':
                    printf("FOR     : ");
                    for(counter = 0; counter < iteratationVal; counter++) {
                        printf("F");
                    }
                    break;
                default:
                    break;
            }
            counter = 0;
            printf("\n\n");
        } else {
            if ((iterationOperation == 'D' || iterationOperation == 'W' || iterationOperation == 'F') && 
            (iteratationVal > 20 || iteratationVal < 3)) {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            } else if (iterationOperation == 'Q' && iteratationVal == 0) {
                isQuitting = 1;
                printf("\n+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n\n");
            } else if (iterationOperation == 'Q' && iteratationVal != 0 ) {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            } else {
                printf("ERROR: Invalid entered value(s)!\n\n");
            }
        }

    }


    return 0;
}