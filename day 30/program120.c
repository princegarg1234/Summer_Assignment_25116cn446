#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50


void displayMenu();
void addStudent(char names[][MAX_NAME_LEN], int rollNumbers[], float marks[], int *count);
void displayStudents(char names[][MAX_NAME_LEN], int rollNumbers[], float marks[], int count);
void searchStudent(char names[][MAX_NAME_LEN], int rollNumbers[], float marks[], int count);

int main() {
    
    char studentNames[MAX_STUDENTS][MAX_NAME_LEN];
    int rollNumbers[MAX_STUDENTS];
    float marks[MAX_STUDENTS];
    
    int studentCount = 0; 
    int choice;

    printf("=== Welcome to the Student Database Management System ===\n");

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type. Exiting program.\n");
            break;
        }


        getchar(); 

        switch (choice) {
            case 1:
                addStudent(studentNames, rollNumbers, marks, &studentCount);
                break;
            case 2:
                displayStudents(studentNames, rollNumbers, marks, studentCount);
                break;
            case 3:
                searchStudent(studentNames, rollNumbers, marks, studentCount);
                break;
            case 4:
                printf("\nThank you for using the system. Goodbye!\n");
                return 0;
            default:
                printf("\n[Error] Invalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}


void displayMenu() {
    printf("\n-----------------------------\n");
    printf("1. Add New Student Record\n");
    printf("2. Display All Student Records\n");
    printf("3. Search Student by Name\n");
    printf("4. Exit Application\n");
    printf("-----------------------------\n");
}


void addStudent(char names[][MAX_NAME_LEN], int rollNumbers[], float marks[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\n[Error] Database storage capacity is full!\n");
        return;
    }

    printf("\nEnter Student Name: ");
        fgets(names[*count], MAX_NAME_LEN, stdin);
    
  
    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("Enter Roll Number: ");
    scanf("%d", &rollNumbers[*count]);

    printf("Enter GPA/Marks: ");
    scanf("%f", &marks[*count]);

   
    (*count)++; 
    printf("\n[Success] Record added successfully!\n");
}

void displayStudents(char names[][MAX_NAME_LEN], int rollNumbers[], float marks[], int count) {
    if (count == 0) {
        printf("\n[Info] No student records found. Add a record first.\n");
        return;
    }

    printf("\n%-20s %-15s %-10s\n", "Student Name", "Roll Number", "GPA/Marks");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s %-15d %-10.2f\n", names[i], rollNumbers[i], marks[i]);
    }
}


void searchStudent(char names[][MAX_NAME_LEN], int rollNumbers[], float marks[], int count) {
    if (count == 0) {
        printf("\n[Info] The database is completely empty.\n");
        return;
    }

    char searchName[MAX_NAME_LEN];
    int foundStatus = 0;

    printf("\nEnter the exact name of the student to search: ");
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    for (int i = 0; i < count; i++) {
        
        if (strcmp(names[i], searchName) == 0) { 
            printf("\n[Record Found!]");
            printf("\nName:        %s", names[i]);
            printf("\nRoll Number: %d", rollNumbers[i]);
            printf("\nGPA/Marks:   %.2f\n", marks[i]);
            foundStatus = 1;
            break; 
        }
    }

    if (!foundStatus) {
        printf("\n[Result] No match found for student: '%s'.\n", searchName);
    }
}
