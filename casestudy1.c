
int main() {
    char name[50];
    int mobile;
    char payment_mode[25];
    int items[100];
    int quantities[100];
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
        items[count] = item;
        quantities[count] = quantity;
        count++;
    } while (count < 100);

    
    printBill(name, mobile, payment_mode, items, quantities, count);

    return 0;
}