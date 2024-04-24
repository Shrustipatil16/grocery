#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct User* next;
} User;

User* users = NULL;
int num_users = 0;

void signup() {
    User* new_user = malloc(sizeof(User));
    if (new_user == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(new_user->username, username);
    strcpy(new_user->password, password);
    new_user->next = NULL; 

        new_user->next = users;
    users = new_user;
    num_users++;

    printf("Signup successful!\n");
}

int login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    User* current = users;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
            printf("Login successful!\n");
            return 1;
        }
        current = current->next;
    }

    printf("Invalid username or password.\n");
    return 0;
}

void free_users() {
    User* current = users;
    while (current != NULL) {
        User* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Sign up\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                if (login()) {
                                    }
                break;
            case 3:
                free_users();
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}