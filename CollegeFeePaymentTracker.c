
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_NAME "records.txt"

// Function to record a payment
void record_payment() {
    char student_name[100];
    float amount;
    FILE *fp;

    printf("\nEnter Student Name: ");
    scanf(" %[^
]", student_name);

    printf("Enter Amount Paid: ");
    scanf("%f", &amount);

    // Get current time
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline

    fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%s,%.2f,%s\n", student_name, amount, timestamp);
    fclose(fp);

    printf("Payment recorded successfully.\n");
}

// Function to print receipt
void print_receipt() {
    char student_name[100];
    float amount;

    printf("\nEnter Student Name for Receipt: ");
    scanf(" %[^
]", student_name);

    printf("Enter Amount Paid: ");
    scanf("%f", &amount);

    // Get current time
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline

    printf("\n----- Receipt -----\n");
    printf("Student Name: %s\n", student_name);
    printf("Amount Paid: ₹%.2f\n", amount);
    printf("Date/Time: %s\n", timestamp);
    printf("-------------------\n");
}

// Function to display all records
void display_records() {
    FILE *fp;
    char line[200];

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n--- Payment Records ---\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    printf("------------------------\n");

    fclose(fp);
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n=== College Fee Payment Tracker ===\n");
        printf("1. Record Payment\n");
        printf("2. Print Receipt\n");
        printf("3. Show All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                record_payment();
                break;
            case 2:
                print_receipt();
                break;
            case 3:
                display_records();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
