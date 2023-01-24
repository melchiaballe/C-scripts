#define _CRT_SECURE_NO_WARNINGS
#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70

#define MIN_LIVES 1
#define MAX_LIVES 10

#include <stdio.h>

struct PlayerInfo
{
    int numLives;
    char symbol;
    int numTreasures;
    int histort[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int maxMoves;
    int pathLength;
    int multipleOf;
    int bombs[MAX_PATH_LENGTH];
    int treasures[MAX_PATH_LENGTH];

};

int main(void)
{
    struct GameInfo gInfo = { 0, 0, 5, { 0 } , { 0 }};
    struct PlayerInfo pInfo = { 0 };
    int isValid = 0, i = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &pInfo.symbol);

    while (!isValid)
    {
        printf("Set the number of lives: ");
        scanf("%d", &pInfo.numLives);

        if(pInfo.numLives < MIN_LIVES || pInfo.numLives > MAX_LIVES)
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        else 
            isValid = 1;
        
    }
    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    isValid = 0;
    while (!isValid)
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", gInfo.multipleOf, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &gInfo.pathLength);

        if((gInfo.pathLength < MIN_PATH_LENGTH || gInfo.pathLength > MAX_PATH_LENGTH) || (gInfo.pathLength % gInfo.multipleOf != 0))
            printf("     Must be a multiple of %d and between %d-%d!!!\n", gInfo.multipleOf, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        else
            isValid = 1;
    }

    isValid = 0;
    while (!isValid)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gInfo.maxMoves);

        if(gInfo.maxMoves < pInfo.numLives || gInfo.maxMoves > (int)(gInfo.pathLength * .75))
            printf("    Value must be between %d and %d\n", pInfo.numLives, (int)(gInfo.pathLength * .75));
        else
        isValid = 1;
    }
    printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", gInfo.multipleOf);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gInfo.pathLength);

    for(i = 0; i < gInfo.pathLength; i = i + gInfo.multipleOf) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + gInfo.multipleOf);
        scanf("%d %d %d %d %d", &gInfo.bombs[i], &gInfo.bombs[i + 1], &gInfo.bombs[i + 2], &gInfo.bombs[i + 3], &gInfo.bombs[i + 4]);
    }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", gInfo.multipleOf);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gInfo.pathLength);

    for(i = 0; i < gInfo.pathLength; i = i + gInfo.multipleOf) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + gInfo.multipleOf);
        scanf("%d %d %d %d %d", &gInfo.treasures[i], &gInfo.treasures[i + 1], &gInfo.treasures[i + 2], &gInfo.treasures[i + 3], &gInfo.treasures[i + 4]);
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", pInfo.symbol);
    printf("   Lives      : %d\n", pInfo.numLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", gInfo.pathLength);
    printf("   Bombs      : ");
    for(i = 0; i < gInfo.pathLength; i++) {
        printf("%d", gInfo.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for(i = 0; i < gInfo.pathLength; i++) {
        printf("%d", gInfo.treasures[i]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}
