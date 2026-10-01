/*
 * Student Record Management System
 * Demonstrates: Structure, Array, Functions, File Handling (basic level)
 */

#include <stdio.h>
#include <string.h>

#define MAX 50   // maximum number of students

// ---------- Structure ----------
struct Student {
    int roll;
    char name[50];
    float marks;
};

// ---------- Function Prototypes ----------
int addStudent(struct Student arr[], int count);
void displayStudents(struct Student arr[], int count);
void saveToFile(struct Student arr[], int count);
int loadFromFile(struct Student arr[]);

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    // Load existing records from file (if any) when program starts
    count = loadFromFile(students);

    do {
        printf("\n----- Student Record Menu -----\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Save Records to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addStudent(students, count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                saveToFile(students, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// ---------- Add a new student to the array ----------
int addStudent(struct Student arr[], int count) {
    if (count >= MAX) {
        printf("Record list is full!\n");
        return count;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &arr[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", arr[count].name);   // reads full name with spaces

    printf("Enter Marks: ");
    scanf("%f", &arr[count].marks);

    count++;
    printf("Student added successfully!\n");
    return count;
}

// ---------- Display all students from the array ----------
void displayStudents(struct Student arr[], int count) {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", arr[i].roll, arr[i].name, arr[i].marks);
    }
}

// ---------- Save array data to a file ----------
void saveToFile(struct Student arr[], int count) {
    FILE *fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%.2f\n", arr[i].roll, arr[i].name, arr[i].marks);
    }

    fclose(fp);
    printf("Records saved to students.txt successfully!\n");
}

// ---------- Load array data from a file ----------
int loadFromFile(struct Student arr[]) {
    FILE *fp = fopen("students.txt", "r");
    int count = 0;

    if (fp == NULL) {
        // File doesn't exist yet, that's okay on first run
        return 0;
    }

    while (fscanf(fp, "%d,%[^,],%f\n", &arr[count].roll, arr[count].name, &arr[count].marks) == 3) {
        count++;
        if (count >= MAX) break;
    }

    fclose(fp);
    return count;
}