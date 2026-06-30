#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define COURSE_LENGTH 20


struct Student {
    int id;
    char name[NAME_LENGTH];
    char course[COURSE_LENGTH];
    float gpa;
};

struct Student records[MAX_STUDENTS];
int studentCount = 0;


void addStudent();
void displayStudents();
void searchStudent();

int main() {
    int choice;

    do {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}


void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database full! Cannot add more students.\n");
        return;
    }

    struct Student newStudent;

    printf("\nEnter Student ID: ");
    scanf("%d", &newStudent.id);
    
    
    while (getchar() != '\n'); 

    printf("Enter Student Name: ");
    
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; 

    printf("Enter Course: ");
    fgets(newStudent.course, COURSE_LENGTH, stdin);
    newStudent.course[strcspn(newStudent.course, "\n")] = '\0';

    printf("Enter GPA: ");
    scanf("%f", &newStudent.gpa);

    records[studentCount] = newStudent;
    studentCount++;

    printf("Record added successfully!\n");
}


void displayStudents() {
    if (studentCount == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-10s %-25s %-15s %-5s\n", "ID", "Name", "Course", "GPA");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-25s %-15s %-5.2f\n", 
               records[i].id, records[i].name, records[i].course, records[i].gpa);
    }
}


void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo records to search.\n");
        return;
    }

    int searchId;
    int found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < studentCount; i++) {
        if (records[i].id == searchId) {
            printf("\nRecord Found!\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Course: %s\n", records[i].course);
            printf("GPA: %.2f\n", records[i].gpa);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", searchId);
    }
}
