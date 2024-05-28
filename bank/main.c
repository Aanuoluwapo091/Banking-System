#include <stdio.h>
#include <stdlib.h>

#include <string.h>

struct BankAccount {
int accountNumber;
float balance;
char password[20];
};

void deposit(struct BankAccount *account, float amount) {
account->balance += amount;
}

void withdraw(struct BankAccount *account, float amount) {
if (account->balance >= amount) {
account->balance -= amount;
} else {
printf("Insufficient funds!\n");
}
}

void checkBalance(struct BankAccount *account) {
printf("Account Number: %d\n", account->accountNumber);
printf("Current Balance: $%.2f\n", account->balance);
}

void applyLoan(struct BankAccount *account, float amount) {
account->balance += amount;
printf("Loan of $%.2f approved and added to your account.\n", amount);
}

int main() {
struct BankAccount account1 = {123456, 1000.0, "password123"}; // Example account with initial balance $1000 and password
int choice;
float amount;
char password[20];

printf("Welcome to Mercy Bank!\n");
printf("Enter your account password: ");
scanf("%s", password);

if (strcmp(password, account1.password) != 0) {
printf("Incorrect password! Access denied.\n");
return 0;
}

do {
printf("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Apply for Loan\n5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {


case 1:
printf("Enter amount to deposit: $");
scanf("%f", &amount);
deposit(&account1, amount);
break;


case 2:
printf("Enter account password: ");
scanf("%s", password);
if (strcmp(password, account1.password) != 0) {
printf("Incorrect password! Access denied.\n");

break;
}


printf("Enter amount to withdraw: $");
scanf("%f", &amount);
withdraw(&account1, amount);
break;

case 3:
checkBalance(&account1);
break;

case 4:
       printf("Enter loan amount: $");
       scanf("%f", &amount);
       applyLoan(&account1, amount);
break;
case 5:
       printf("Thank you for using Mercy Bank!\n");
break;

default:
printf("Invalid choice! Please try again.\n");
}

} while (choice != 5);
return 0;
}
