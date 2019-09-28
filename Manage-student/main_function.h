//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "student_structure.h"
//#include "file_function.h"
//#include "utility_function.h"

// Function "printfStudentList" prints the student list according to student ID
void printfStudentList (StudentNode *head)
{
    printf("\nStudent List:\n");
    printf("Student ID\tName\t Date of birth\tAddress\t Point\n");
    displayList(head);
}

// Function "infoStudent" find infor of a student according to student ID
void infoStudent (StudentNode *head)
{
    int id; // ID of the student
    printf("\nEnter student ID.");
    checkEnterInteger(&id);
    StudentNode *current_studentnode = head;
    while (current_studentnode && (current_studentnode->id != id))
    {
        current_studentnode = current_studentnode->next;
    }
    if (current_studentnode)
    {
        printf("Information of this student:\n");
        printf("Student ID\tName\t Date of birth\tAddress\t Point\n");
        printf("%d\t%s\t%s\t%s\t%d\n", current_studentnode->id, \
               current_studentnode->name, current_studentnode->date_of_birth, \
               current_studentnode->address, current_studentnode->point);
    }
    else
        printf("Not found!");
}

// Function "addStudent" adds 1 student
void addStudent (StudentNode **pointer_of_head)
{
    int id; // ID of the student
    char name[255]; // Name of the student
    char date_of_birth[255];    // Date of birth of the student
    char address[255];  // Address of the student
    int point;  // Point of the student

    printf("\nEnter student ID.");
    checkEnterInteger(&id);
    while(checkStudentID(*pointer_of_head, id))
    {
        printf("\nThis ID is existed.Enter student ID.");
        checkEnterInteger(&id);
    }

    printf("\nEnter student name: ");
    gets(name);
    while(checkStringIsEmpty(name))
    {
        printf("\nYou didn't enter anything. Please enter again: ");
        gets(name);
    }

    printf("\nEnter student date of birth: ");
    gets(date_of_birth);
    while(checkStringIsEmpty(date_of_birth))
    {
        printf("\nYou didn't enter anything. Please enter again: ");
        gets(date_of_birth);
    }

    printf("\nEnter student address: ");
    gets(address);
    while(checkStringIsEmpty(address))
    {
        printf("\nYou didn't enter anything. Please enter again: ");
        gets(address);
    }

    printf("\nEnter student point.");
    checkEnterInteger(&point);

    // Add 1 student node to linked list
    insertStudentNode(pointer_of_head, lengthList(*pointer_of_head) + 1, id, name, date_of_birth, address, point);

    writeFile("file.txt", *pointer_of_head);
}

// Function "delStudent" deletes 1 student
void delStudent (StudentNode **pointer_of_head)
{
    int id; // ID of the student
    printf("\nEnter student ID: ");
    checkEnterInteger(&id);
    if(!checkStudentID(*pointer_of_head, id))
    {
        printf("\nThis ID isn't existed.");
    }
    else
    {
        deleteStudentNode(pointer_of_head, id);
        writeFile("file.txt", *pointer_of_head);
    }
}

// Function "updateStudent" updates information a student according to student ID
void updateStudent (StudentNode *head)
{
    int id; // ID of the student
    printf("\nEnter student ID to update: ");
    checkEnterInteger(&id);

    StudentNode *current_studentnode = head;
    while (current_studentnode && (current_studentnode->id != id))
    {
        current_studentnode = current_studentnode->next;
    }
    if (current_studentnode)
    {
        printf("Information of this student:\n");
        printf("Student ID\tName\t Date of birth\tAddress\t Point\n");
        printf("%d\t%s\t%s\t%s\t%d\n", current_studentnode->id, \
               current_studentnode->name, current_studentnode->date_of_birth, \
               current_studentnode->address, current_studentnode->point);

        getchar();
        printf("\nEnter student name: ");
        gets(current_studentnode->name);
        while(checkStringIsEmpty(current_studentnode->name))
        {
            printf("\nYou didn't enter anything. Please enter again: ");
            gets(current_studentnode->name);
        }

        printf("\nEnter student date of birth: ");
        gets(current_studentnode->date_of_birth);
        while(checkStringIsEmpty(current_studentnode->date_of_birth))
        {
            printf("\nYou didn't enter anything. Please enter again: ");
            gets(current_studentnode->date_of_birth);
        }

        printf("\nEnter student address: ");
        gets(current_studentnode->address);
        while(checkStringIsEmpty(current_studentnode->address))
        {
            printf("\nYou didn't enter anything. Please enter again: ");
            gets(current_studentnode->address);
        }
        printf("\nEnter student point: ");
        checkEnterInteger(&current_studentnode->point);
        printf("\nStudent information after updating:\n");
        printf("Student ID\tName\t Date of birth\tAddress\t Point\n");
        printf("%d\t%s\t%s\t%s\t%d\n", current_studentnode->id, \
               current_studentnode->name, current_studentnode->date_of_birth, \
               current_studentnode->address, current_studentnode->point);
        writeFile("file.txt", head);
    }
    else
        printf("Not found!");
}
