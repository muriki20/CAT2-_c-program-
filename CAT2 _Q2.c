// c program 
/*
Name:moses
reg:CT100/G/26258/25
description:program reading procesin and writing interger to file
}
*/#include <stdio.h>

int main() {
    float hours, rate, gross_pay, tax, net_pay;
    float overtime_hours, overtime_pay;

    // Input from user
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    printf("Enter hourly wage: ");
    scanf("%f", &rate);

    // Calculate gross pay
    if (hours > 40) {
        overtime_hours = hours - 40;
        overtime_pay = overtime_hours * rate * 1.5;
        gross_pay = (40 * rate) + overtime_pay;
    } else {
        gross_pay = hours * rate;
    }

    // Calculate tax
    if (gross_pay <= 600)
        tax = 0.15 * gross_pay;
    else
        tax = (0.15 * 600) + (0.20 * (gross_pay - 600));

    // Calculate net pay
    net_pay = gross_pay - tax;

    // Display results
    printf("\nGross Pay: $%.2f", gross_pay);
    printf("\nTax: $%.2f", tax);
    printf("\nNet Pay: $%.2f\n", net_pay);

    return 0;
}