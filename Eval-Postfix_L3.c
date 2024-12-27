/*Design, Develop and Implement a Program in C for evaluation of Suffix
expression with single digit operands and operators: +, -, *, /, %, ^.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
double compute(double op1, double op2, char sym)
{
    switch (sym)
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    case '$':
    case '^':
        return (pow(op1, op2));
    }
}
void main()
{
    int i, top = -1;
    char postfix[20], sym;
    double s[20], op1, op2, res;
    printf("\nEnter postfix expression : ");
    scanf("%s", postfix);
    for (i = 0; i < strlen(postfix); i++)
    {
        sym = postfix[i];
        if (isdigit(sym))
            s[++top] = sym - '0';
        else
        {
            op2 = s[top--];
            op1 = s[top--];
            res = compute(op1, op2, sym);
            s[++top] = res;
        }
    }
    res = s[top--];
    printf("\nThe result of the expression is : %.4f\n", res);
    return;
}