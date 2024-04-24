#include <stdio.h>
#include <string.h>

struct Item {
    char name[20];
    float price;
};

void printBill(char name[], int mobile, char payment_mode[], struct Item items[], int quantities[], int count) {
    float total = 0.0;
    printf("\n========== Grocery Bill ==========\n");
    printf("Customer Name: %s\n", name);
    printf("Mobile Number: %d\n", mobile);
    printf("Payment Mode: %s\n", payment_mode);
    printf("\nItems\t\tQuantity\tPrice\n");
    printf("---------------------------------\n");

    for (int i = 0; i < count; i++) {
        float price = items[i].price;
        printf("%s", items[i].name);
        total += price * quantities[i];
        printf("\t\t%d\t\t%.2f\n", quantities[i], price);
    }
    printf("---------------------------------\n");
    printf("Total\t\t\t\t%.2f\n", total);
    printf("=================================\n");
}

int main() {
    char name[50];
    int mobile;
    char payment_mode[25];
    int quantities[100];
    struct Item items[100];
    int count = 0;
    int choice;

    printf("Enter Customer Name: ");
    scanf("%49s", name);
    printf("Enter Mobile Number: ");
    scanf("%d", &mobile);
    printf("Choose The Payment Mode ->\n");
    printf("1 - Online\n");
    printf("2 - Card\n");
    printf("3 - Cash\n");
    printf("4 - Gift Cards/Vouchers\n");
    printf("Enter The Mode : ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            strcpy(payment_mode, "Online");
            break;
        case 2:
            strcpy(payment_mode, "Card");
            break;
        case 3:
            strcpy(payment_mode, "Cash");
            break;
        case 4:
            strcpy(payment_mode, "Gift Cards/Vouchers");
            break;
        default:
            printf("Invalid Payment Mode\n");
            return 1;
    }

    do {
        int item, quantity;
        printf("Add Item To Cart\n");
        printf("1 -> Bread\n");
        printf("2 -> Milk\n");
        printf("3 -> Eggs\n");
        printf("4 -> Rice\n");
        printf("5 -> Hand Wash\n");
        printf("6 -> Shampoo\n");
        printf("Enter item number (1-6) or 0 to finish: ");
        scanf("%d", &item);
        if (item == 0)
            break;
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        switch (item) {
            case 1:
                strcpy(items[count].name, "Bread");
                items[count].price = 50.0;
                break;
            case 2:
                strcpy(items[count].name, "Milk");
                items[count].price = 30.0;
                break;
            case 3:
                strcpy(items[count].name, "Eggs");
                items[count].price = 20.0;
                break;
            case 4:
                strcpy(items[count].name, "Rice");
                items[count].price = 60.0;
                break;
            case 5:
                strcpy(items[count].name, "Hand Wash");
                items[count].price = 100.0;
                break;
            case 6:
                strcpy(items[count].name, "Shampoo");
                items[count].price = 80.0;
                break;
            default:
                printf("Invalid item\n");
                continue;
        }
        
        quantities[count] = quantity;
        count++;
    } while (count < 100);

    printBill(name, mobile, payment_mode, items, quantities, count);

    return 0;
}
