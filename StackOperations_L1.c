#include <stdio.h>
#include <stdlib.h>
#define Max 5

void push(int stack[], int *top, int element){
    if (*top == Max-1){
        printf("Stack Overflow! Cannot push more elements");
    }
    else{
        (*top)++;
        stack[*top] = element;
        printf("%d pushed to stack\n", element);
    }
}

void pop(int stack[], int *top){
    if (*top == -1){
        printf("Stack Underflow! Cannot pop from empty stack");
    }
    else{
        int popped = stack[*top];
        (*top)--;
        printf("%d popped from stack\n", popped);
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void main() {
    int stack[Max];
    int top = -1;
    int choice, element;

    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter an element to push: ");
                scanf("%d", &element);
                push(stack, &top, element);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}