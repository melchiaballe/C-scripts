
#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    // product ids
    const int p1Id = 111;
    const int p2Id = 222;
    const int p3Id = 111;

    // prices per product
    const double p1Price = 111.49;
    const double p2Price = 222.99;
    const double p3Price = 334.49;

    const double pAverage = (p1Price + p2Price + p3Price) / 3;

    // bool variable 1 = True and 0 = False
    const int p1Taxed = 1;
    const int p2Taxed = 0;
    const int p3Taxed = 0;


    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", p1Id);
    printf("  Taxed: %c\n", p1Taxed > 0 ? 'Y' : 'N');
    printf("  Price: $%.4lf\n", p1Price);
    printf("Product-2 (ID:%d)\n", p2Id);
    printf("  Taxed: %c\n", p2Taxed > 0 ? 'Y' : 'N');
    printf("  Price: $%.4lf\n", p2Price);
    printf("Product-3 (ID:%d)\n", p3Id);
    printf("  Taxed: %c\n", p3Taxed > 0 ? 'Y' : 'N');
    printf("  Price: $%.4lf\n\n", p3Price);
    printf("The average of all prices is: $%.4lf\n\n", pAverage);

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");


    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", p1Taxed);
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", (p2Taxed == 0 && p3Taxed == 0) ? 1 : 0);
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue , (p3Price < testValue) ? 1 : 0);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", (p3Price > (p1Price + p2Price)) ? 1 : 0);
    printf("5. Is the price of product 1 equal to or more than the price difference of product 3 LESS product 2? -> %d (price difference: $%.2lf)\n\n", 
    (p1Price >= (p3Price - p2Price)) ? 1 : 0, (p3Price - p2Price));
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", p2Price >= pAverage ? 1 : 0);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", (p1Id != p2Id && p1Id != p3Id) ? 1 : 0);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", (p2Id != p1Id && p2Id != p3Id) ? 1 : 0);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", (p3Id != p1Id && p3Id != p2Id) ? 1 : 0);


    return 0;
}