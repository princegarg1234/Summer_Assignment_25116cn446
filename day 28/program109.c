#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define FILE_NAME "books.txt"


typedef struct {
    int id;
    char title[100];
    char author[50];
    int available; 
} Book;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: 
                printf("\nThank you for using the Library Management System!\n");
                exit(0);
            default: 
                printf("\nInvalid selection! Please pick a choice between 1 and 6.\n");
        }
    }
    return 0;
}


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void addBook() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("\nError opening file or creating system storage!\n");
        return;
    }

    Book b;
    printf("\nEnter Unique Book ID (Integer): ");
    scanf("%d", &b.id);
    clearInputBuffer();

    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; 

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0'; 

    b.available = 1; 

    fwrite(&b, sizeof(Book), 1, file);
    fclose(file);

    printf("\nSuccess: Book successfully added to the archive!\n");
}


void displayBooks() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo records found. The library is currently empty.\n");
        return;
    }

    Book b;
    printf("\n%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n--------------------------------------------------------------------------------");
    
    while (fread(&b, sizeof(Book), 1, file)) {
        printf("\n%-10d %-30s %-25s %-15s", 
               b.id, b.title, b.author, 
               b.available ? "Available" : "Issued");
    }
    printf("\n--------------------------------------------------------------------------------\n");
    fclose(file);
}

void searchBook() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo library registry found.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter the Book ID to search: ");
    scanf("%d", &searchId);

    Book b;
    while (fread(&b, sizeof(Book), 1, file)) {
        if (b.id == searchId) {
            found = 1;
            printf("\nBook Found Details:");
            printf("\nID: %d", b.id);
            printf("\nTitle: %s", b.title);
            printf("\nAuthor: %s", b.author);
            printf("\nStatus: %s\n", b.available ? "Available" : "Issued");
            break;
        }
    }

    if (!found) {
        printf("\nError: No book matches the ID %d.\n", searchId);
    }
    fclose(file);
}


void issueBook() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (file == NULL) {
        printf("\nSystem database missing or empty.\n");
        return;
    }

    int targetId, found = 0;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &targetId);

    Book b;
    while (fread(&b, sizeof(Book), 1, file)) {
        if (b.id == targetId) {
            found = 1;
            if (b.available == 1) {
                b.available = 0; 
                
            
                fseek(file, -sizeof(Book), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, file);
                
                printf("\nSuccess: The book '%s' has been issued successfully!\n", b.title);
            } else {
                printf("\nNotice: This book is already issued to another user.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nError: Book ID %d not found in records.\n", targetId);
    }
    fclose(file);
}


void returnBook() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (file == NULL) {
        printf("\nSystem database missing or empty.\n");
        return;
    }

    int targetId, found = 0;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &targetId);

    Book b;
    while (fread(&b, sizeof(Book), 1, file)) {
        if (b.id == targetId) {
            found = 1;
            if (b.available == 0) {
                b.available = 1; 
                
                fseek(file, -sizeof(Book), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, file);
                
                printf("\nSuccess: The book '%s' has been safely returned to inventory!\n", b.title);
            } else {
                printf("\nNotice: According to our records, this book was never issued.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nError: Book ID %d not found in records.\n", targetId);
    }
    fclose(file);
}
