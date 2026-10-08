#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student structure definition
struct Student {
    int roll;
    char name[50];
    float marks;
};

// Functions list
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// 1. Record add karne ke liye
void addStudent() {
    FILE *fp = fopen("students.txt", "a"); // "a" mode for append
    struct Student s;

    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    // Save data to file
    fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    fclose(fp);

    printf("Student added successfully!\n");
}

// 2. Sabhi records dekhne ke liye
void displayStudents() {
    FILE *fp = fopen("students.txt", "r"); // "r" mode for read
    struct Student s;

    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n--- All Student Records ---\n");
    printf("Roll\tName\t\tMarks\n");
    printf("----------------------------\n");

    while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        printf("%d\t%s\t\t%.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}

// 3. Roll number se search karne ke liye
void searchStudent() {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;
    int rollToSearch, found = 0;

    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollToSearch);

    while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        if (s.roll == rollToSearch) {
            printf("\nRecord Found!");
            printf("\nRoll : %d\nName : %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollToSearch);
    }

    fclose(fp);
}

// 4. Record delete karne ke liye
void deleteStudent() {
    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w"); // Temporary file to write remaining data
    struct Student s;
    int rollToDelete, found = 0;

    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &rollToDelete);

    while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        if (s.roll == rollToDelete) {
            found = 1; // Skip writing this student to temp file
        } else {
            fprintf(temp, "%d %s %.2f\n", s.roll, s.name, s.marks);
        }
    }

    fclose(fp);
    fclose(temp);

    // Old file delete karo aur temp file ko original name do
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        printf("Student record deleted successfully!\n");
    } else {
        printf("Roll Number %d not found!\n", rollToDelete);
    }
}
