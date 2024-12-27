/*Design, Develop and Implement a menu driven Program in C for the following
operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name,
Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[20];
    char usn[10];
    char branch[5];
    int sem;
    char phno[10];
    struct node *link;
};
typedef struct node *NODE;
// get node
NODE get_node()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->link = NULL;
    printf("\nName: ");
    scanf("%s", temp->name);
    printf("\nUSN: ");
    scanf("%s", temp->usn);
    printf("\nBranch: ");
    scanf("%s", temp->branch);
    printf("\nSem: ");
    scanf("%d", &temp->sem);
    printf("\nPh no: ");
    scanf("%s", temp->phno);
    return temp;
}
// insert front
NODE insert_front(NODE first)
{
    NODE temp;
    temp = get_node();
    if (first == NULL)
        return temp;
    else

    {
        temp->link = first;
        return temp;
    }
}
// insert rear
NODE insert_rear(NODE first)
{
    NODE temp, next;
    temp = get_node();
    if (first == NULL)
        return temp;
    else
    {
        next = first;
        while (next->link != NULL)
            next = next->link;
        next->link = temp;
    }
    return first;
}
// delete front
NODE del_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("\nNo entries");
        return first;
    }
    temp = first;
    first = first->link;
    free(temp);
    return first;
}
// delete rear
NODE del_rear(NODE first)

{
    NODE temp, prev, cur;
    if (first == NULL)
    {
        printf("\nNo entries \n");
        return first;
    }
    else if (first->link == NULL)
    {
        printf("Deleted USN:%s \n", first->usn);
        free(first);
        return first;
    }
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
    printf("Deleted USN: %s", cur->usn);
    free(cur);
    return first;
}
// display
void display(NODE first)
{
    NODE temp = first;
    int count = 0;
    if (temp == NULL)
    {
        printf("\nNo entries \n");
        return;
    }
    printf("\nStudent info: \n");
    while (temp != NULL)
    {
        printf("Name:%s\t", temp->name);
        printf("USN:%s\t", temp->usn);
        printf("Branch:%s\t", temp->branch);
        printf("Sem:%d\t", temp->sem);
        printf("Ph no:%s\t", temp->phno);
        printf("\n");
        count++;
        temp = temp->link;
    }
    printf("\nthe no. of nodes are %d", count);
}
// main func
void main()
{
    NODE first = NULL;
    int choice, item;
    for (;;)
    {
        printf("\n\nEnter choice 1.IF 2.IR 3.DF 4.DR 5.display 6.Exit\n");
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
            first = del_front(first);
            break;
        case 4:
            first = del_rear(first);
            break;
        case 5:
            display(first);
            break;
        case 6:
            exit(0);
        }
    }
}