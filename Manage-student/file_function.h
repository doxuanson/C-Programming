//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "student_structure.h"

// Function to read file
void readFile (char *file_name, StudentNode **pointer_of_head)
{
    FILE *file_point; // Point to read the file file_name
    char line[1000]; // string stores every line of file file_name.

    file_point = fopen(file_name, "r");
    if(!file_point)
    {
        perror("Error opening file.\n");
        return NULL;
    }

    while(1)
    {
        if ( fgets(line, 1000, file_point) != NULL )
        {
            int id; // ID of the student
            char name[255]; // Name of the student
            char date_of_birth[255];    // Date of birth of the student
            char address[255];  // Address of the student
            int point;  // Point of the student
            char *token; // Variable
            token = strtok(line, "\t");
            id = atoi(token);

            token = strtok(NULL, "\t");
            strcpy(name, token);

            token = strtok(NULL, "\t");
            strcpy(date_of_birth, token);

            token = strtok(NULL, "\t");
            strcpy(address, token);

            token = strtok(NULL, "\t");
            point = atoi(token);

            // Add 1 student node to linked list
            insertStudentNode(pointer_of_head, lengthList(*pointer_of_head) + 1, id, name, date_of_birth, address, point);
        }

        // Break when point file_point at end of file.
        if(feof(file_point))
            break ;
    }
    fclose(file_point);
}

// Function to write to file
void writeFile (char *file_name, StudentNode *head)
{
    remove(file_name); // Remove file file_name
    StudentNode *current_studentnode = head;
    FILE *file_point; // Point to read the file file_name
    file_point = fopen(file_name, "a");
    char line[1000]; // string stores 1 student node of linked list
    char temp[100]; // variable

    while (current_studentnode)
    {
        itoa(current_studentnode->id,temp,10); // convert integer to string
        strcpy(line, temp);
        strcat(line, "\t");
        strcat(line, current_studentnode->name);
        strcat(line, "\t");
        strcat(line, current_studentnode->date_of_birth);
        strcat(line, "\t");
        strcat(line, current_studentnode->address);
        strcat(line, "\t");
        itoa(current_studentnode->point,temp,10); // convert integer to string
        strcat(line, temp);
        strcat(line, "\n");

        fputs(line, file_point); // write string "line" to file

        current_studentnode = current_studentnode->next;
    }
    fclose(file_point);
}


//
//int main ()
//{
//    StudentNode *head = NULL;
//    readFile ("file.txt", &head);
//
//    writeFile("file.txt", head);
//    return 0;
//}





