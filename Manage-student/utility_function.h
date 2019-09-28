//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "student_structure.h"
//#include "file_function.h"

// Function "displayMenu" displays menu of program
void displayMenu ()
{
    printf("\n***************************************************************");
    printf("\n|                             MENU                            |");
    printf("\n|                    ----------------------                   |");
    printf("\n| 1. Print the student list according to student ID           |");
    printf("\n| 2. Find infor of a student according to student ID          |");
    printf("\n| 3. Add a student                                            |");
    printf("\n| 4. Delete a student according to student ID                 |");
    printf("\n| 5. Update information a student according to student ID     |");
    printf("\n| 6. Exit                                                     |");
    printf("\n***************************************************************");
}

// Function "checkEnter Integer" to check entered number
void checkEnterInteger (int *num_point)
{
    int num;
    char term;
    printf("\nEnter number:");
    scanf("%d%c", &num, &term);
    while (term != '\n')
    {
        char s[100];
        gets(s);
        printf("\nThe number you entered is not an integer.\nEnter number again: ");
        scanf("%d%c", &num, &term);
    }
    *num_point = num;
}

// Function
int checkStringIsEmpty (char *str)
{
    return !strcmp(str, "");
}

// Function "checkStudentID" check uniqueness of student ID
int checkStudentID (StudentNode *head, int id)
{
    return findStudentNode(head, id);
}


