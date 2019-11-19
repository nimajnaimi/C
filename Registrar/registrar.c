#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// maximum length for names (student, courses, university)
#define MAX_NAME_LENGTH  20
// maximum number of courses students can be registered for
#define MAX_REGISTERED_COURSES  5
// maximum number of courses at university
#define MAX_COURSES  100
// maximum number of students at university
#define MAX_STUDENTS 1000

// course data type, only has name
typedef struct
{
    char name[MAX_NAME_LENGTH];
} course;

// student data type, has name, registeredCourses[] and numberOfRegisteredCourses
typedef struct
{
    char name[MAX_NAME_LENGTH];
    course * registeredCourses[MAX_REGISTERED_COURSES];
    int numberOfRegisteredCourses;
} student;

// university structure, holds name, courses and students
// numberOfCourses holds how many courses we currently have
// numberOfStudents holds how many students we currently have
typedef struct
{
    char name[MAX_NAME_LENGTH];
    course * courses[MAX_COURSES];
    int numberOfCourses;
    student * students[MAX_STUDENTS];
    int numberOfStudents;
} university;

// given a prompt and int * for choice
// fills the value for choice prompting user multiple times if necessary
void getNumber(char * prompt, int * choice)
{
    printf("%s", prompt);
    int numberOfItemsRead = scanf("%d", choice);
    while (numberOfItemsRead != 1)
    {
        printf("Bad input\n");
        printf("%s", prompt);
        numberOfItemsRead = scanf("%d", choice);
    }
    // choice has correct information
}

// given a prompt and char * for message
// fills the value for message prompting user multiple times if necessary
void getString(char * prompt, char * msg)
{
    printf("%s", prompt);
    int numberOfItemsRead = scanf("%s", msg);
    while (numberOfItemsRead != 1)
    {
        printf("Bad input\n");
        printf("%s", prompt);
        numberOfItemsRead = scanf("%s", msg);
    }
    // msg has correct information
}

// creates a student object, gets name from user
student * makeStudent()
{
    student * aStudent = (student *) malloc(sizeof(student));
    aStudent->numberOfRegisteredCourses = 0;
    getString("Enter the name for student: ", aStudent->name);
    return aStudent;
}

// free the student data that was allocated using malloc
int deleteStudent(student * aStudent)
{
    if (! aStudent)
        return -1;
    free(aStudent);
    return 0;
}

// creates a course object, gets name from user
// similar to makeStudent
course * makeCourse()
{
    course * aCourse = (course *) malloc(sizeof(course));
    getString("Enter the name for course: ", aCourse->name);
    return aCourse;
}

// free the course data that was allocated using malloc
// similar to deleteStudent
int deleteCourse(course * aCourse)
{
    if (! aCourse)
        return -1;
    free(aCourse);
    return 0;
}

// creates a university object, gets name from user
// sets numberOfCourses and numberOfStudents to 0
// similar to makeStudent
university * makeUniversity()
{
    university * aUni = (university *) malloc(sizeof(university));
    aUni->numberOfCourses = 0;
    aUni->numberOfStudents = 0;
    getString("Enter the name for university: ", aUni->name);
    return aUni;
}

// free the university data that was allocated using malloc
// need to free each course in the courses array
// need to free each student in student array
int deleteUniversity(university * aUni)
{
    if (! aUni)
        return -1;
    for (int i = 0; i < aUni->numberOfStudents; i++)
        deleteStudent(aUni->students[i]);
    for (int i = 0; i < aUni->numberOfCourses; i++)
        deleteCourse(aUni->courses[i]);
    free(aUni);
    return 0;
}

// returns a student * from the students array in uni
// returns NULL if a student with the given name is not found
student * getStudent(university * uni)
{
    // get student object
    char studentName[MAX_NAME_LENGTH];
    getString("Enter the name for student: ", studentName);
    for (int i = 0; i < uni->numberOfStudents; i++)
    {
        if (strcmp(studentName, uni->students[i]->name) == 0)
            return uni->students[i];

    }
    return NULL;
}

// returns a course * from the courses array in uni
// returns NULL if a course with the given name is not found
course * getCourse(university * uni)
{
    char courseName[MAX_NAME_LENGTH];
    getString("Enter the name for course: ", courseName);
    for (int i = 0; i < uni->numberOfCourses; i++)
    {
        if (strcmp(courseName, uni->courses[i]->name) == 0)
            return uni->courses[i];

    }
    return NULL;
}
// enroll student at university
// creates a new student and adds it to the students array for university
void enrollStudent(university * uni)
{
    student * aStudent = makeStudent();
    uni->students[uni->numberOfStudents] = aStudent;
    uni->numberOfStudents++;
}

// add a course at university
// creates a new course and adds it to the courses array for university
// similar to enrollStudent
void addCourse(university * uni)
{
    course * aCourse = makeCourse();
    uni->courses[uni->numberOfCourses] = aCourse;
    uni->numberOfCourses++;
}

// Display basic information about the university
void universityInformation(university * uni)
{
    printf("%s has %d courses and %d students\n",
           uni->name, uni->numberOfCourses, uni->numberOfStudents);
}

// list all students at the university
void listAllStudents(university * uni)
{
    printf("Students are: \n");
    for (int i = 0; i < uni->numberOfStudents; i++)
    {
        student * aStudent = uni->students[i];
        printf("%s ", aStudent->name);
    }
    printf("\n");
}

// list all courses at the university
// similar to listAllStudents
void listAllCourses(university * uni)
{
    printf("Courses are: \n");
    for (int i = 0; i < uni->numberOfCourses; i++)
    {
        course * aCourse = uni->courses[i];
        printf("%s ", aCourse->name);
    }
    printf("\n");
}

// get student struct
// get course strruct
// if both student and course structs are found
// add the course to the registeredCourses for the student
void registerStudentForCourse(university * uni)
{
    student * aStudent = getStudent(uni);
    course * aCourse = getCourse(uni);
    if (aStudent != NULL && aCourse != NULL)
    {
        aStudent->registeredCourses[aStudent->numberOfRegisteredCourses] = aCourse;
        aStudent->numberOfRegisteredCourses++;
    }
    printf("Registered %s for %s course\n", aStudent->name, aCourse->name);
}

// helper function for listAllStudentsInCourse
// return true if student is registered for courseName
bool isStudentInCourse(student * aStudent, char * courseName)
{
    for (int i = 0; i < aStudent->numberOfRegisteredCourses; i++)
    {
        if (strcmp(courseName, aStudent->registeredCourses[i]->name) == 0)
        {
            return true;
        }
    }
    return false;
}

// list all students at the university
// that are enrolled in a given course
void listAllStudentsInCourse(university * uni)
{
    course * aCourse = getCourse(uni);
    if (aCourse->name == NULL)
    {
        printf("Could not find course");
    }
    else
    {
        printf("Students enrolled in %s are: \n", aCourse->name);
        for (int i = 0; i < uni->numberOfStudents; i++)
        {
            student * aStudent = uni->students[i];
            if (isStudentInCourse(aStudent, aCourse->name))
            {
                printf("%s ", aStudent->name);
            }
        }
    }
    printf("\n");
}

// main menu for interacting with registration system
void mainMenu(university * uni)
{
    int choice;
    printf("Welcome to the %s menu\n", uni->name);
    printf("1. Display information about the university\n");
    printf("2. List all courses\n");
    printf("3. Add a course\n");
    printf("4. Enroll a new student\n");
    printf("5. List all students\n");
    printf("6. Register a student for a course\n");
    printf("7. List all students enrolled in a course\n");
    printf("10. Exit\n");
    getNumber("Enter command: ", &choice);
    printf("Choice is %d\n", choice);
    switch(choice)
    {
    case 1:
        universityInformation(uni);
        break;
    case 2:
        listAllCourses(uni);
        break;
    case 3:
        addCourse(uni);
        break;
    case 4:
        enrollStudent(uni);
        break;
    case 5:
        listAllStudents(uni);
        break;
    case 6:
        registerStudentForCourse(uni);
        break;
    case 7:
        listAllStudentsInCourse(uni);
        break;
    case 10:
        printf("Thank you for using the Registrar program\n");
        deleteUniversity(uni);
        exit(0);
    default:
        printf("Bad input!");
    }
    printf("\n");
    mainMenu(uni);
}


int main()
{
    university * uni = makeUniversity();
    mainMenu(uni);
    return 0;
}
