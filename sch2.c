#include <stdio.h>
#include <string.h>

typedef struct student {
    int roll_no;
    char name[50];
    char program[20];
    char course[4][20];
    int sub_marks[4];
    int total;
    int average;
} student;

int flag = 0;
int i,j;
void display(student students[], int n) {
    printf("\nStudent List:\n");
    printf("%-10s %-20s %-10s %-20s %-20s %-10s %-10s\n",
           "Roll No", "Name", "Program", "Courses", "Sub Marks", "Total", "Average");

    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10s ", students[i].roll_no, students[i].name, students[i].program);
        for (j = 0; j < 4; j++) printf("%s ", students[i].course[j]);
        printf("     ");
        for (j = 0; j < 4; j++) printf("%d ", students[i].sub_marks[j]);
		printf("     ");
        printf("%-10d %-10d\n", students[i].total, students[i].average);
    }
}
void search(student students[], int n) {
    int search_roll;
    printf("\nEnter roll number to search: ");
    scanf("%d", &search_roll);

    for (i = 0; i < n; i++) {
        if (students[i].roll_no == search_roll) {
            printf("\nStudent Information:\n");
            printf("Name: %s\n", students[i].name);
            printf("Program: %s\n", students[i].program);
            printf("Courses: ");
            for (j = 0; j < 4; j++)
                printf("%s ", students[i].course[j]);
            printf("\nSubject Marks: ");
            for (j = 0; j < 4; j++)
                printf("%d ", students[i].sub_marks[j]);
            printf("\nTotal: %d\n", students[i].total);
            printf("Average: %d\n", students[i].average);
            flag = 1;
            break;
        }
    }

    if (!flag)
        printf("Student not found.\n");
}


void sort(student students[], int n) {
    student temp;
	
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Student List:\n");
    display(students, n);
}
void add_new_student(student students[], int *n) {
    if (*n >= 100) {
        printf("Cannot add more students. Max limit reached.\n");
        return;
    }

     i = *n;
    printf("\nEnter info for New Student:\n");
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("Roll Number: ");
    scanf("%d", &students[i].roll_no);
    printf("Program: ");
    scanf("%s", students[i].program);

    students[i].total = 0;
    for (j = 0; j < 4; j++) {
        printf("Course %d Name: ", j + 1);
        scanf("%s", students[i].course[j]);
        printf("Marks for %s: ", students[i].course[j]);
        scanf("%d", &students[i].sub_marks[j]);
        students[i].total += students[i].sub_marks[j];
    }

    students[i].average = students[i].total / 4;
    (*n)++; 
    printf("New student added successfully!\n");
}
void modify_student_detail(student students[], int n) {
    int roll, found = 0;
    printf("Enter Roll Number of Student to Modify: ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++) {
        if (students[i].roll_no == roll) {
            found = 1;
            printf("\nModifying details for %s (Roll No: %d)\n", students[i].name, roll);
            
            printf("Enter new Name: ");
            scanf("%s", students[i].name);
            
            printf("Enter new Program: ");
            scanf("%s", students[i].program);
            
            students[i].total = 0;
            for (j = 0; j < 4; j++) {
                printf("Enter Course %d Name: ", j + 1);
                scanf("%s", students[i].course[j]);
                printf("Enter Marks for %s: ", students[i].course[j]);
                scanf("%d", &students[i].sub_marks[j]);
                students[i].total += students[i].sub_marks[j];
            }

            students[i].average = students[i].total / 4.0;
            printf("Student details updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}
void append_student(student students[], int *n) {
    if (*n >= 100) {
        printf("Cannot append — student array is full.\n");
        return;
    }

    i = *n;
    printf("\nAppending new student at index %d:\n", i + 1);

    printf("Enter Name: ");
    scanf("%s", students[i].name);

    printf("Enter Roll Number: ");
    scanf("%d", &students[i].roll_no);

    printf("Enter Program: ");
    scanf("%s", students[i].program);

    students[i].total = 0;

    for (j = 0; j < 4; j++) {
        printf("Enter Course %d Name: ", j + 1);
        scanf("%s", students[i].course[j]);

        printf("Enter Marks for %s: ", students[i].course[j]);
        scanf("%d", &students[i].sub_marks[j]);

        students[i].total += students[i].sub_marks[j];
    }

    students[i].average = students[i].total / 4;
    (*n)++;
    printf("Student record appended successfully.\n");
}
int main() {
    int n,choice;
    student students[100];

    printf("How many student records do you want to enter? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter info for Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_no);
        printf("Program: ");
        scanf("%s", students[i].program);

        students[i].total = 0;
        for (j = 0; j < 4; j++) {
            printf("Course %d Name: ", j + 1);
            scanf("%s", students[i].course[j]);
            printf("Marks for %s: ", students[i].course[j]);
            scanf("%d", &students[i].sub_marks[j]);
            students[i].total += students[i].sub_marks[j];
        }

        students[i].average = students[i].total / 4;
    }
	
	while (1) {
    printf("Enter your choice\n");
    printf("Choices are:\n 1. display \n 2. sort \n 3. search \n 4. add new student \n 5. modify \n 6. append \n 7. exit\n");
    printf("Your choice is: ");
    scanf("%d", &choice);

	switch (choice) {
	        case 1:
	            display(students, n);
	            break;
	        case 2:
	            sort(students, n);
	            break;
	        case 3:
	            search(students, n);
	            break;
	        case 4:
	            add_new_student(students, &n);
	            break;
	        case 5:
	            modify_student_detail(students, n);
	            break;
	        case 6:
	            append_student(students, &n);
	            break;
	        case 7:
	            printf("Exiting the program.\n");
	            return 0;
	        default:
	            printf("Invalid choice. Try again.\n");
    }
	}
return 0;
}

