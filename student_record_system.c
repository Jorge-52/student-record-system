#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 100

// Define the student structure
typedef struct {
    char name[NAME_LENGTH];
    int rollNo;
    float gpa;
} Student;

// Function declarations
void addStudents(Student* students, int count);
void displayStudents(Student* students, int count);
void updateGPA(Student* students, int count);
void sortByGPA(Student* students, int count);

int main() {
    int count;
    printf("Enter number of students: ");
    scanf("%d", &count);

    // Dynamically allocate memory for students
    Student* students = (Student*)malloc(count * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input, display, update, sort
    addStudents(students, count);

    printf("\nStudent Records:\n");
    displayStudents(students, count);

    updateGPA(students, count);

    printf("\nUpdated Records:\n");
    displayStudents(students, count);

    printf("\nSorted Records by GPA (Descending):\n");
    sortByGPA(students, count);
    displayStudents(students, count);

    // Free allocated memory
    free(students);

    return 0;
}

void addStudents(Student* students, int count) {
    for (int i = 0; i < count; ++i) {
        printf("Enter data for student %d:\n", i + 1);
        printf("Name: ");
        getchar();  // Clear newline from input buffer
        fgets(students[i].name, NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline

        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);

        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }
}

void displayStudents(Student* students, int count) {
    for (int i = 0; i < count; ++i) {
        printf("Name: %s, Roll No: %d, GPA: %.2f\n",
               students[i].name, students[i].rollNo, students[i].gpa);
    }
}

void updateGPA(Student* students, int count) {
    int roll;
    float newGPA;
    printf("\nEnter roll number to update GPA: ");
    scanf("%d", &roll);

    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (students[i].rollNo == roll) {
            printf("Enter new GPA: ");
            scanf("%f", &newGPA);
            students[i].gpa = newGPA;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", roll);
    }
}

void sortByGPA(Student* students, int count) {
    Student temp;
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (students[i].gpa < students[j].gpa) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}