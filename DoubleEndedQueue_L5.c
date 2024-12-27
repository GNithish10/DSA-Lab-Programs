/*Design, Develop and Implement a menu driven Program in C for the following
operations on Double Ended QUEUE of integers (Array Implementation of Queue with
maximum size MAX)
a. Perform Insertion / Deletion at front of QUEUE
b. Perform Insertion / Deletion at rear of QUEUE
c. Display the status of Circular QUEUE
d. Exit
Support the program with appropriate functions for each of the above operations.*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue_full(int rear)
{
    return ((rear == SIZE - 1) ? 1 : 0);
}
int queue_empty(int rear, int front)
{
    return ((rear < front) ? 1 : 0);
}
void queue_insert_rear(int queue[], int *rear, int ele)
{
    if (queue_full(*rear))
    {
        printf("\n queue full");
        return;
    }
    queue[++(*rear)] = ele;
}
void queue_insert_front(int queue[], int *rear, int *front, int ele)
{
    if (queue_empty(*rear, *front))
    {
        queue[++(*rear)] = ele;
        return;
    }
    if (*front != 0)
    {
        queue[--(*front)] = ele;
        return;
    }
}
void queue_delete_rear(int queue[], int *rear, int *front)
{
    if (queue_empty(*rear, *front))
    {
        printf("\n queue empty");
        return;
    }
    printf("the element deleted is %d", queue[*rear]);
    if (*front > *rear)
    {
        *front = 0;
        *rear = -1;
        return;
    }
    else
    {
        *rear = (*rear - 1 + SIZE) % SIZE;
        return;
    }
}
void queue_delete_front(int queue[], int *rear, int *front)
{
    if (queue_empty(*rear, *front))
    {
        printf("\n queue empty");
        return;
    }
    printf("the element deleted is %d", queue[*front]);
    if (*front > *rear)
    {
        *front = 0;
        *rear = -1;
        return;
    }
    else
    {
        *front = (*front + 1) % SIZE;
        return;
    }
}

void display(int queue[], int rear, int front)
{
    int i;
    if (queue_empty(rear, front))
    {
        printf("\n queue empty");
        return;
    }
    printf("the element in the dequeue are:");
    for (i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
}
int main()
{
    int Queue[SIZE], rear = -1, front = 0, choice, item;
    for (;;)
    {
        printf("\n1.Insert Front \n2.Insert Rear \n3.Delete Front \n4.Delete Rear\n5.Display \n6.Exit");
        printf("\nEnter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element :");
            scanf("%d", &item);
            queue_insert_front(Queue, &rear, &front, item);
            break;
        case 2:
            printf("Enter the element :");
            scanf("%d", &item);
            queue_insert_rear(Queue, &rear, item);
            break;
        case 3:
            queue_delete_front(Queue, &rear, &front);
            break;
        case 4:
            queue_delete_rear(Queue, &rear, &front);
            break;
        case 5:
            display(Queue, rear, front);
            break;

        case 6:
            exit(0);
        default:
            printf("enter valid choice");
        }
    }
    return 0;
}