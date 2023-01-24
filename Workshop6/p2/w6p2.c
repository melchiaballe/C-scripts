#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double minimum = 500.00, maximum = 400000.00;
    int ids[10];
    int priority[10];
    double cost[10];
    char financed[10];
    double income = 0.00, totalIncome = 0.00, totalByPriority = 0.00;
    int isValid = 0, isPriorityValid = 0, hasFinancing = 0, priorityFilter = 0, forecast = 0, 
    i = 0, selection = 0, yearsToPay = 0, monthsToPay = 0;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    while (!isValid)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);

        if(income < minimum) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", minimum);
        } else if(income > maximum) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", maximum);
        } else {
            isValid = 1;
        }

        printf("\n");
    }


    isValid = 0;
    while (!isValid)
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &forecast);

        if(forecast < 1 || forecast > 10) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        } else {
            isValid = 1;
        }
        
        printf("\n");
    }

    for(i = 0; i < forecast; i++) {
        ids[i] = i + 1;
        printf("Item-%d Details:\n", i + 1);

        isValid = 0;
        while (!isValid)
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if(cost[i] < 100) {
                printf("      ERROR: Cost must be at least $100.00\n");
            } else {
                totalIncome += cost[i];
                isValid = 1;
            }
        }

        isValid = 0;
        while (!isValid)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if(priority[i] > 3 || priority[i] < 1) {
                printf("      ERROR: Value must be between 1 and 3\n");
            } else {
                isValid = 1;
            }
        }

        isValid = 0;
        while (!isValid)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financed[i]);

            if(financed[i] == 'y' || financed[i] == 'n') {
                isValid = 1;
            } else {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        }

        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    for(i = 0; i < forecast; i++) {
        printf("%3d  %5d    %5c    %11.2lf\n", ids[i], priority[i], financed[i], cost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalIncome);

    isValid = 0;
    while (!isValid)
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");

        if(selection < 0 || selection > 2) {
            printf("ERROR: Invalid menu selection.\n\n");
        } else {
            hasFinancing = 0;
            totalByPriority = 0.00;
            if(selection == 1) {
                printf("====================================================\n");
                printf("Filter:   All items\n");
                printf("Amount:   $%1.2lf\n", totalIncome);
                yearsToPay = (int)totalIncome / (income * 12);
                // added + 0.9 to the formula since if there are remaining days we have to round it off to a month
                monthsToPay = (int)(((totalIncome - ((income * 12) * yearsToPay)) / income) + 0.9);
                printf("Forecast: %d years, %d months\n", yearsToPay, monthsToPay);
                
                for(i = 0; i < forecast; i++) {
                    if(financed[i] == 'y') {
                        hasFinancing = 1;
                    }
                }

                if(hasFinancing) {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }

                printf("====================================================\n\n");
            } else if(selection == 2) {

                isPriorityValid = 0;

                while (!isPriorityValid)
                {
                    printf("What priority do you want to filter by? [1-3]: ");
                    scanf("%d", &priorityFilter);
                    printf("\n");

                    if(priorityFilter < 1 || priorityFilter > 3) {
                        printf("ERROR: Invalid menu selection.\n\n");
                    } else {
                        isPriorityValid = 1;
                    }
                }

                for(i = 0; i < forecast; i++) {
                    if(priority[i] == priorityFilter) {
                        totalByPriority += cost[i];
                        if(financed[i] == 'y') {
                            hasFinancing = 1;
                        }
                    }
                }

                yearsToPay = (int)totalByPriority / (income * 12);
                // added + 0.9 to the formula since if there are remaining days we have to round it off to a month
                monthsToPay = (int)(((totalByPriority - ((income * 12) * yearsToPay)) / income) + 0.9);

                printf("====================================================\n");
                printf("Filter:   by priority (%d)\n", priorityFilter);
                printf("Amount:   $%1.2lf\n", totalByPriority);
                printf("Forecast: %d years, %d months\n", yearsToPay, monthsToPay);

                if(hasFinancing) {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }

                printf("====================================================\n\n");
            } else {
                isValid = 1;
            }
        }
    }
    printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}