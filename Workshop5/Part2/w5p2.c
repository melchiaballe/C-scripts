

#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

#include <stdio.h>

int main(void)
{
    int JAN = 1, DEC = 12, inputYear = 0, inputMonth = 0, isCompleted = 0, loopCounter = 1;
    double morning = 0.0, evening = 0.0, morningTotal = 0.0, eveningTotal = 0.0;

    printf("General Well-being Log\n");
    printf("======================\n");
    
    while (isCompleted == 0)
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &inputYear, &inputMonth);
        if((inputYear <= MAX_YEAR && inputYear >= MIN_YEAR) && (inputMonth >= JAN && inputMonth <= DEC)) {
            isCompleted = 1;
        } else {
            if(inputYear > MAX_YEAR || inputYear < MIN_YEAR) {
                printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            }

            if(inputMonth < JAN || inputMonth > DEC) {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
            }
        }
    }

    printf("\n*** Log date set! ***\n\n");

    for(loopCounter = 1; loopCounter <= LOG_DAYS; loopCounter++) {

        isCompleted = 0;
        printf("%d-", inputYear);

        switch (inputMonth)
        {
            case 1:
                printf("JAN-");
                break;
            case 2:
                printf("FEB-");
                break;
            case 3:
                printf("MAR-");
                break;
            case 4:
                printf("APR-");
                break;
            case 5:
                printf("MAY-");
                break;
            case 6:
                printf("JUN-");
                break;
            case 7:
                printf("JUL-");
                break;
            case 8:
                printf("AUG-");
                break;
            case 9:
                printf("SEP-");
                break;
            case 10:
                printf("OCT-");
                break;
            case 11:
                printf("NOV-");
                break;
            case 12:
                printf("DEC-");
                break;
            default:
                break;
        }

        loopCounter < 10 ? printf("0%d\n", loopCounter) : printf("%d\n", loopCounter);

        while (isCompleted == 0)
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morning);

            if (morning >= 0.00 && morning <= 5.0)
            {
                morningTotal += morning;
                isCompleted = 1;
            } else {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }

        isCompleted = 0;
        while (isCompleted == 0)
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evening);

            if (evening >= 0.00 && evening <= 5.0)
            {
                eveningTotal += evening;
                isCompleted = 1;
            } else {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }
        printf("\n");
    }

    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %6.3lf\n", morningTotal);
    printf("Evening total rating: %6.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n\n", (morningTotal + eveningTotal));

    printf("Average morning rating: %4.1lf\n", (morningTotal / LOG_DAYS));
    printf("Average evening rating: %4.1lf\n", (eveningTotal / LOG_DAYS));
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n\n", (((morningTotal / LOG_DAYS) + (eveningTotal / LOG_DAYS)) / 2));

    return 0;
}