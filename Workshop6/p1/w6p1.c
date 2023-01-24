#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double minimum = 500.00, maximum = 400000.00;
    int ids[10];
    int priority[10];
    double cost[10];
    char financed[10];
    double income = 0.00, totalIncome = 0.00;
    int isValid = 0, forecast = 0, i = 0;

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


    // part 4
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    for(i = 0; i < forecast; i++) {
        printf("%3d  %5d    %5c    %11.2lf\n", ids[i], priority[i], financed[i], cost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalIncome);


    printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}