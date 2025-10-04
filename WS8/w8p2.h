#ifndef W8P2_H
#define W8P2_H
#define MAX_PRODS 3
#define SUGGESTED_GRAMS 64
#define KG_UNIT_VALUE 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo {
    int product_sku;
    double product_price;
    int calories_suggested_serving;
    double product_weight;
};
struct ReportData {
    int product_sku;
    double product_price;
    int calories_suggested_serving;
    double product_weight_lbs;
    double product_weight_kgs;
    int product_weight_grams;
    double total_servings;
    double cost_per_serving;
    double calories_cost_per_serving;
};
// ----------------------------------------------------------------------------
// function prototypes

int getIntPositive(int *ptr);
double getDoublePositive(double *ptr);
void openingMessage(void);
void getCatFoodInfo(struct CatFoodInfo catFoodInfo[], const int size);
void displayCatFoodHeader(void);
void displayCatFoodData(int sku, double price, double lbs, int calories);
double convertLbsKg(const double *lbs, double *kgs);
int convertLbsG(const double *lbs, int *grams);
void convertLbs(const double *lbs, double *kgs, int *grams);
double calculateServings(const int serving_size_grams, const int total_grams, double *result);
double calculateCostPerServing(const double *product_price, const double *total_servings, double *result);
double calculateCostPerCal(const double *product_price, const double *total_calories, double *result);
struct ReportData calculateReportData(const struct CatFoodInfo product_data);
void displayReportHeader(void);
void displayReportData(const struct ReportData report_data, const int is_cheapest_option);
void displayFinalAnalysis(const struct CatFoodInfo product_data);
void start();

#endif //W8P2_H
