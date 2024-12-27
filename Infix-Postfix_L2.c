/*Design, Develop and Implement a Program in C for converting an Infix
Expression to Postfix Expression. Program should support for both parenthesized and
free parenthesized expressions with the operators: +, -, *, /, %( Remainder), ^ (Power)
and alphanumeric operands.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int G(char);
int F(char);
void infix_postfix(char infix[], char postfix[]);
int F(char sym)
{
    switch (sym)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}
int G(char sym)
{
    switch (sym)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}
void infix_postfix(char infix[], char postfix[])
{
    int top = -1, i, j = 0;
    char stack[20], sym;
    stack[++top] = '#';
    for (i = 0; i < strlen(infix); i++)
    {
        sym = infix[i];
        while (F(stack[top]) > G(sym))
            postfix[j++] = stack[top--];
        if (F(stack[top]) != G(sym))
            stack[++top] = sym;
        else
            top--;
    }
    while (stack[top] != '#')
        postfix[j++] = stack[top--];
    postfix[j] = '\0';
    return;
}
void main()
{
    char postfix[20], infix[20];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_postfix(infix, postfix);
    printf("The Postfix expression is: ");
    printf("%s", postfix);
}