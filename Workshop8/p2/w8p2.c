
#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"


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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg) {

	const double lbsToKg = 2.20462;

	double placeholder = 0.00;

	placeholder = (*lbs / lbsToKg);

	if (kg != NULL) {
		*kg = placeholder;
	}
		
	return placeholder;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* grams) {
    int placeholder = 0.00;

	placeholder = (convertLbsKg(lbs, NULL) * 1000);

	if (grams != NULL) {
		*grams = placeholder;
	}
		
	return placeholder;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kg, int* grams) {
    convertLbsKg(lbs, kg);
	convertLbsG(lbs, grams);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGramsProduct, double* numberOfServing) {
	double placeholder = 0.00;

	placeholder = ((double)totalGramsProduct / (double)servingSizeGrams);

	if (numberOfServing != NULL) {
		*numberOfServing = placeholder;
	}

	return placeholder;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalNumServing, double* costPerServing) {
	double placeholder = 0.00;

	placeholder = (*productPrice / *totalNumServing);

	if (costPerServing != NULL) {
		*costPerServing = placeholder;
	}

	return placeholder;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalNumCalories, double* costPerCal) {
	double placeholder = 0.00;

	placeholder = (*productPrice / *totalNumCalories);

	if (costPerCal != NULL) {
		*costPerCal = placeholder;
	}

	return placeholder;
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo cFoodInfo) {
	struct ReportData tempInfo = { 0 };
	
	tempInfo.SKU = cFoodInfo.SKU;
	tempInfo.price = cFoodInfo.price;
	tempInfo.calPerServing = cFoodInfo.calPerServing;
	tempInfo.weightInPounds = cFoodInfo.weightInPounds;

	tempInfo.weightInKg = convertLbsKg(&tempInfo.weightInPounds, NULL);
	tempInfo.grams = convertLbsG(&tempInfo.weightInPounds, NULL);
	tempInfo.totalServing = calculateServings(GRAMS, tempInfo.grams, NULL);
	double totalCalorie = (tempInfo.calPerServing * tempInfo.totalServing);
	tempInfo.costCalPerServing = calculateCostPerCal(&tempInfo.price, &totalCalorie, NULL);
	tempInfo.costPerServing = calculateCostPerServing(&tempInfo.price, &tempInfo.totalServing, NULL);

	return tempInfo;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rData, const int cheapestOption) {
	if(rData.SKU == cheapestOption) {
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", rData.SKU, rData.price, rData.weightInPounds, rData.weightInKg, rData.grams, rData.calPerServing, rData.totalServing, rData.costPerServing, rData.costCalPerServing);
	} else {
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", rData.SKU, rData.price, rData.weightInPounds, rData.weightInKg, rData.grams, rData.calPerServing, rData.totalServing, rData.costPerServing, rData.costCalPerServing);
	}
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cFoodInfo) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", cFoodInfo.SKU, cFoodInfo.price);
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void) {
	int i = 0, comparisonVal = -1, cheapestSKU = 0;
	struct CatFoodInfo cFoodInfo[MAX_PRODUCTS] = { { 0 } };
	struct ReportData rData[MAX_PRODUCTS] = { { 0 } };
	

	openingMessage(MAX_PRODUCTS);
	for(i = 0; i < MAX_PRODUCTS; i++) {
		cFoodInfo[i] = getCatFoodInfo(i);
		rData[i] = calculateReportData(cFoodInfo[i]);

		if(comparisonVal != -1) {
			if (rData[i].costCalPerServing < rData[comparisonVal].costCalPerServing) {
				comparisonVal = i;
			}
		} else {
			comparisonVal = i;
		}
	}
	cheapestSKU = rData[comparisonVal].SKU;

	displayCatFoodHeader();
	for(i = 0; i < MAX_PRODUCTS; i++) {
		displayCatFoodData(cFoodInfo[i].SKU, &cFoodInfo[i].price, cFoodInfo[i].calPerServing, &cFoodInfo[i].weightInPounds);
	}
	printf("\n");

	displayReportHeader();
	for(i = 0; i < MAX_PRODUCTS; i++) {
		displayReportData(rData[i], cheapestSKU);
	}
	printf("\n");

	displayFinalAnalysis(cFoodInfo[comparisonVal]);

}