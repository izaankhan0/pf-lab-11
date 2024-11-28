#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    int id;
};

struct Course {
    char course_id[20];
    char course_name[100];
    char instructor_name[100];
    int credits;
    struct Student students[100];
    int student_count;
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
        printf("\n1. Add Department\n2. Add Course to Department\n3. Add Student to Course\n4. Display Departments\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (department_count >= 10) {
                printf("Cannot add more departments.\n");
                continue;
            }
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
                struct Department *dep = &departments[found];
                if (dep->course_count >= 100) {
                    printf("Cannot add more courses to this department.\n");
                    continue;
                }

                struct Course *course = &dep->courses[dep->course_count];
                printf("Enter course ID: ");
                scanf(" %[^\n]", course->course_id);
                printf("Enter course name: ");
                scanf(" %[^\n]", course->course_name);
                printf("Enter instructor name: ");
                scanf(" %[^\n]", course->instructor_name);
                printf("Enter credits: ");
                scanf("%d", &course->credits);
                course->student_count = 0;

                dep->course_count++;
            } else {
                printf("Department not found.\n");
            }
        } else if (choice == 3) {
            char dep_name[100], course_id[20];
            printf("Enter department name: ");
            scanf(" %[^\n]", dep_name);
            printf("Enter course ID: ");
            scanf(" %[^\n]", course_id);

            int dep_index = -1, course_index = -1;
            for (int i = 0; i < department_count; i++) {
                if (strcmp(dep_name, departments[i].department_name) == 0) {
                    dep_index = i;
                    break;
                }
            }

            if (dep_index != -1) {
                struct Department *dep = &departments[dep_index];
                for (int j = 0; j < dep->course_count; j++) {
                    if (strcmp(course_id, dep->courses[j].course_id) == 0) {
                        course_index = j;
                        break;
                    }
                }

                if (course_index != -1) {
                    struct Course *course = &dep->courses[course_index];
                    if (course->student_count >= 100) {
                        printf("Cannot add more students to this course.\n");
                        continue;
                    }

                    struct Student *student = &course->students[course->student_count];
                    printf("Enter student name: ");
                    scanf(" %[^\n]", student->name);
                    printf("Enter student ID: ");
                    scanf("%d", &student->id);

                    course->student_count++;
                } else {
                    printf("Course not found.\n");
                }
            } else {
                printf("Department not found.\n");
            }
        } else if (choice == 4) {
            for (int i = 0; i < department_count; i++) {
                struct Department *dep = &departments[i];
                printf("\nDepartment: %s\n", dep->department_name);
                for (int j = 0; j < dep->course_count; j++) {
                    struct Course *course = &dep->courses[j];
                    printf("  Course ID: %s, Name: %s, Instructor: %s, Credits: %d\n",
                           course->course_id, course->course_name, course->instructor_name, course->credits);
                    printf("    Students:\n");
                    for (int k = 0; k < course->student_count; k++) {
                        struct Student *student = &course->students[k];
                        printf("      Name: %s, ID: %d\n", student->name, student->id);
                    }
                }
            }
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
