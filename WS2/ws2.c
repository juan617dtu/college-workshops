#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    float s_shirt, m_shirt, l_shirt;
    int price_small, price_medium, price_large, num_shirt_s, num_shirt_l, num_shirt_m, sub_total, tax, total,
    sal_subtotal, sal_tax, sal_total, tom_subtotal, tom_tax, tom_total, subtotal_total, tax_total, total_total, toonies,
    loonies, quarters, remainder, dimes, nickels, pennies, qty;

    printf("Set Shirt Prices\n================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &s_shirt);
    price_small = (int)(s_shirt * 100 + 0.5);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &m_shirt);
    price_medium = (int)(m_shirt * 100 + 0.5);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &l_shirt);
    price_large = (int)(l_shirt * 100 + 0.5);

    printf("Shirt Store Price List\n======================\n");
    printf("SMALL : $%.2f\nMEDIUM: $%.2f\nLARGE : $%.2f", s_shirt, m_shirt, l_shirt);
    printf("\n\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &num_shirt_s);
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &num_shirt_l);
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &num_shirt_m);

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total");
    printf("\n-------- ---- ----- --- --------- --------- ---------\n");
    sub_total = (num_shirt_s * price_small);
    tax = (int)(sub_total * TAX + 0.5);
    total = (int)(sub_total + tax + 0.5);
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, (float)price_small / 100, num_shirt_s,
        (float)sub_total / 100.0, (float)tax / 100.0, (float)total / 100.0);
    sal_subtotal = (num_shirt_m * price_medium);
    sal_tax = (int)(sal_subtotal * TAX + 0.5);
    sal_total = (int)(sal_subtotal + sal_tax + 0.5);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, (float)price_medium / 100, num_shirt_m,
        (float)sal_subtotal / 100.0, (float)sal_tax / 100.0, (float)sal_total / 100.0);
    tom_subtotal = (num_shirt_l * price_large);
    tom_tax = (int)(tom_subtotal * TAX + 0.5);
    tom_total = (int)(tom_subtotal + tom_tax + 0.5);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, (float)price_large / 100, num_shirt_l,
        (float)tom_subtotal / 100.0, (float)tom_tax / 100.0, (float)tom_total / 100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    subtotal_total = (sub_total + sal_subtotal + tom_subtotal);
    tax_total = (tax + sal_tax + tom_tax);
    total_total = (total + sal_total + tom_total);
    printf("%33.4lf %9.4lf %9.4lf\n\n", (float)subtotal_total / 100.0, (float)tax_total / 100.0,
        (float)total_total / 100.0);

    printf("Daily retail sales represented by coins\n=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (float)subtotal_total / 100.0);
    toonies = subtotal_total / 200;
    remainder = subtotal_total % 200;
    printf("Toonies  %3d %9.4lf\n", toonies, fmod((float)remainder / 100.0, 2.0));
    loonies = remainder / 100;
    remainder %= 100;
    printf("Loonies  %3d %9.4lf\n", loonies, fmod((float)remainder / 100.0, 1.0));
    quarters = remainder / 25;
    remainder %= 25;
    printf("Quarters %3d %9.4lf\n", quarters, fmod((float)remainder / 100.0, 0.25));
    dimes = remainder / 10;
    remainder %= 10;
    printf("Dimes    %3d %9.4lf\n", dimes, fmod((float)remainder / 100.0, 0.10));
    nickels = remainder / 5;
    remainder %= 5;
    printf("Nickels  %3d %9.4lf\n", nickels, fmod((float)remainder / 100.0, 0.5));
    pennies = remainder;
    remainder %= 1;
    printf("Pennies  %3d %9.4lf\n", pennies, (float)remainder);

    qty = num_shirt_s + num_shirt_m + num_shirt_l;
    printf("\nAverage cost/shirt: $%.4lf\n", ((float)subtotal_total / 100.0) / (float)qty);

    printf("\nSales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (float)total_total / 100.0);
    toonies = total_total / 200;
    remainder = total_total % 200;
    printf("Toonies  %3d %9.4lf\n", toonies, fmod((float)remainder/ 100.0, 2.0));
    loonies = remainder / 100;
    remainder %= 100;
    printf("Loonies  %3d %9.4lf\n", loonies, fmod((float)remainder / 100.0, 1.0));
    quarters = remainder / 25;
    remainder %= 25;
    printf("Quarters %3d %9.4lf\n", quarters, fmod((float)remainder / 100.0, 0.25));
    dimes = remainder / 10;
    remainder %= 10;
    printf("Dimes    %3d %9.4lf\n", dimes, fmod((float)remainder / 100.0, 0.10));
    nickels = remainder / 5;
    remainder %= 5;
    printf("Nickels  %3d %9.4lf\n", nickels, fmod((float)remainder / 100.0, 0.5));
    pennies = remainder;
    remainder %= 1;
    printf("Pennies  %3d %9.4lf\n", pennies, (float)remainder);

    printf("\nAverage cost/shirt: $%.4lf\n", ((float)total_total / 100.0) / (float)qty);

    return 0;
}
