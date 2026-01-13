#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_ITEMS 10

bool find_first_instance(char arr[], const int size, const char target) {

	for (int l = 0; l < size; l++) {
		if (arr[l] == target) {
			return true;
		}
	}
	return false;
}
int main(void)
{
	const double min_income = 500.00, max_income = 400000.00, min_cost = 100.00;
	double monthly_income, cost[MAX_ITEMS], total = 0, priority_total = 0.0;
	int items, priority[MAX_ITEMS], forecast_option, months, years, leftover_months, priority_option;
	char finance_option[MAX_ITEMS];
	bool flag = false;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	do {
		printf("Enter your monthly NET income: $");
		scanf("%lf", &monthly_income);
		if (monthly_income < min_income) {
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", min_income);
		}
		else if (monthly_income > max_income) {
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", max_income);
		}
		else { break; }
	} while (1);

	while (1) {
		printf("\n\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &items);
		if (items < 1 || items > MAX_ITEMS) printf("ERROR: List is restricted to between 1 and 10 items.");
		else { break; }
	}
	for (int i = 0; i < items; i++) {
		printf("\nItem-%d Details:\n", i + 1);

		do {
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);
			if (cost[i] < min_cost) {
				printf("      ERROR: Cost must be at least $%.2lf\n", min_cost);
			}
		} while (cost[i] < min_cost);

		do {
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);

			if (priority[i] < 1 || priority[i] > 3) {
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (priority[i] < 1 || priority[i] > 3);

		do {
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance_option[i]);  // space before %c eats newline

			if (finance_option[i] != 'y' && finance_option[i] != 'n') {
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (finance_option[i] != 'y' && finance_option[i] != 'n');
	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (int j = 0; j < items; j++) {
		printf("%3d  %5d    %5c    %11.2lf\n", j + 1, priority[j], finance_option[j], cost[j]);
	}

	printf("---- -------- -------- -----------\n");

	for (int k = 0; k < items; k++) {
		total += cost[k];
	}
	printf("                      $%11.2lf\n", total);

	do {
		printf("\nHow do you want to forecast your wish list?\n1. All items (no filter)\n2. By priority\n");
		printf("0. Quit/Exit\nSelection: ");
		scanf("%d", &forecast_option);

		if (forecast_option == 0) printf("\nBest of luck in all your future endeavours!\n");
		else if (forecast_option < 0 || forecast_option > 2) printf("\nERROR: Invalid menu selection.\n");
		else if (forecast_option == 1) {
			printf("\n====================================================\nFilter: All items\n");
			printf("Amount: $%.2lf\n", total);

			months = (int)ceil(total / monthly_income);
			years = months / 12;
			leftover_months = months % 12;

			printf("Forecast: %d years, %d months\n", years, leftover_months);

			if (find_first_instance(finance_option, sizeof(finance_option) / sizeof(finance_option[0]), 'y'))
				{
				printf("NOTE: Financing options are available on some items.\n"
		   "      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
		}
		else if (forecast_option == 2) {
			do {
				printf("\nWhat priority do you want to filter by? [1-3]: ");
				scanf("%d", &priority_option);
			} while (priority_option < 1 || priority_option > 3);

			printf("\n====================================================\n");
			printf("Filter:  by priority (%d)\n", priority_option);

			switch (priority_option) {
				case 1: {
					flag = false;
					priority_total = 0.0;
					for (int n = 0; n < items; n++) {
						if (priority[n] == 1) {
							priority_total += cost[n];
							if (finance_option[n] == 'y') flag = true;
						}
					}
					printf("Amount:  $%1.2lf\n", priority_total);

					months = (int)ceil(priority_total / monthly_income);
					years = months / 12;
					leftover_months = months % 12;
					printf("Forecast: %d years, %d months\n", years, leftover_months);
					if (flag == true) {
						printf("NOTE: Financing options are available on some items.\n"
					"      You can likely reduce the estimated months.\n");
					}
					printf("====================================================\n");
					break;
				}
				case 2: {
					priority_total = 0.0;
					flag = false;
					for (int o = 0; o < items; o++) {
						if (priority[o] == 2) {
							priority_total += cost[o];
							if (finance_option[o] == 'y') flag = true;
						}
					}
					printf("Amount:  $%1.2lf\n", priority_total);

					months = (int)ceil(priority_total / monthly_income);
					years = months / 12;
					leftover_months = months % 12;
					printf("Forecast: %d years, %d months\n", years, leftover_months);
					if (flag == true) {
						printf("NOTE: Financing options are available on some items.\n"
					"      You can likely reduce the estimated months.\n");
					}
					printf("====================================================\n");
					break;
				}
				default: {
					priority_total = 0.0;
					flag = false;
					for (int p = 0; p < items; p++) {
						if (priority[p] == 3) {
							priority_total += cost[p];
							if (finance_option[p] == 'y') flag = true;
						}
					}
					printf("Amount:  $%1.2lf\n", priority_total);

					months = (int)ceil(priority_total / monthly_income);
					years = months / 12;
					leftover_months = months % 12;
					printf("Forecast: %d years, %d months\n", years, leftover_months);
					if (flag == true) {
						printf("NOTE: Financing options are available on some items.\n"
					"      You can likely reduce the estimated months.\n");
					}
					printf("====================================================\n");
					break;
				}
			}
		}
	} while (forecast_option != 0);

    return 0;
}
