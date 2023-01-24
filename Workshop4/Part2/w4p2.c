
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples = 0, oranges = 0, pears = 0, tomatoes = 0, cabbages = 0,
    pickedApples = 0, pickedOrange = 0, pickedPears = 0, 
    pickedTomatoes = 0, pickedCabbages = 0, 
    anotherShopping = 0, tempPickedComparison = 0, isCompleted = 0;


    do {
        printf("Grocery Shopping\n");
        printf("================\n");

        do {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if(apples < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (apples <= -1);
        printf("\n");

        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if(oranges < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (oranges <= -1);
        printf("\n");

        do {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);

            if(pears < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (pears <= -1);
        printf("\n");

        do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);

            if(tomatoes < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (tomatoes <= -1);
        printf("\n");

        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if(cabbages < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (cabbages <= -1);
        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        if(apples != 0) {
            tempPickedComparison = apples;
            isCompleted = 0;
            do {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickedApples);

                if(pickedApples > apples || pickedApples > tempPickedComparison) {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", tempPickedComparison);
                } else if((pickedApples <= apples && pickedApples <= tempPickedComparison) &&  pickedApples > 0) {
                    tempPickedComparison -= pickedApples;
                    if(tempPickedComparison == 0)
                        printf("Great, that's the apples done!\n\n"), isCompleted = 1;
                    else
                        printf("Looks like we still need some APPLES...\n");
                } else {
                    printf("ERROR: You must pick at least 1!\n");
                }

            } while (isCompleted == 0);
        }

        if(oranges != 0) {
            tempPickedComparison = oranges;
            isCompleted = 0;
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickedOrange);

                if(pickedOrange > oranges || pickedOrange > tempPickedComparison) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", tempPickedComparison);
                } else if((pickedOrange <= oranges && pickedOrange <= tempPickedComparison) &&  pickedOrange > 0) {
                    tempPickedComparison -= pickedOrange;
                    if(tempPickedComparison == 0)
                        printf("Great, that's the oranges done!\n\n"), isCompleted = 1;
                    else
                        printf("Looks like we still need some ORANGES...\n");
                } else {
                    printf("ERROR: You must pick at least 1!\n");
                }

            } while (isCompleted == 0);
        }

        if(pears != 0) {
            tempPickedComparison = pears;
            isCompleted = 0;
            do {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickedPears);

                if(pickedPears > pears || pickedPears > tempPickedComparison) {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", tempPickedComparison);
                } else if((pickedPears <= pears && pickedPears <= tempPickedComparison) &&  pickedPears > 0) {
                    tempPickedComparison -= pickedPears;
                    if(tempPickedComparison == 0)
                        printf("Great, that's the pears done!\n\n"), isCompleted = 1;
                    else
                        printf("Looks like we still need some PEARS...\n");
                } else {
                    printf("ERROR: You must pick at least 1!\n");
                }

            } while (isCompleted == 0);
        }

        if(tomatoes != 0) {
            tempPickedComparison = tomatoes;
            isCompleted = 0;
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickedTomatoes);

                if(pickedTomatoes > tomatoes || pickedTomatoes > tempPickedComparison) {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tempPickedComparison);
                } else if((pickedTomatoes <= tomatoes && pickedTomatoes <= tempPickedComparison) &&  pickedTomatoes > 0) {
                    tempPickedComparison -= pickedTomatoes;
                    if(tempPickedComparison == 0)
                        printf("Great, that's the tomatoes done!\n\n"), isCompleted = 1;
                    else
                        printf("Looks like we still need some TOMATOES...\n");
                } else {
                    printf("ERROR: You must pick at least 1!\n");
                }

            } while (isCompleted == 0);
        }

        if(cabbages != 0) {
            tempPickedComparison = cabbages;
            isCompleted = 0;
            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickedCabbages);

                if(pickedCabbages > cabbages || pickedCabbages > tempPickedComparison) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", tempPickedComparison);
                } else if((pickedCabbages <= cabbages && pickedCabbages <= tempPickedComparison) &&  pickedCabbages > 0) {
                    tempPickedComparison -= pickedCabbages;
                    if(tempPickedComparison == 0)
                        printf("Great, that's the cabbages done!\n\n"), isCompleted = 1;
                    else
                        printf("Looks like we still need some CABBAGES...\n");
                } else {
                    printf("ERROR: You must pick at least 1!\n");
                }

            } while (isCompleted == 0);
        }

        printf("All the items are picked!\n\n");

        printf("Do another shopping? (0=NO): ");
        scanf("%d", &anotherShopping);
        printf("\n");

    } while (anotherShopping != 0);
    
    printf("Your tasks are done for today - enjoy your free time!\n\n");


    return 0;
}