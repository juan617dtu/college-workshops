#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    const double GRAMS_IN_LBS = 453.5924;

    int bag_weight1, bag_weight2, bag_weight3, daily_servings;
    char coffee_type1, coffee_type2, coffee_type3, cream1, cream2, cream3, coffee_strength, coffee_with_cream;

    printf("Take a Break - Coffee Shop\n==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&coffee_type1);
    coffee_type1 = toupper(coffee_type1);
    printf("Bag weight (g): ");
    scanf("%d",&bag_weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    cream1 = toupper(cream1);
    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&coffee_type2);
    coffee_type2 = toupper(coffee_type2);
    printf("Bag weight (g): ");
    scanf("%d",&bag_weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c",&cream2);
    cream2 = toupper(cream2);
    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium): ");
    scanf(" %c",&coffee_type3);
    coffee_type3 = toupper(coffee_type3);
    printf("Bag weight (g): ");
    scanf("%d",&bag_weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c",&cream3);
    cream3 = toupper(cream3);

    printf("\n\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   | Coffee                 | Packaged      | Best  |\n");
    printf("   | Type                   | Bag Weight    | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light  | Medium | Rich | (G)   | Lbs   | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d    |   %d    |   %d  | %4d  | %6.3lf|   %d   |\n", coffee_type1 == 'L' ? 1 : 0,
        coffee_type1 == 'M' ? 1 : 0, coffee_type1 == 'R' ? 1 : 0, bag_weight1, bag_weight1 / GRAMS_IN_LBS,
        cream1 == 'Y' ? 1 : 0);
    printf(" 2 |   %d    |   %d    |   %d  | %4d  | %6.3lf|   %d   |\n", coffee_type2 == 'L' ? 1 : 0,
        coffee_type2 == 'M' ? 1 : 0, coffee_type2 == 'R' ? 1 : 0, bag_weight2, bag_weight2 / GRAMS_IN_LBS,
        cream2 == 'Y' ? 1 : 0);
    printf(" 3 |   %d    |   %d    |   %d  | %4d  | %6.3lf|   %d   |\n", coffee_type3 == 'L' ? 1 : 0,
        coffee_type3 == 'M' ? 1 : 0, coffee_type3 == 'R' ? 1 : 0, bag_weight3, bag_weight3 / GRAMS_IN_LBS,
        cream3 == 'Y' ? 1 : 0);

    printf("\n\nEnter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c",&coffee_strength);
    coffee_strength = toupper(coffee_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_with_cream);
    coffee_with_cream = toupper(coffee_with_cream);
    printf("Typical number of daily servings: ");
    scanf("%d", &daily_servings);
    printf("\nThe below table shows how your preferences align to the available products:");
    printf("--------------------+-------------+-------+\n");
    printf("  |      Coffee     |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|        %d       |      %d     |   %d  |\n", coffee_strength == 'L' ? 1 : 0,
        daily_servings > 0 && daily_servings < 5? 1 : 0, coffee_with_cream == 'Y'? 1 : 0);
    printf(" 2|        %d       |      %d     |   %d  |\n", coffee_strength == 'R' ? 1 : 0,
        daily_servings > 4 && daily_servings < 10? 1 : 0, coffee_with_cream == 'Y'? 1 : 0);
    printf(" 3|        %d       |      %d     |   %d  |\n", coffee_strength == 'M' ? 1 : 0,
        daily_servings > 10 ? 1 : 0, coffee_with_cream == 'Y'? 1 : 0);

    printf("\n\nEnter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c",&coffee_strength);
    coffee_strength = toupper(coffee_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_with_cream);
    coffee_with_cream = toupper(coffee_with_cream);
    printf("Typical number of daily servings: ");
    scanf("%d", &daily_servings);
    printf("\nThe below table shows how your preferences align to the available products:");
    printf("--------------------+-------------+-------+\n");
    printf("  |      Coffee     |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|        %d       |      %d     |   %d  |\n", coffee_strength == 'L' ? 1 : 0,
        daily_servings > 0 && daily_servings < 5? 1 : 0, coffee_with_cream == 'Y'? 1 : 0);
    printf(" 2|        %d       |      %d     |   %d  |\n", coffee_strength == 'R' ? 1 : 0,
        daily_servings > 4 && daily_servings < 10? 1 : 0, coffee_with_cream == 'Y'? 1 : 0);
    printf(" 3|        %d       |      %d     |   %d  |\n", coffee_strength == 'M' ? 1 : 0,
        daily_servings > 10 ? 1 : 0, coffee_with_cream == 'Y'? 1 : 0);

    printf("\nHope you found a product that suits your likes!");

    return 0;
}
