#include <stdio.h>
#include <string.h>


void printBill(char name[], int mobile, char payment_mode[], int items[], int quantities[], int count) {
    float total = 0.0;
    printf("\n========== Grocery Bill ==========\n");
    printf("Customer Name: %s\n", name);
    printf("Mobile Number: %d\n", mobile);
    printf("Payment Mode: %s\n", payment_mode);
    printf("\nItems\t\tQuantity\tPrice\n");
    printf("---------------------------------\n");

    
    for (int i = 0; i < count; i++) {
        float price;
        switch (items[i]) {
            case 1:
                price = 50.0;
                printf("Bread");
                break;
            case 2:
                price = 30.0;
                printf("Milk");
                break;
            case 3:
                price = 20.0;
                printf("Eggs");
                break;
            case 4:
                price = 60.0;
                printf("Rice");
                break;
            case 5:
                price = 100.0;
                printf("Hand Wash");
                break;
            case 6:
                price = 80.0;
                printf("Shampoo");
                break;
            default:
                price = 0.0;
                break;
        }
        total += price * quantities[i];
        printf("\t\t%d\t\t%.2f\n", quantities[i], price);
    }
    printf("---------------------------------\n");
    printf("Total\t\t\t\t%.2f\n", total);
    printf("=================================\n");
}