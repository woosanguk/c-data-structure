#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_STUDENT 5

struct student_score {
    char name[30];
    float korean;
    float english;
    float math;
    float avg;
};

struct student_score createStudent(char *name, float korean, float english, float math) {
    struct student_score student = {0};
    strcpy(student.name, name);
    student.korean = korean;
    student.english = english;
    student.math = math;
    student.avg = (korean + english + math) / 3;
    return student;
}

int main() {
    struct student_score *ptr_student_new = (struct student_score *) malloc(
            sizeof(struct student_score) * NUMBER_OF_STUDENT);
    struct student_score student;
    student = createStudent("lee", 81, 79, 99);
    ptr_student_new[0] = student;
    student = createStudent("kim", 80, 82, 79);
    ptr_student_new[1] = student;
    student = createStudent("Park", 79, 85, 75);
    ptr_student_new[2] = student;
    student = createStudent("hong", 75, 87, 82);
    ptr_student_new[3] = student;
    student = createStudent("jung", 90, 89, 65);
    ptr_student_new[4] = student;

    for (int i = 0; i < NUMBER_OF_STUDENT; i++) {
        printf("name = %s, avg = %f\n", ptr_student_new[i].name, ptr_student_new[i].avg);
    }

    return 0;
}