#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptr) {

    int number;

    do {
        scanf("%d",&number);
        if (number < 1) printf("ERROR: Enter a positive value: ");

    } while (number < 1);

    if (ptr != NULL) *ptr = number;
    return number;
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptr) {

    double number;

    do {
        scanf("%lf",&number);
        if (number < 1.0) printf("ERROR: Enter a positive value: ");

    } while (number < 1.0);

    if (ptr != NULL) *ptr = number;
    return number;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(void) {

    printf("Cat Food Cost Analysis\n======================\n\n");
    printf("Enter the details for 3 dry food bags of product data for analysis.\nNOTE: A 'serving' is %d\n",
        SUGGESTED_GRAMS);
}
// 4. Get user input for the details of cat food product
void getCatFoodInfo(struct CatFoodInfo catFoodInfo[MAX_PRODS], const int size) {

    for (int i = 0; i < size; i++) {

        printf("\nCat Food Product #%d\n--------------------\n", i + 1);
        printf("SKU           : ");
        getIntPositive(&catFoodInfo[i].product_sku);
        printf("PRICE         : $");
        getDoublePositive(&catFoodInfo[i].product_price);
        printf("WEIGHT (LBS)  : ");
        getDoublePositive(&catFoodInfo[i].product_weight);
        printf("CALORIES/SERV.: ");
        getIntPositive(&catFoodInfo[i].calories_suggested_serving);
    }
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}
// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double price, double lbs, int calories) {

    printf("%07d %10.2lf %10.1lf %8d\n", sku, price, lbs, calories);
}
// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *lbs, double *kgs) {

    const double result = *lbs / KG_UNIT_VALUE;

    if (kgs != NULL) *kgs = result;

    return result;
}
// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *lbs, int *grams) {

    const double kg = convertLbsKg(lbs, NULL);

    const int result = (int)(kg * 1000.0);

    if (grams != NULL) *grams = result;

    return result;
}
// 10. convert lbs: kg and g
void convertLbs(const double *lbs, double *kgs, int *grams) {

    const double kg = convertLbsKg(lbs, NULL);
    if (kgs != NULL) *kgs = kg;

    const int grams_result = convertLbsG(lbs, NULL);
    if (grams != NULL) *grams = grams_result;
}
// 11. calculate: servings based on gPerServ
double calculateServings(const int serving_size_grams, const int total_grams, double *result) {

    double total_servings = (double)total_grams / serving_size_grams;

    if (result != NULL) *result = total_servings;

    return total_servings;
}
// 12. calculate: cost per serving
double calculateCostPerServing(const double *product_price, const double *total_servings, double *result) {

    const double price = *product_price;
    const double servings = *total_servings;
    const double cost_per_serving = price / servings;

    if (result != NULL) *result = cost_per_serving;

    return cost_per_serving;
}
// 13. calculate: cost per calorie
double calculateCostPerCal(const double *product_price, const double *total_calories, double *result) {

    const double price = *product_price;
    const double calories = *total_calories;
    const double cost_per_cal = price / calories;

    if (result != NULL) *result = cost_per_cal;

    return cost_per_cal;
}
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo product_data) {

    struct ReportData report_data;

    report_data.product_sku = product_data.product_sku;
    report_data.product_price = product_data.product_price;
    report_data.calories_suggested_serving = product_data.calories_suggested_serving;
    report_data.product_weight_lbs = product_data.product_weight;
    report_data.product_weight_kgs = convertLbsKg(&report_data.product_weight_lbs, NULL);
    report_data.product_weight_grams = convertLbsG(&report_data.product_weight_lbs, NULL);
    report_data.total_servings = calculateServings(SUGGESTED_GRAMS,
        report_data.product_weight_grams, NULL);
    report_data.cost_per_serving = calculateCostPerServing(&report_data.product_price, &report_data.total_servings,
        NULL);

    double total_calories = product_data.calories_suggested_serving * report_data.total_servings;

    report_data.calories_cost_per_serving = calculateCostPerCal(&report_data.product_price,
        &total_calories, NULL);

    return report_data;
}
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", SUGGESTED_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}
// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report_data, const int is_cheapest_option) {

    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report_data.product_sku,
        report_data.product_price, report_data.product_weight_lbs, report_data.product_weight_kgs,
        report_data.product_weight_grams, report_data.calories_suggested_serving,
        report_data.total_servings, report_data.cost_per_serving, report_data.calories_cost_per_serving);
    if (is_cheapest_option != 0) printf(" ***");
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo product_data) {

    printf("\nFinal Analysis\n--------------\nBased on the comparison data, the PURRR-fect economical option is:");
    printf("\nSKU: %07d Price: $%.2lf\n\n", product_data.product_sku, product_data.product_price);
    printf("Happy shopping!\n");
}
// ----------------------------------------------------------------------------
// 17. Logic entry point
void start(void) {

    struct CatFoodInfo cat_food_info[MAX_PRODS] = {0};
    struct ReportData report_data[MAX_PRODS] = {0};
    double cheapest_product_arr[MAX_PRODS] = {0};

    openingMessage();
    getCatFoodInfo(cat_food_info, MAX_PRODS);
    displayCatFoodHeader();

    for (int i = 0; i < MAX_PRODS; i++) {
        displayCatFoodData(cat_food_info[i].product_sku, cat_food_info[i].product_price,
            cat_food_info[i].product_weight, cat_food_info[i].calories_suggested_serving);

        report_data[i] = calculateReportData(cat_food_info[i]);
        cheapest_product_arr[i] = report_data[i].calories_cost_per_serving;
    }
    double cheapest_product = cheapest_product_arr[0];

    for (int i = 1; i < MAX_PRODS; i++) {

        if (cheapest_product_arr[i] < cheapest_product) cheapest_product = cheapest_product_arr[i];
    }
    displayReportHeader();

    for (int i = 0; i < MAX_PRODS; i++) {
        if (report_data[i].calories_cost_per_serving == cheapest_product) displayReportData(report_data[i],
            1);
        else { displayReportData(report_data[i], 0);  }
        printf("\n");
    }
    for (int i = 0; i < MAX_PRODS; i++) {
        if (report_data[i].calories_cost_per_serving == cheapest_product) displayFinalAnalysis(cat_food_info[i]);
    }
}
