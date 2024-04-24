#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PAYMENT_MODE_LENGTH 25

struct Item {
    int id;
    char name[20];
    float price;
};

struct Cart {
    struct Item items[MAX_ITEMS];
    int quantities[MAX_ITEMS];
    int count;
};

struct Customer {
    char name[MAX_NAME_LENGTH];
    int mobile;
    char payment_mode[MAX_PAYMENT_MODE_LENGTH];
    struct Cart cart;
};

// Function to print the bill
void printBill(struct Customer customer) {
    float total = 0;

    printf("\n\nCustomer Name: %s\n", customer.name);
    printf("Mobile Number: %d\n", customer.mobile);
    printf("Payment Mode: %s\n", customer.payment_mode);

    printf("\n\nItems in Cart:\n");
    printf("ID\tName\t\tPrice\tQuantity\tTotal\n");
    for (int i = 0; i < customer.cart.count; i++) {
        struct Item item = customer.cart.items[i];
        int quantity = customer.cart.quantities[i];
        float itemTotal = item.price * quantity;
        total += itemTotal;
        printf("%d\t%s\t\t%.2f\t%d\t\t%.2f\n", item.id, item.name, item.price, quantity, itemTotal);
    }

    printf("\nTotal Bill: %.2f\n", total);
}

int main() {
    struct Customer customer;
    int choice;

    printf("Enter Customer Name: ");
    scanf("%49s", customer.name);
    printf("Enter Mobile Number: ");
    scanf("%d", &customer.mobile);

    printf("Choose The Payment Mode ->\n");
    printf("1 - Online\n");
    printf("2 - Card\n");
    printf("3 - Cash\n");
    printf("4 - Gift Cards/Vouchers\n");
    printf("Enter The Mode : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(customer.payment_mode, "Online");
            break;
        case 2:
            strcpy(customer.payment_mode, "Card");
            break;
        case 3:
            strcpy(customer.payment_mode, "Cash");
            break;
        case 4:
            strcpy(customer.payment_mode, "Gift Cards/Vouchers");
            break;
        default:
            printf("Invalid Payment Mode\n");
            return 1;
    }

    customer.cart.count = 0;

    do {
        int itemId, quantity;
        printf("\nAdd Item To Cart\n");
        printf("1 -> Bread (2.50)\n");
        printf("2 -> Milk (3.00)\n");
        printf("3 -> Eggs (0.20)\n");
        printf("Enter item number (1-3) or 0 to finish: ");
        scanf("%d", &itemId);
        if (itemId == 0)
            break;
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Adding item to cart
        switch (itemId) {
            case 1:
                strcpy(customer.cart.items[customer.cart.count].name, "Bread");
                customer.cart.items[customer.cart.count].price = 2.50;
                break;
            case 2:
                strcpy(customer.cart.items[customer.cart.count].name, "Milk");
                customer.cart.items[customer.cart.count].price = 3.00;
                break;
            case 3:
                strcpy(customer.cart.items[customer.cart.count].name, "Eggs");
                customer.cart.items[customer.cart.count].price = 0.20;
                break;
            default:
                printf("Invalid item\n");
                continue;
        }
        customer.cart.items[customer.cart.count].id = itemId;
        customer.cart.quantities[customer.cart.count] = quantity;
        customer.cart.count++;
    } while (customer.cart.count < MAX_ITEMS);

    printBill(customer);

    return 0;
}
