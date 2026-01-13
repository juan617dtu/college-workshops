#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages, picked_apples, picked_oranges, picked_pears, picked_tomatoes,
    picked_cabbages, ans = 1;

    do {
        printf("Grocery Shopping\n================\n");

        while (true) {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
            if (apples >= 0) break;
            printf("ERROR: Value must be 0 or more.\n");
        }
        printf("\n");

        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges >= 0) break;
            printf("ERROR: Value must be 0 or more.\n");
        } while (true);
        printf("\n");

        for (int i = 0; i == 0;) {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears >= 0) i++;
            else printf("ERROR: Value must be 0 or more.\n");
        }
        printf("\n");

        while (1) {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
            if (tomatoes >= 0) break;
            printf("ERROR: Value must be 0 or more.\n");
        }
        printf("\n");

        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages >= 0) break;
            printf("ERROR: Value must be 0 or more.\n");
        } while (1);

        printf("\n\n--------------------------\nTime to pick the products!\n--------------------------\n\n");

        if (apples > 0) {
            for (int j = 0; j == 0;) {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &picked_apples);
                if (picked_apples < 1) printf("ERROR: You must pick at least 1!\n");
                else if (picked_apples > apples) {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
                }
                else {
                    apples -= picked_apples;
                    apples == 0? j++ : printf("Looks like we still need some APPLES...\n");
                }
            } printf("Great, that's the apples done!\n");
            printf("\n");
        }

        if (oranges > 0) {
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &picked_oranges);
                if (picked_oranges < 1) printf("ERROR: You must pick at least 1!\n");
                else if (picked_oranges > oranges) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                }
                else {
                    oranges -= picked_oranges;
                    if (oranges == 0) {
                        printf("Great, that's the oranges done!\n");
                        break;
                    }
                    printf("Looks like we still need some ORANGES...\n");
                }
            } while (true);
            printf("\n");
        }

        if (pears > 0) {
            while (true) {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &picked_pears);
                if (picked_pears < 1) printf("ERROR: You must pick at least 1!\n");
                else if (picked_pears > pears) {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                }
                else {
                    pears -= picked_pears;
                    if (pears == 0) {
                        printf("Great, that's the pears done!\n");
                        break;
                    }
                    printf("Looks like we still need some PEARS...\n");
                }
            }
            printf("\n");
        }

        if (tomatoes > 0) {
            while (true) {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &picked_tomatoes);
                if (picked_tomatoes < 1) printf("ERROR: You must pick at least 1!\n");
                else if (picked_tomatoes > tomatoes) {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                }
                else {
                    tomatoes -= picked_tomatoes;
                    if (tomatoes == 0) {
                        printf("Great, that's the tomatoes done!\n");
                        break;
                    }
                    printf("Looks like we still need some TOMATOES...\n");
                }
            }
            printf("\n");
        }

        if (cabbages > 0) {
            while (true) {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &picked_cabbages);
                if (picked_cabbages < 1) printf("ERROR: You must pick at least 1!\n");
                else if (picked_cabbages > cabbages) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                }
                else {
                    cabbages -= picked_cabbages;
                    if (cabbages == 0) {
                        printf("Great, that's the cabbages done!\n");
                        break;
                    }
                    printf("Looks like we still need some CABBAGES...\n");
                }
            }
            printf("\n");
        }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &ans);
        printf("\n");
    } while (ans != 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
