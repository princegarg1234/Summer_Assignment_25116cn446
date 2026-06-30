#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100


struct Book {
    int id;
    char title[100];
    char author[50];
    int isAvailable; 
};


struct Book library[MAX_BOOKS];
int bookCount = 0;


void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n*** MINI LIBRARY SYSTEM MENU ***");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Program closing.\n");
            break;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nThank you for using the Library System!\n");
                exit(0);
            default:
                printf("\nInvalid selection! Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}


void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nError: The library memory is full!\n");
        return;
    }

    struct Book newBook;
    
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &newBook.id);
    
    
    while (getchar() != '\n'); 

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; 

    newBook.isAvailable = 1; 

    library[bookCount] = newBook;
    bookCount++;

    printf("\nSuccess: Book added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("\nThe library contains no books yet.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n--------------------------------------------------------------------------------");
    for (int i = 0; i < bookCount; i++) {
        printf("\n%-10d %-30s %-25s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].isAvailable ? "Available" : "Issued");
    }
    printf("\n");
}


void searchBook() {
    if (bookCount == 0) {
        printf("\nThe library contains no books yet.\n");
        return;
    }

    int searchId;
    int found = 0;
    
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\n--- Book Details Found ---");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].isAvailable ? "Available" : "Issued");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nError: No book with ID %d was found.\n", searchId);
    }
}

void issueBook() {
    int targetId;
    int found = 0;

    printf("\nEnter the Book ID you want to issue: ");
    scanf("%d", &targetId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == targetId) {
            found = 1;
            if (library[i].isAvailable == 1) {
                library[i].isAvailable = 0; 
                printf("\nSuccess: Book '%s' has been issued successfully!\n", library[i].title);
            } else {
                printf("\nNotice: This book is already issued to someone else.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nError: No book with ID %d exists.\n", targetId);
    }
}


void returnBook() {
    int targetId;
    int found = 0;

    printf("\nEnter the Book ID you want to return: ");
    scanf("%d", &targetId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == targetId) {
            found = 1;
            if (library[i].isAvailable == 0) {
                library[i].isAvailable = 1; 
                printf("\nSuccess: Book '%s' has been returned safely.\n", library[i].title);
            } else {
                printf("\nNotice: This book was already in the library, not flagged as issued.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nError: No book with ID %d exists.\n", targetId);
    }
}
