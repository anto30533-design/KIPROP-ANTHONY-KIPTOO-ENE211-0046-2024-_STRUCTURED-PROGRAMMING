#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int login();
void displayMenu();
void deposit(double *balance);
void withdraw(double *balance);
void checkBalance(double balance);

int login() {
    int correctPin = 1234;
    int pin;
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter PIN: ");
        scanf("%d", &pin);

        if (pin == correctPin) {
            printf("Login successful!\n");
            return 1;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts left: %d\n", 3 - attempts);
        }
    }
    printf("Maximum attempts reached. Access denied.\n");
    return 0;
}

void displayMenu() {
    printf("\n BANKING MENU \n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
    printf("Select option: ");
}

void deposit(double *balance) {
    double amount;
    printf("Enter amount to deposit: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
    } else {
        *balance += amount;
        printf("Successfully deposited $%.2lf\n", amount);
        printf("New balance: $%.2lf\n", *balance);
    }
}

void withdraw(double *balance) {
    double amount;
    printf("Enter amount to withdraw: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
    } else if (amount > *balance) {
        printf("Insufficient funds! Available balance: $%.2lf\n", *balance);
    } else {
        *balance -= amount;
        printf("Successfully withdrew $%.2lf\n", amount);
        printf("New balance: $%.2lf\n", *balance);
    }
}

void checkBalance(double balance) {
    printf("\n ACCOUNT BALANCE \n");
    printf("Current balance: $%.2lf\n", balance);
}

int main() {
    double balance = 1000.00;
    int choice;

    printf("BANKING SYSTEM \n");

    if (login() == 0) {
        printf("Exiting system...\n");
        return 0;
    }

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                deposit(&balance);
                break;

            case 2:
                withdraw(&balance);
                break;

            case 3:
                checkBalance(balance);
                break;

            case 4:
                printf("Thank you for banking with us!\n");
                printf("Final balance: $%.2lf\n", balance);
                return 0;

            default:
                printf("Invalid choice! Please select 1-4.\n");
        }
    }

    return 0;
}
