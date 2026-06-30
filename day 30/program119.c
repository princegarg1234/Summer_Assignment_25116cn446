#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"


typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;


void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();
void updateEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== MINI EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Employee Records\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee Record\n");
        printf("5. Delete Employee Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("Exiting program. Thank you!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}


void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); 

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; 

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);

    printf("Employee record added successfully!\n");
}


void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb"); 
    if (fp == NULL) {
        printf("\nNo records found. Please add an employee first.\n");
        return;
    }

    Employee emp;
    printf("\n--------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("--------------------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }
    printf("--------------------------------------------------------------\n");
    fclose(fp);
}

void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Designation: %s\n", emp.designation);
            printf("Salary: %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}


void updateEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+"); 
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int updateId, found = 0;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &updateId);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == updateId) {
            found = 1;
            getchar(); 

            printf("Enter New Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);

            
            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("Record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", updateId);
    }
    fclose(fp);
}


void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    FILE *tempFp = fopen("temp.dat", "wb"); 
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int deleteId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == deleteId) {
            found = 1; 
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);            
        rename("temp.dat", FILE_NAME); 
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("Employee with ID %d not found.\n", deleteId);
    }
}
