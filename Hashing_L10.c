/*Given a set of N employee records with a set K of Keys (4-digit) which uniquely
determine the records. Assume that the records are available in the memory by a Hash
Table (HT) of m memory locations with L as the set of memory addresses (2-digit) of
locations in HT. Let the keys in K and addresses in L are Integers. Develop a Program
in C that uses Hash function H: K →L as H (K) = K mod m (remainder method), and
implement hashing technique to map a given key K to the address space L. Resolve the
collision (if any) using linear probing.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct employee
{
    int id;
    char name[20];
    int sal;
} EMP;
EMP emp[10];
int a[10], empID[10], count = 0;
int getemp(EMP emp[], int key, int ID)
{
    FILE *fp;
    fp = fopen("out.txt", "a+");
    emp[key].id = ID;
    printf("\nEnter employee name and salary:\n");
    scanf("%s%d", emp[key].name, &emp[key].sal);
    fprintf(fp, "\n%d\t%s\t%d", emp[key].id, emp[key].name, emp[key].sal);
    fclose(fp);
    return key;
}
void display()
{
    int i;
    printf("\nKey\tID\tName\tSalary");
    for (i = 0; i < 10; i++)
        if (a[i] != -1)
            printf("\n%d\t%d\t%s\t%d", i, emp[i].id, emp[i].name, emp[i].sal);
}
void probe(int key, int ID)
{
    int i = key, flag = 0;
    if (count == 10)
    {
        printf("Hash table is full.\n");
        exit(0);
    }
    if (a[key] == -1)
    {
        a[key] = getemp(emp, key, ID);
        display();
        count++;
    }
    else
    {
        printf("\nCollision detected. Solving it with linear probing...\n");
        while (a[i] != -1)
        {
            i++;
            if (i == 10)
            {
                i = 0;                        // 1st change made here
                while (i < key && a[i] != -1) // 2nd change made here
                    i++;
            }
        }
        a[i] = getemp(emp, i, ID);
        printf("\nCollision problem solved! Hash table:\n");
        display();
        count++;
    }
}
void main()
{
    int key, i, j = 0, ans = 1;
    for (i = 0; i < 10; i++)
        a[i] = -1;
    do
    {
        printf("\nEnter the employee ID: ");
        scanf("%d", &empID[j]);
        key = empID[j] % 10;
        probe(key, empID[j]);
        printf("\n\nDo you want to continue the input? (1=Yes | 0=No): ");
        scanf("%d", &ans);
        j++;
    } while (ans);
    display(emp);
    for (i = 0; i < 10; i++)
        if (a[i] != -1)
            printf(" \t%d", a[i]);
    printf("\n");
}
