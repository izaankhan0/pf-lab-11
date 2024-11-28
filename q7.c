#include <stdio.h>
#include <string.h>

struct Course {
    char course_id[20];
    char course_name[100];
    char instructor_name[100];
    int credits;
};

struct Department {
    char department_name[100];
    struct Course courses[100];
    int course_count;
};

int main() {
    struct Department departments[10];
    int department_count = 0;

    while (1) {
        int choice;
        printf("\n1. Add Department\n2. Add Course to Department\n3. Display Departments and Courses\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter department name: ");
            scanf(" %[^\n]", departments[department_count].department_name);
            departments[department_count].course_count = 0;
            department_count++;
        } else if (choice == 2) {
            char dep_name[100];
            printf("Enter department name: ");
            scanf(" %[^\n]", dep_name);

            int found = -1;
            for (int i = 0; i < department_count; i++) {
                if (strcmp(dep_name, departments[i].department_name) == 0) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                struct Course *course = &departments[found].courses[departments[found].course_count];
                printf("Enter course ID: ");
                scanf(" %[^\n]", course->course_id);
                printf("Enter course name: ");
                scanf(" %[^\n]", course->course_name);
                printf("Enter instructor name: ");
                scanf(" %[^\n]", course->instructor_name);
                printf("Enter credits: ");
                scanf("%d", &course->credits);

                departments[found].course_count++;
            } else {
                printf("Department not found.\n");
            }
        } else if (choice == 3) {
            for (int i = 0; i < department_count; i++) {
                printf("\nDepartment: %s\n", departments[i].department_name);
                for (int j = 0; j < departments[i].course_count; j++) {
                    struct Course *course = &departments[i].courses[j];
                    printf("  Course ID: %s, Name: %s, Instructor: %s, Credits: %d\n",
                           course->course_id, course->course_name, course->instructor_name, course->credits);
                }
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
