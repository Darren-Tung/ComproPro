#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct class
{
    char name[20];
    int numberOfSessionsPresent;
    float attendanceRate;
    int status;

    //TODO: integrate with darren
    char grade;
    float mark;
}

int main(void)
{
    //INITIALISING VARIABLES
    int numberOfStudents         = 0;
    int numberOfSessions         = 0;
    int numberOfSessionsPresent  = 0;
    float attendanceRate         = 0.0;
    int numberOfStudentsDebarred = 0;
    int presenceChecker = 0;
    float sum;


    //INPUT NUMBER OF STUDENTS, SESSIONS
    printf("Welcome to the Attendance Calculator");
    printf("\nFirstly, how many names are you recording:");                           
    scanf("%d", &numberOfStudents);

    //INITIALISING STRUCTURES FOR STUDENTS
    struct class student[numberOfStudents];

    printf("There are %d student(s) in the class\n", numberOfStudents);

    if(numberOfStudents == 0)
    {
        printf("ERROR MESSAGE: 0 Students entered.\n");
        printf("Please try again");
    }

    //INPUT NAMES OF STUDENTS

    int z = 0, b = 0, y = 0;

    while (z != numberOfStudents)
    {
        printf("\nEnter the name of Student %d:", z+1);

        fflush(stdin);
  
        gets(student[z].name);

        //to check length of name

        b = strlen(student[z].name);

        y = b++;

        //adding a character to fix memory dump

        student[z].name[y] = '\0';

        z++;
    }
    printf("The following student(s) are in the class:\n");


    for(int a = 0; a != numberOfStudents; a++)
    {
        printf("%s\n", student[a].name);
    }

    //INPUT Number of lessons

    printf("How many lesson(s) do you have for your module in the term:");
    
    scanf("%d", &numberOfSessions);

    printf("You have %d lessons", numberOfSessions);

    printf("\nIf the student is present, enter 1. Else, enter 0.");

    //CHECK for 0 sessions

    if(numberOfSessions == 0)
    {
        printf("\nERROR: 0 Lessons entered\n");

        printf("\nPlease try again");
    }


    for(int c = 0; c != numberOfStudents; c++)
    {
        student[c].numberOfSessionsPresent = 0;

        for(int d = 1; d != numberOfSessions + 1; d++)
        {

           printf("\nIs %s present in Session %d:", student[c].name, d);

           scanf("%d", &presenceChecker);

           if(presenceChecker == 1)
           {
                student[c].numberOfSessionsPresent += 1;
                presenceChecker = 0;
           }
        }
    }


    //PROCESS for attendance rate

    for(int e = 0; e!= numberOfStudents; e++)
    {
        student[e].attendanceRate = 100.0 * (((float)student[e].numberOfSessionsPresent)/(numberOfSessions));

        if(student[e].attendanceRate < 80.00)
        {
            student[e].status = 1;

            numberOfStudentsDebarred++;
        }
        else
        {
            student[e].status = 0;
        }
    }


    printf("\nNow, we will proceed to the grade recorder.");
    for (int n = 0;n != numberOfStudents;n++)
    {
        float highest = 0.0;

        printf("\nEnter the mark for %s: ", student[n].name);
        scanf(" %f",&student[n].mark);
        

        if (student[n].mark >= 80)
            student[n].grade='A';

        else if (student[n].mark >= 70)
            student[n].grade='B';

        else if (student[n].mark >= 60)
            student[n].grade='C';

        else if (student[n].mark >= 50)
            student[n].grade='D';

        else 
            student[n].grade='F';

        
        sum   = sum + student[n].mark;

        if (student[n].mark > highest)
        {
            highest = student[n].mark;
        }
    }


    //OUTPUT

    printf("\n\n%-10s%20s%24s\n", "Name", "AttendanceRate","Status");


    for(int f = 0; f != numberOfStudents; f++)
    {
        if(student[f].status == 1)
        {
            printf("%-10s      %-20.2f          %10s  \n", student[f].name, student[f].attendanceRate, "DEBARRED");
        }
        else
        {
            printf("%-10s      %-20.2f                \n",student[f].name, student[f].attendanceRate);
        }
    }

    if(numberOfStudentsDebarred > 0.001)
    {
        printf("\nThere are %d student(s) who are debarred due to poor attendance.\n", numberOfStudentsDebarred);

        printf("\nLIST OF STUDENTS WHO ARE DEBARRED\n");
        for(int g = 0; g != numberOfStudents ; g++)
        {
            if(student[g].status == 1)
            {
                printf("%s\n", student[g].name);
            }
        }
    }
    else
    {
        printf("\nThere are no students who are debarred due to poor attendance.");
    }
}


/* SAMPLE TEXT

Welcome to the Attendance Recorder

Firstly, how many names are you recording
3(input on number of names)

There are 3 student(s) in the class

Enter the name of Student 1

Tom

Enter the name of Student 2

Harry

Enter the name of Student 3

Dominic

The following students are in the class
Tom
Harry
Dominic

How many lesson(s) do you have for your subject?
1(input n number of sessions)

You have 1 lesson(s)

Is Tom present in Session 1?
If so, enter 1. Else, enter 0.
1

Is Harry present in Session 1?
If so,, enter 1. Else, enter 0.
0

Is Dominic present in Session 1?
If so, enter 1. Else, enter 0.
1.

Name  AttendanceRate  Status
Tom   100.0
Harry 0.0             DEBARRED
Dominic 100.0
(not exact output)

LIST OF STUDENTS WHO ARE DEBARRED
Harry
*/
