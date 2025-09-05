#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month, day = 1;
    double morning_rate[LOG_DAYS], evening_rate[LOG_DAYS], total_morning_rate = 0.0, total_evening_rate = 0.0;

    printf("General Well-being Log\n======================\n");

    while(1) {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (month < JAN || month > DEC) printf("   ERROR: Jan.(1) - Dec.(12)\n");
        if (year >= MIN_YEAR && year <= MAX_YEAR && month >= 1 && month <= 12) break;
    }
    printf("\n*** Log date set! ***");

    for (int i = 0; i < LOG_DAYS; i++) {
        printf("\n\n%d-", year);
        switch (month) {
            case 1: printf("JAN-");
                break;
            case 2: printf("FEB-");
                break;
            case 3: printf("MAR-");
                break;
            case 4: printf("APR-");
                break;
            case 5: printf("MAY-");
                break;
            case 6: printf("JUN-");
                break;
            case 7: printf("JUL-");
                break;
            case 8: printf("AUG-");
                break;
            case 9: printf("SEP-");
                break;
            case 10: printf("OCT-");
                break;
            case 11: printf("NOV-");
                break;
            default: printf("DEC-");
                break;
        }
        if (day < 10) printf("0%d\n", day);
        else if (day >= 10) printf("%d\n", day);

        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morning_rate[i]);
            if (morning_rate[i] < 0.0 || morning_rate[i] > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else if (morning_rate[i] <= 5.0 && morning_rate[i] >= 0.0) break;

        } while (1);

        while (1) {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evening_rate[i]);
            if (evening_rate[i] < 0.0 || evening_rate[i] > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else if (evening_rate[i] <= 5.0 && evening_rate[i] >= 0.0) break;
        }
        day++;
    }
    printf("\n\nSummary\n=======\n");
    for (int j = 0; j < LOG_DAYS; j++) {
        total_morning_rate += morning_rate[j];
    }
    for (int k = 0; k < LOG_DAYS; k++) {
        total_evening_rate += evening_rate[k];
    }
    printf("Morning total rating: %.3lf\n", total_morning_rate);
    printf("Evening total rating: %.3lf\n", total_evening_rate);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", total_morning_rate + total_evening_rate);
    const double avg_morning_rate = total_morning_rate / LOG_DAYS;
    printf("Average morning rating:  %.1lf\n", avg_morning_rate);
    const double avg_evening_rate = total_evening_rate / LOG_DAYS;
    printf("Average evening rating:  %.1lf\n", avg_evening_rate);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", (avg_morning_rate + avg_evening_rate) / 2);

    return 0;
}