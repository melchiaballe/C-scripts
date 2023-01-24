#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* iPointer) {
	// placeholder for integer
	int placeholder = 0;
	// loop to get positive integer value
	while (placeholder < 1) {
		// user input for integer
		scanf("%d", &placeholder);
		// flag to check for loop continuation
		if (placeholder < 1) {
			printf("ERROR: Enter a positive value: ");
		}
	}

	// if pointer is not NULL or an address has been given
	if (iPointer != NULL) {
		// change the pointer value 
		*iPointer = placeholder;
	}
	
	// return to function call
	return placeholder;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dPointer) 
{
	double placeholder = 0;
	while (placeholder < 1) { 
		scanf("%lf", &placeholder);

		if (placeholder < 1) {
			printf("ERROR: Enter a positive value: ");
		}
	}

	if (dPointer != NULL) {
		*dPointer = placeholder;
	}
		
	return placeholder;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProducts) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", numOfProducts);
	printf("NOTE: A 'serving' is %dg\n\n", GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numSequence){
	struct CatFoodInfo tempInfo = { 0 };
	printf("Cat Food Product #%d\n", (numSequence + 1));
	printf("--------------------\n");

	printf("SKU           : ");
	tempInfo.SKU = getIntPositive(&tempInfo.SKU);
	printf("PRICE         : $");
	tempInfo.price = getDoublePositive(&tempInfo.price);
	printf("WEIGHT (LBS)  : ");
	tempInfo.weightInPounds = getDoublePositive(&tempInfo.weightInPounds);
	printf("CALORIES/SERV.: ");
	tempInfo.calPerServing = getIntPositive(&tempInfo.calPerServing);
	printf("\n");
	return tempInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void) {
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int SKU, const double* price, const int calPerServing, const double* weightInPounds) {
	printf("%07d %10.2lf %10.1lf %8d\n", SKU, *price, *weightInPounds, calPerServing);
}

// 7. Logic entry point
void start(void) {
	int i = 0;
	struct CatFoodInfo cFoodInfo[MAX_PRODUCTS] = { { 0 } };

	openingMessage(MAX_PRODUCTS);
	for(i = 0; i < MAX_PRODUCTS; i++) {
		cFoodInfo[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for(i = 0; i < MAX_PRODUCTS; i++) {
		displayCatFoodData(cFoodInfo[i].SKU, &cFoodInfo[i].price, cFoodInfo[i].calPerServing, &cFoodInfo[i].weightInPounds);
	}
	printf("\n");

}