/*Name:Darren Tung Yan Zuo    Class:ES22
  This program allow you to input the students names of 1 subject. It then 
  calculates the average mark and grade
*/


//dont include stuff just because it sounds fancy
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 30
#define MAXSIZE 20

void main(void)
{
    char name[MAXSIZE][MAXLEN];

    char subject[20] , grade[20];

    float marks[20];

    int count = 0;

    int numberOfNames;

    float average, sum = 0.0;

    float highest = 0.0;


    
    printf(" What module do you want to compare? ");

    fflush(stdin);

    gets(subject);

    //scanf("%s",&subject);

    
    printf("\n\n -------------- For %s --------------\n\n",subject);

    printf(" How many students do you want to compare [1 to %d] ? ",MAXSIZE);

    fflush(stdin);
    scanf(" %f",&numberOfNames);
    
    for (int n = 0;n != numberOfNames;n++)
    {
        printf(" Student %d\n",n+1);

        printf("     Enter name: ");
        gets( name[n] );

        printf("     Enter marks: ");
        scanf(" %f",&marks[n]);
        

        if (marks[n] >= 80)
            grade[n]='A';
        else if (marks[n] >= 70)
            grade[n]='B';
        else if (marks[n] >= 60)
            grade[n]='C';
        else if (marks[n] >= 50)
            grade[n]='D';
        else 
            grade[n]='F';

        count = count + 1;
        sum   = sum + marks[n];

        if (marks[n] > highest)
        {
            highest = marks[n];
        }
    }

    average = sum/count;

    //OUTPUT:Average Grade
    if (average >= 80)
        grade = 'A';
    else if (average >= 70)
        grade = 'B';
    else if (average >= 60)
        grade = 'C';
    else if (average >= 50)
        grade = 'D';
    else
        grade = 'F';



    printf("\n\n **********");

    printf("\n %-15s %4s  %s\n","Names","Marks","Grade");
    
    for (n = 0 ; n < numberOfNames ; n++)
        printf(" %-15s %4.2f %6c\n",name[n],marks[n],grade[n]);

    printf("\n The average marks is %.2f",average);
    
    printf("\n The average grade is %c",grade);

    printf("\n The highest mark is %.2f",highest);
    printf("\n **********\n");
   

}//end main