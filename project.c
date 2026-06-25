#include <stdio.h>

typedef struct{
    char name[50];
    int id;
    float scores[3];
    float average;
    char grade;

}Student;

void addStudent(Student students[], int *count);
void enterScores(Student students[], int count);
void calculateAveragesAndGrades(Student students[], int count);
void showAllStudents(Student students[], int count);

int main(){

    Student students[100];   // Creates a list that can store upto 100 students;
    int count = 0;           // Tracks how many students added so far;

    int choice = 0;          // Menu loop;

    printf("\n*** STUDENTS' GRADEBOOK ***\n");

    do{
    printf("\n1. Add student\n");
    printf("2. Enter/Update scores\n");
    printf("3. Calculate averages and grades\n");
    printf("4. Show all students\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            addStudent(students, &count);
            break;
        case 2:
            enterScores(students, count);
            break;
        case 3:
            calculateAveragesAndGrades(students, count);
            break;
        case 4:
            showAllStudents(students, count);
            break;
        case 0:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.");
            break;
    }    


    }while(choice != 0);

    return 0;
}

void addStudent(Student students[], int *count){
    if(*count >=100){
        printf("Cannot add more students. Maximum capacity reached.\n");
        return;
    }

    Student s;     // Gives an empty student form;

    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter student ID: ");
    scanf("%d", &s.id);


    s.scores[0] = 0.0f;
    s.scores[1] = 0.0f;
    s.scores[2] = 0.0f;

    s.average = 0.0f;
    s.grade = '\0';

    students[*count] = s;

    (*count)++;

    printf("\nStudent added successfully.\n");

}

void enterScores(Student students[], int count){

    int id;
    int found = 0;
    int i;

    printf("Enter student ID: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++){
        if(students[i].id == id){
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Student not found.\n");
        return;
    }

    printf("Enter score for exam 1: ");
    scanf("%f", &students[i].scores[0]);

    printf("Enter score for exam 2: ");
    scanf("%f", &students[i].scores[1]);

    printf("Enter score for exam 3: ");
    scanf("%f", &students[i].scores[2]);

    printf("Scores updated for student %s (ID %d).\n", students[i].name, students[i].id);


}

void calculateAveragesAndGrades(Student students[], int count){
    int i;

    if(count == 0){
        printf("No students to process.\n");
        return;
    }

    for(i = 0; i < count; i++){
        students[i].average = (students[i].scores[0] + 
                               students[i].scores[1] +
                               students[i].scores[2]) / 3.0f;

        if(students[i].average >= 90.0f){
            students[i].grade = 'A';
        }
        else if(students[i].average >= 80.0f){
            students[i].grade = 'B';
        }
        else if(students[i].average >= 70.0f){
            students[i].grade = 'C';
        }
        else if(students[i].average >= 60.0f){
            students[i].grade = 'D';
        }
        else{
            students[i].grade = 'F';
        }
    }

    printf("Averages and grades calculated for %d student(s).\n", count);

}

void showAllStudents(Student students[], int count){
    int i;

    if(count == 0){
        printf("No students to show.\n");
        return;
    }

    printf("\n==== All Students ====\n"); //Show all students;
    
    for(i = 0; i < count; i++){
        printf("\nStudent #%d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].id);
        printf("Scores: %.2f, %.2f, %.2f\n", 
                students[i].scores[0],
                students[i].scores[1],
                students[i].scores[2]);
        printf("Average: %.2f\n", students[i].average);
        printf("Grade: %c\n", students[i].grade);
    }

}