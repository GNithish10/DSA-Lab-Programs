/*Design, Develop and Implement a menu driven Program in C for the following
operations on Circular QUEUE of integers (Array Implementation of Queue with
maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations.*/

#include <stdio.h>
#include <stdlib.h>
#define queuesize 5
void insert_rear(int item, int *r, int *count, int q[])
{
    if (*count == queuesize)
    {
        printf("queue overflow\n");
        return;
    }
    *r = (*r + 1) % queuesize;
    q[*r] = item;
    *count = *count + 1;
}

void delete_front(int *f, int *count, int q[])
{
    int item;
    if (*count == 0)
    {
        printf("queue underflow\n");
        return;
    }
    item = q[*f];
    printf("Deleted item is %d\n", item);
    *f = (*f + 1) % queuesize;
    *count = *count - 1;
}

void display(int f, int count, int q[])
{
    int i;
    if (count == 0)
    {
        printf("queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = 1; i <= count; i++)
    {
        printf("%d\n", q[f]);
        f = (f + 1) % queuesize;
    }
}

void main()
{
    int choice, item, f = 0, r = -1, count = 0, queue[queuesize];
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to insert: ");
            scanf("%d", &item);
            insert_rear(item, &r, &count, queue);
            break;
        case 2:
            delete_front(&f, &count, queue);
            break;
        case 3:
            display(f, count, queue);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}