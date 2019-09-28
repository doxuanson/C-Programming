#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_structure.h"
#include "file_function.h"
#include "utility_function.h"
#include "main_function.h"

int main ()
{
    StudentNode *head = NULL;
    readFile ("file.txt", &head);
    int check = 1; // variable "check" to check that user want to exit the program
    while (check)
    {
        displayMenu();
        int selected_number;

        checkEnterInteger(&selected_number);
        printf("\n"); // Minh khong hieu vi` sao khi an' 1 roi` an' string thi` bi vong` lap. Khi su dung dong` nay` thi` het'.
        switch(selected_number)
        {
        case 1:
            printfStudentList(head);
            break;
        case 2:
            infoStudent(head);
            break;
        case 3:
            addStudent(&head);
            break;
        case 4:
            delStudent(&head);
            break;
        case 5:
            updateStudent(head);
            break;
        case 6:
            check = 0;
            break;
        default:
            printf("Please enter number from 1 o 6!");
        }
    }

    return 0;
}
