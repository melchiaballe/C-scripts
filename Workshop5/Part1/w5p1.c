
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2012
#define MAX_YEAR 2022

#include <stdio.h>

int main(void)
{
    int JAN = 1, DEC = 12, inputYear = 0, inputMonth = 0, dayInMonth = 1, isCompleted = 0;


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

    printf("Log starting date: %d-", inputYear);

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

    dayInMonth < 10 ? printf("0%d\n", dayInMonth) : printf("%d\n", dayInMonth);

    return 0;
}