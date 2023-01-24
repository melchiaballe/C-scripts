
#define MAX_PRODUCTS 3
#define GRAMS 64

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int SKU;
    double price;
    int calPerServing;
    double weightInPounds;
};

struct ReportData
{
    int SKU;
    double price;
    int calPerServing;
    double weightInPounds;
    double weightInKg;
    int grams;
    double totalServing;
    double totalCostPerServing;
    double costPerServing;
    double costCalPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* iPointer);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dPointer);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numSequence);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int SKU, const double* price, const int calPerServing, const double* weightInPounds);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* grams);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kg, int* grams);


// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGramsProduct, double* numberOfServing);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalNumServing, double* costPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalNumCalories, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo cFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rData, const int cheapestOption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cFoodInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);