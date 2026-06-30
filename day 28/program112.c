#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.dat"


typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

void addContact();
void viewContacts();
void searchContact();
void deleteContact();
void flushInput();

int main() {
    int choice;

    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            flushInput();
            continue;
        }
        flushInput(); 

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}


void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void addContact() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Contact newContact;

    printf("Enter Name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';

    printf("Enter Phone Number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("Enter Email Address: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    fwrite(&newContact, sizeof(Contact), 1, file);
    fclose(file);

    printf("Contact saved successfully!\n");
}

void viewContacts() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo contacts found. The list is empty!\n");
        return;
    }

    Contact temp;
    int count = 1;

    printf("\n---------------------------------------------------------------\n");
    printf("%-5s %-20s %-15s %-25s\n", "S.No", "Name", "Phone", "Email");
    printf("---------------------------------------------------------------\n");

    while (fread(&temp, sizeof(Contact), 1, file) == 1) {
        printf("%-5d %-20s %-15s %-25s\n", count++, temp.name, temp.phone, temp.email);
    }
    printf("---------------------------------------------------------------\n");

    fclose(file);
}


void searchContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo contacts available to search.\n");
        return;
    }

    char searchName[50];
    Contact temp;
    int found = 0;

    printf("Enter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fread(&temp, sizeof(Contact), 1, file) == 1) {
        
        if (strcasecmp(temp.name, searchName) == 0) { 
            printf("\nContact Found:\n");
            printf("Name:  %s\n", temp.name);
            printf("Phone: %s\n", temp.phone);
            printf("Email: %s\n", temp.email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact matching '%s' not found.\n", searchName);
    }

    fclose(file);
}


void deleteContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo contacts available to delete.\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("System error. Cannot proceed with deletion.\n");
        fclose(file);
        return;
    }

    char targetName[50];
    Contact temp;
    int found = 0;

    printf("Enter the name of the contact to delete: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';

    
    while (fread(&temp, sizeof(Contact), 1, file) == 1) {
        if (strcasecmp(temp.name, targetName) == 0) {
            found = 1; 
        } else {
            fwrite(&temp, sizeof(Contact), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);             
        rename("temp.dat", FILE_NAME); 
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.dat");            
        printf("Contact matching '%s' not found.\n", targetName);
    }
}
