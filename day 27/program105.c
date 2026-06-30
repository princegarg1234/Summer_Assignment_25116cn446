#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "student_data.txt"


typedef struct {
    int roll_no;
    char name[50];
    char course[50];
    float gpa;
} Student;

void add_student();
void display_all();
void search_student();
void update_student();
void delete_student();
void clear_input_buffer();

int main() {
    int choice;

    while (1) {
        printf("\n=========================================\n");
        printf("     STUDENT RECORD MANAGEMENT SYSTEM    \n");
        printf("=========================================\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit Program\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1: add_student(); break;
            case 2: display_all(); break;
            case 3: search_student(); break;
            case 4: update_student(); break;
            case 5: delete_student(); break;
            case 6:
                printf("\nExiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}


void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void add_student() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    Student std;
    printf("\n--- Add New Student Record ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &std.roll_no);
    clear_input_buffer();

    printf("Enter Student Name: ");
    fgets(std.name, sizeof(std.name), stdin);
    std.name[strcspn(std.name, "\n")] = '\0'; 

    printf("Enter Course: ");
    fgets(std.course, sizeof(std.course), stdin);
    std.course[strcspn(std.course, "\n")] = '\0'; 

    printf("Enter GPA: ");
    scanf("%f", &std.gpa);

    
    fwrite(&std, sizeof(Student), 1, file);
    fclose(file);

    printf("\nRecord added successfully!\n");
}


void display_all() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo records found! (Database file does not exist yet).\n");
        return;
    }

    Student std;
    int count = 0;

    printf("\n-----------------------------------------------------------------\n");
    printf("%-10s %-25s %-20s %-5s\n", "Roll No", "Name", "Course", "GPA");
    printf("-----------------------------------------------------------------\n");

    
    while (fread(&std, sizeof(Student), 1, file) == 1) {
        printf("%-10d %-25s %-20s %-5.2f\n", std.roll_no, std.name, std.course, std.gpa);
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("The student database file is empty.\n");
    } else {
        printf("-----------------------------------------------------------------\n");
        printf("Total Records: %d\n", count);
    }
}


void search_student() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records available to search.\n");
        return;
    }

    int target_roll;
    int found = 0;
    Student std;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &target_roll);

    while (fread(&std, sizeof(Student), 1, file) == 1) {
        if (std.roll_no == target_roll) {
            found = 1;
            printf("\n--- Record Found ---\n");
            printf("Roll Number : %d\n", std.roll_no);
            printf("Name        : %s\n", std.name);
            printf("Course      : %s\n", std.course);
            printf("GPA         : %.2f\n", std.gpa);
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", target_roll);
    }
}


void update_student() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records available to update.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    int target_roll;
    int found = 0;
    Student std;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &target_roll);

    while (fread(&std, sizeof(Student), 1, file) == 1) {
        if (std.roll_no == target_roll) {
            found = 1;
            printf("\n--- Current Record Details ---\n");
            printf("Name: %s | Course: %s | GPA: %.2f\n", std.name, std.course, std.gpa);
            printf("-------------------------------\n");
            
            clear_input_buffer();
            printf("Enter New Name: ");
            fgets(std.name, sizeof(std.name), stdin);
            std.name[strcspn(std.name, "\n")] = '\0';

            printf("Enter New Course: ");
            fgets(std.course, sizeof(std.course), stdin);
            std.course[strcspn(std.course, "\n")] = '\0';

            printf("Enter New GPA: ");
            scanf("%f", &std.gpa);
        }
        
        fwrite(&std, sizeof(Student), 1, temp);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILE_NAME);        
        rename("temp.txt", FILE_NAME); 
        printf("\nRecord updated successfully!\n");
    } else {
        remove("temp.txt"); // Discard the temp file
        printf("\nStudent with Roll Number %d not found.\n", target_roll);
    }
}


void delete_student() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records available to delete.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    int target_roll;
    int found = 0;
    Student std;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &target_roll);

    while (fread(&std, sizeof(Student), 1, file) == 1) {
        if (std.roll_no == target_roll) {
            found = 1; 
            continue;
        }
        fwrite(&std, sizeof(Student), 1, temp);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("\nRecord deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("\nStudent with Roll Number %d not found.\n", target_roll);
    }
}
