//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

// Struct of node student
typedef struct student_node {
    int id; // ID student is unique, every student have 1 different id
    char name[255]; // Name of the student
    char date_of_birth[255];    // Date of birth of the student
    char address[255];  // Address of the student
    int point;  // Point of the student

    struct student_node *next;
}StudentNode;


/*Function insertStudentNode perform insert 1 new StudentNode to linked list, it have argumentss:
    pointer_of_head is point of pointer head of linked list
    index is the order of the elements in linked list (begin from 1)
*/
StudentNode *insertStudentNode(StudentNode **pointer_of_head, int index, \
                 int id, char name[255], char date_of_birth[255], \
                 char address[255], int point)
{
    // Init new StudentNode
    StudentNode *new_studentnode = (StudentNode *) malloc(sizeof(StudentNode));
    new_studentnode->id = id;
    strcpy(new_studentnode->name, name);
    strcpy(new_studentnode->date_of_birth, date_of_birth);
    strcpy(new_studentnode->address, address);
    new_studentnode->point = point;


    // Get length of linked list
    int length_list = 0;
    StudentNode *current_studentnode = *pointer_of_head;
    while (current_studentnode)
    {
        current_studentnode = current_studentnode->next;
        length_list++;
    }

    // If index <= 0 or index > (length_list + 1), don't add new_studentnode to linked list
    if (index <= 0 || index > (length_list + 1))
    {
        printf("\n%dth place doesn't match!",index);
        return NULL;
    }
    // Add new_studentnode to the head of the linked list
    else if ((index == 1) && (length_list == 0))
    {
        new_studentnode->next = NULL;
        *pointer_of_head = new_studentnode;
        return new_studentnode;
    }
    else if (index == 1)
    {
        new_studentnode->next = *pointer_of_head;
        *pointer_of_head = new_studentnode;
        return new_studentnode;
    }
    // Add new_studentnode to the middle or the end of linked list
    else
    {
        current_studentnode = *pointer_of_head;
        int current_index = 1;
        while (current_index < (index-1))
        {
            current_studentnode = current_studentnode->next;
            current_index++;
        }
        new_studentnode->next = current_studentnode->next;
        current_studentnode->next = new_studentnode;
        return new_studentnode;
    }
}

/*Function findStudentNode
    Find StudentNode have value id in linked list.
    If StudentNode is found, return position of the StudentNode in the linked list. If StudentNode isn't found, return 0.
*/
int findStudentNode (StudentNode *head, int id)
{
    StudentNode *current_studentnode = head;
    int current_index = 1;
    while (current_studentnode && (current_studentnode->id != id))
    {
        current_studentnode = current_studentnode->next;
        current_index++;
    }
    if (current_studentnode)
        return current_index;
    else
        return 0;
}

/*Function deleteStudentNode
    Find StudentNode have value id in linked list.
    If StudentNode is found, delete and return position of the StudentNode in the linked list. If StudentNode isn't found, return 0.
*/
int deleteStudentNode(StudentNode **pointer_of_head, int id)
{
    StudentNode* prev_studentnode = NULL;
    StudentNode* current_studentnode = *pointer_of_head;
    int current_index = 1;
    while (current_studentnode && current_studentnode->id != id)
    {
        prev_studentnode = current_studentnode;
        current_studentnode = current_studentnode->next;
        current_index++;
    }
    if (current_studentnode)
    {
        if (prev_studentnode)
        {
            prev_studentnode->next = current_studentnode->next;
            free (current_studentnode);
        }
        else
        {
            *pointer_of_head = current_studentnode->next;
            free (current_studentnode);
        }
        return current_index;
    }
    return 0;
}

// Funtion displayList display all of the elements of linked list
void displayList (StudentNode *head)
{
    StudentNode *current_studentnode = head;
    while (current_studentnode)
    {
        printf("%d\t%s\t%s\t%s\t%d\n", current_studentnode->id, \
               current_studentnode->name, current_studentnode->date_of_birth, \
               current_studentnode->address, current_studentnode->point);
        current_studentnode = current_studentnode->next;
    }
}

// Funtion "destroyList" destroy linked list
void destroyList (StudentNode* head)
{
    StudentNode* current_studentnode = head, *new_studentnode = NULL;
    while (current_studentnode != NULL)
    {
        new_studentnode = current_studentnode->next;
        free (current_studentnode);
        current_studentnode = new_studentnode;
    }
}

int lengthList (StudentNode *head)
{
    int length_list = 0;
    StudentNode *current_studentnode = head;
    while (current_studentnode)
    {
        current_studentnode = current_studentnode->next;
        length_list++;
    }
    return length_list;
}

//int main()
//{
//    StudentNode *head = NULL;
//
//    displayList(head);
//    insertStudentNode(&head, 1, 20133299, "Do Xuan Son", "18-12-1995", "Ha Noi", 8);
//    insertStudentNode(&head, 2, 20133299, "Nguyen Van", "18-12-1995", "Ha Noi", 8);
//
//
//    displayList(head);
//
//    printf("\n%d",lengthList(head));
//
//    return 0;
//}
