#include <stdio.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;
int loginOrder = 0;

// Stack functions
int isFull() { return top == MAX - 1; }
int isEmpty() { return top == -1; }

void push(int loginID) {
    if (isFull()) {
        printf("\nStack Overflow! Cannot login more users.\n");
    } else {
        top++;
        stack[top] = loginID;
        loginOrder++;
        printf("Login Successful! Login ID %d added as session %d\n", loginID, loginOrder);
    }
}

void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! No login session to logout.\n");
    } else {
        printf("Logout Successful! Login ID %d logged out.\n", stack[top]);
        top--;
        loginOrder--;
    }
}

void peek() {
    if (isEmpty()) {
        printf("\nNo Active Login Sessions.\n");
    } else {
        printf("Last Active Login ID: %d\n", stack[top]);
    }
}

void display() {
    if (isEmpty()) {
        printf("\nNo Active Login Sessions.\n");
    } else {
        printf("\nActive Login IDs (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, loginID;

    while (1) {
        printf("\n--- BANK ACCESS SYSTEM USING STACK ---");
        printf("\n1. Login (Push Login ID)");
        printf("\n2. Show Last Login");
        printf("\n3. Logout Last Session");
        printf("\n4. Display All Active Logins");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Login ID: ");
                scanf("%d", &loginID);
                push(loginID);
                break;

            case 2:
                peek();
                break;

            case 3:
                pop();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting Program... Thank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }
}
