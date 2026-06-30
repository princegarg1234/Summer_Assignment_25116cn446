#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100


struct Employee {
    int id;
    char name[50];
    char designation[30];
    float basic_salary;
    float hra;         
    float da;           
    float pf;           
    float gross_salary;
    float net_salary;
};


struct Employee empList[MAX_EMPLOYEES];
int empCount = 0;


void addEmployee();
void displayAll();
void searchEmployee();
void calculateSalary(struct Employee *emp);

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n     SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Salary Slips");
        printf("\n3. Search Employee by ID");
        printf("\n4. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("\nExiting the system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}


void calculateSalary(struct Employee *emp) {
    
    emp->hra = emp->basic_salary * 0.15;
    emp->da = emp->basic_salary * 0.20;
    emp->pf = emp->basic_salary * 0.12;
    
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    emp->net_salary = emp->gross_salary - emp->pf;
}

void addEmployee() {
    if (empCount >= MAX_EMPLOYEES) {
        printf("\nSystem database full! Cannot add more employees.\n");
        return;
    }

    struct Employee newEmp;
    
    printf("\nEnter Employee ID (Integer): ");
    scanf("%d", &newEmp.id);
    
    
    for (int i = 0; i < empCount; i++) {
        if (empList[i].id == newEmp.id) {
            printf("\nError: Employee ID %d already exists!\n", newEmp.id);
            return;
        }
    }

    printf("Enter Employee Name: ");
    getchar(); 
    fgets(newEmp.name, sizeof(newEmp.name), stdin);
    newEmp.name[strcspn(newEmp.name, "\n")] = '\0'; 

    printf("Enter Designation: ");
    fgets(newEmp.designation, sizeof(newEmp.designation), stdin);
    newEmp.designation[strcspn(newEmp.designation, "\n")] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%f", &newEmp.basic_salary);

    
    calculateSalary(&newEmp);

    
    empList[empCount] = newEmp;
    empCount++;

    printf("\nRecord added successfully!\n");
}


void displayAll() {
    if (empCount == 0) {
        printf("\nNo records found in the database.\n");
        return;
    }

    for (int i = 0; i < empCount; i++) {
        printf("\n------------------------------------------------");
        printf("\n               SALARY SLIP                      ");
        printf("\n------------------------------------------------");
        printf("\nID          : %d", empList[i].id);
        printf("\nName        : %s", empList[i].name);
        printf("\nDesignation : %s", empList[i].designation);
        printf("\n------------------------------------------------");
        printf("\nBasic Pay   : %.2f", empList[i].basic_salary);
        printf("\nHRA (15%%)   : %.2f", empList[i].hra);
        printf("\nDA (20%%)    : %.2f", empList[i].da);
        printf("\nGross Salary: %.2f", empList[i].gross_salary);
        printf("\n------------------------------------------------");
        printf("\nPF Ded.(12%%): %.2f", empList[i].pf);
        printf("\n------------------------------------------------");
        printf("\nNET PAY     : %.2f", empList[i].net_salary);
        printf("\n------------------------------------------------\n");
    }
}


void searchEmployee() {
    if (empCount == 0) {
        printf("\nNo records found in the database.\n");
        return;
    }

    int searchId;
    int found = 0;
    
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < empCount; i++) {
        if (empList[i].id == searchId) {
            found = 1;
            printf("\n------------------------------------------------");
            printf("\n               RECORD FOUND                     ");
            printf("\n------------------------------------------------");
            printf("\nID          : %d", empList[i].id);
            printf("\nName        : %s", empList[i].name);
            printf("\nDesignation : %s", empList[i].designation);
            printf("\nBasic Pay   : %.2f", empList[i].basic_salary);
            printf("\nGross Salary: %.2f", empList[i].gross_salary);
            printf("\nNet Pay     : %.2f", empList[i].net_salary);
            printf("\n------------------------------------------------\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
}
