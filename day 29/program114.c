#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


int arr[MAX_SIZE];
int n = 0; 


void createArray();
void displayArray();
void insertElement();
void deleteElement();
void searchElement();

int main() {
    int choice;

    while (1) {
        
        printf("\n=============================");
        printf("\n   ARRAY OPERATIONS SYSTEM   ");
        printf("\n=============================");
        printf("\n1. Create / Initialize Array");
        printf("\n2. Display Array Elements");
        printf("\n3. Insert Element at Position");
        printf("\n4. Delete Element from Position");
        printf("\n5. Search Element (Linear Search)");
        printf("\n6. Exit");
        printf("\n=============================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                createArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                insertElement();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                searchElement();
                break;
            case 6:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}


void createArray() {
    printf("\nEnter the number of elements to store (Max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 0 || n > MAX_SIZE) {
        printf("Invalid size! Resetting size to 0.\n");
        n = 0;
        return;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully!\n");
}


void displayArray() {
    if (n == 0) {
        printf("\nArray is empty! Nothing to display.\n");
        return;
    }

    printf("\nCurrent Array Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void insertElement() {
    int element, pos;

    if (n >= MAX_SIZE) {
        printf("\nError: Array Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("\nEnter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (1 to %d): ", n + 1);
    scanf("%d", &pos);


    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Insertion aborted.\n");
        return;
    }

    
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = element; 
    n++; 
    printf("Element inserted successfully!\n");
}


void deleteElement() {
    int pos;

    if (n == 0) {
        printf("\nError: Array Underflow! No element to delete.\n");
        return;
    }

    printf("\nEnter the position of the element to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position! Deletion aborted.\n");
        return;
    }

    printf("Deleted element: %d\n", arr[pos - 1]);

   
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--; 
    printf("Element deleted successfully!\n");
}


void searchElement() {
    int key, found = 0;

    if (n == 0) {
        printf("\nArray is empty! Cannot perform search.\n");
        return;
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at Position %d (Index %d).\n", i + 1, i);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("Element not found in the array.\n");
    }
}
