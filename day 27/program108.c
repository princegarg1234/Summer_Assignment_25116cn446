#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 5
#define PASS_MARKS 33


struct Subject {
    char name[30];
    int max_marks;
    int obtained_marks;
};


struct Student {
    char name[50];
    int roll_no;
    char class_name[10];
    struct Subject subs[MAX_SUBJECTS];
    int total_max;
    int total_obtained;
    float percentage;
    char grade[5];
    int failed_count;
};


void calculateGrade(struct Student *s) {
    if (s->failed_count > 0) {
        strcpy(s->grade, "FAIL");
    } else if (s->percentage >= 85.0) {
        strcpy(s->grade, "A+");
    } else if (s->percentage >= 75.0) {
        strcpy(s->grade, "A");
    } else if (s->percentage >= 60.0) {
        strcpy(s->grade, "B");
    } else if (s->percentage >= 50.0) {
        strcpy(s->grade, "C");
    } else if (s->percentage >= 33.0) {
        strcpy(s->grade, "D");
    } else {
        strcpy(s->grade, "F");
    }
}

int main() {
    struct Student s;
    s.total_max = 0;
    s.total_obtained = 0;
    s.failed_count = 0;

    
    char default_subjects[MAX_SUBJECTS][30] = {
        "Mathematics", 
        "Physics", 
        "Chemistry", 
        "English", 
        "Computer Science"
    };

    printf("===========================================\n");
    printf("     STUDENT MARKSHEET GENERATION SYSTEM   \n");
    printf("===========================================\n\n");

    
    printf("Enter Student Full Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; 

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll_no);

    printf("Enter Class/Standard: ");
    scanf("%s", s.class_name);
    
    printf("\n--- Enter Marks (Minimum Passing: %d) ---\n", PASS_MARKS);

    
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        strcpy(s.subs[i].name, default_subjects[i]);
        s.subs[i].max_marks = 100; 

        do {
            printf("Enter marks for %s (0-100): ", s.subs[i].name);
            scanf("%d", &s.subs[i].obtained_marks);
            
            if (s.subs[i].obtained_marks < 0 || s.subs[i].obtained_marks > 100) {
                printf("[Error] Marks must be between 0 and 100. Try again.\n");
            }
        } while (s.subs[i].obtained_marks < 0 || s.subs[i].obtained_marks > 100);

        s.total_max += s.subs[i].max_marks;
        s.total_obtained += s.subs[i].obtained_marks;
        
        if (s.subs[i].obtained_marks < PASS_MARKS) {
            s.failed_count++;
        }
    }

    
    s.percentage = ((float)s.total_obtained / s.total_max) * 100;
    calculateGrade(&s);

    
    printf("\n\n=======================================================\n");
    printf("                   OFFICIAL MARKSHEET                  \n");
    printf("=======================================================\n");
    printf(" Name: %-25s Roll No: %-10d\n", s.name, s.roll_no);
    printf(" Class: %-24s Status: %-10s\n", s.class_name, (s.failed_count == 0) ? "PASSED" : "FAILED");
    printf("-------------------------------------------------------\n");
    printf(" %-20s | %-12s | %-12s\n", "SUBJECT NAME", "MAX MARKS", "OBTAINED MARKS");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf(" %-20s | %-12d | %-12d %s\n", 
               s.subs[i].name, 
               s.subs[i].max_marks, 
               s.subs[i].obtained_marks,
               (s.subs[i].obtained_marks < PASS_MARKS) ? "*" : " ");
    }

    printf("-------------------------------------------------------\n");
    printf(" %-20s | %-12d | %-12d\n", "TOTAL METRICS", s.total_max, s.total_obtained);
    printf("-------------------------------------------------------\n");
    printf(" Aggregate Percentage: %.2f%%\n", s.percentage);
    printf(" Assigned Final Grade: %s\n", s.grade);
    if (s.failed_count > 0) {
        printf(" Note: (*) Indicates failure in that respective course.\n");
    }
    printf("=======================================================\n");

    return 0;
}
