#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.txt"


typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

void addItem();
void displayInventory();
void searchItem();
void updateQuantity();

int main() {
    int choice;

    while (1) {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayInventory(); break;
            case 3: searchItem(); break;
            case 4: updateQuantity(); break;
            case 5: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

void addItem() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Item newItem;
    printf("\nEnter Item ID (Integer): ");
    scanf("%d", &newItem.id);
    
    
    while (getchar() != '\n'); 
    
    printf("Enter Item Name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; 

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    
    fprintf(file, "%d,%s,%d,%.2f\n", newItem.id, newItem.name, newItem.quantity, newItem.price);
    fclose(file);

    printf("Item added successfully!\n");
}


void displayInventory() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo inventory data found. Add items first!\n");
        return;
    }

    Item currentItem;
    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-10s\n", "Item ID", "Item Name", "Quantity", "Price");
    printf("-------------------------------------------------------------\n");

    
    while (fscanf(file, "%d,%[^,],%d,%f\n", &currentItem.id, currentItem.name, &currentItem.quantity, &currentItem.price) != EOF) {
        printf("%-10d %-25s %-12d $%-10.2f\n", currentItem.id, currentItem.name, currentItem.quantity, currentItem.price);
    }
    printf("-------------------------------------------------------------\n");
    fclose(file);
}


void searchItem() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo inventory data found.\n");
        return;
    }

    int searchId;
    int found = 0;
    Item currentItem;

    printf("\nEnter Item ID to search: ");
    scanf("%d", &searchId);

    while (fscanf(file, "%d,%[^,],%d,%f\n", &currentItem.id, currentItem.name, &currentItem.quantity, &currentItem.price) != EOF) {
        if (currentItem.id == searchId) {
            printf("\nItem Found!");
            printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n", currentItem.id, currentItem.name, currentItem.quantity, currentItem.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", searchId);
    }
    fclose(file);
}


void updateQuantity() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo inventory data found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("System error handling updates.\n");
        fclose(file);
        return;
    }

    int targetId, newQuantity;
    int found = 0;
    Item currentItem;

    printf("\nEnter Item ID to update stock quantity: ");
    scanf("%d", &targetId);

    while (fscanf(file, "%d,%[^,],%d,%f\n", &currentItem.id, currentItem.name, &currentItem.quantity, &currentItem.price) != EOF) {
        if (currentItem.id == targetId) {
            printf("Current quantity of %s is %d. Enter new quantity: ", currentItem.name, currentItem.quantity);
            scanf("%d", &newQuantity);
            currentItem.quantity = newQuantity;
            found = 1;
        }
        
        fprintf(tempFile, "%d,%s,%d,%.2f\n", currentItem.id, currentItem.name, currentItem.quantity, currentItem.price);
    }

    fclose(file);
    fclose(tempFile);

    
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Stock quantity updated successfully!\n");
    } else {
        printf("Item with ID %d not found.\n", targetId);
    }
}

