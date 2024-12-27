/*Design, Develop and Implement a menu driven Program in C for the following
operations on Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name,
Dept, Designation, Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit.
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int SSN;
    char Name[20];
    char Dept[20];
    char Designation[20];
    int Sal;
    char Ph_No[11];
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE get_node();
NODE insert_front(NODE first);
NODE insert_rear(NODE first);
NODE delete_front(NODE first);
NODE delete_rear(NODE first);
void DLL_display(NODE first);
void main()
{
    NODE first = NULL;
    int choice;
    for (;;)
    {
        printf("\nEnter your choice\n1.Insert from front\n2.Insert from rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit:\n");
        scanf("%d", &choice);
        switch (choice)

        {
        case 1:
            first = insert_front(first);
            break;
        case 2:
            first = insert_rear(first);
            break;
        case 3:
            first = delete_front(first);
            break;
        case 4:
            first = delete_rear(first);
            break;
        case 5:
            DLL_display(first);
            break;
        case 6:
            exit(0);
        default:
            printf("\nWrong Choice!");
        } // End of switch case
    } // End of for loop
    return;
} // End of main()
NODE get_node()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    printf("\nEnter the details of Employee:\n");
    printf("Employee SSN:");
    scanf("%d", &temp->SSN);
    printf("Employee Name:");
    scanf("%s", temp->Name);
    printf("Employee Department:");
    scanf("%s", temp->Dept);
    printf("Employee Designation:");
    scanf("%s", temp->Designation);
    printf("Employee Salary:");
    scanf("%d", &temp->Sal);
    printf("Employee Phone Number:");
    scanf("%s", temp->Ph_No);
    return temp;
}
NODE insert_front(NODE first)
{
    NODE temp;
    temp = get_node();
    if (first == NULL)
        return temp;
    temp->rlink = first;
    first->llink = temp;
    return temp;
}
NODE insert_rear(NODE first)
{
    NODE temp, next;
    temp = get_node();
    if (first == NULL)
        return temp;
    next = first;
    while (next->rlink != NULL)
        next = next->rlink;
    next->rlink = temp;
    temp->llink = next;
    return first;
}
NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("\nNo nodes in the DLL!");
        return first; // return NULL
    }
    temp = first;
    printf("\nThe node to be deleted is:%d\t%s\t%s\t%s\t%d\t%s", temp->SSN, temp->Name, temp->Dept, temp->Designation, temp->Sal, temp->Ph_No);
    first = first->rlink;
    first->llink = NULL;
    free(temp);
    return first;
}
NODE delete_rear(NODE first)
{
    NODE prev, cur;
    if (first == NULL)
    {
        printf("\nNo nodes in the DLL!");
        return first; // return NULL
    }
    if (first->rlink == NULL)
    {
        printf("\nThe node to be deleted is:%d\t%s\t%s\t%s\t%d\t%s", first->SSN, first->Name, first->Dept, first->Designation, first->Sal, first->Ph_No);
        free(first);
        return NULL;
    } // End of if block
    cur = first;
    while (cur->rlink != NULL)
    {
        prev = cur;
        cur = cur->rlink;
    } // End of while loop
    printf("\nThe node to be deleted is:%d\t%s\t%s\t%s\t%d\t%s", cur->SSN, cur->Name, cur->Dept, cur->Designation, cur->Sal, cur->Ph_No);
    prev->rlink = NULL;
    free(cur);
    return first;
} // End of delete_rear()
void DLL_display(NODE first)
{
    NODE temp;
    int count = 0;
    if (first == NULL)
    {
        printf("\nNumber of nodes in the DLL is: %d", count);
        printf("\nNo nodes in the DLL!");
        return;
    }
    temp = first;
    printf("\nThe information of Employee(s) are: ");
    while (temp != NULL)
    {
        printf("\nEmployee SSN: %d", temp->SSN);
        printf("\nEmployee Name: %s", temp->Name);
        printf("\nEmployee Department: %s", temp->Dept);
        printf("\nEmployee Designation: %s", temp->Designation);
        printf("\nEmployee Salary: %d", temp->Sal);
        printf("\nEmployee Ph_No: %s\n", temp->Ph_No);
        count++;
        temp = temp->rlink;
    } // End of while loop
    printf("\nThe number of nodes in the DLL are: %d", count);
    return;
}