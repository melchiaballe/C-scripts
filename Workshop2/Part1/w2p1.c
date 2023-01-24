#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';

    double container = 0.00;
    int smallPrice = 0, mediumPrice = 0, largePrice = 0, subTotal = 0, 
        totalTax = 0, totalAmount = 0, numOfShirtToPurchase = 0;


    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &container);
    smallPrice = container * 100;
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &container);
    mediumPrice = container * 100;
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &container);
    largePrice = container * 100;

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", (double)smallPrice / 100);
    printf("MEDIUM : $%.2lf\n", (double)mediumPrice / 100);
    printf("LARGE  : $%.2lf\n", (double)largePrice / 100);

    printf("\nPatty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numOfShirtToPurchase);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", numOfShirtToPurchase);
    
    // subTotal = (int)((((double)smallPrice / 100) * numOfShirtToPurchase) * 100);
    // totalTax = (int)((((double)subTotal / 100) * TAX) * 100);

    subTotal = (int)((float)(((((double)smallPrice / 100) * numOfShirtToPurchase) * 100) + .5));
    totalTax = (int)((float)(((((double)subTotal / 100) * TAX) * 100) + .5));
    
    totalAmount = subTotal + totalTax;
    printf("Sub-total: $%8.4lf\n", (double)subTotal / 100);
    printf("Taxes    : $%8.4lf\n", (double)totalTax / 100);
    printf("Total    : $%8.4lf\n\n", (double)totalAmount / 100);

    return 0;
}