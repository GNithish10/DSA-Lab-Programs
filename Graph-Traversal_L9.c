/*Design, Develop and Implement a Program in C for the following operations on
Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using
any traversal method (DFS/BFS).*/

#include <stdio.h>
#include <stdlib.h>
int city[10][10], v[10], queue[10], r = 0, f = 1, n;
void dfs(int s)
{
    int i;
    v[s] = 1;
    for (i = 1; i <= n; i++)
        if (city[s][i] && !v[i])
        {
            printf("%d\t", i);
            v[i] = 1;
            dfs(i);
        }
    return;
}

void bfs(int s)
{
    int i;
    for (i = 1; i <= n; i++)
        if (city[s][i] && !v[i])
        {
            queue[++r] = i;
            printf("%d\t", i);
            v[queue[r]] = 1;
        }
    if (f <= r)
    {
        v[queue[f]] = 1;
        bfs(queue[++f]);
    }
    return;
}
void main()
{
    int count = 0, i, choice, j, s;
    printf("\nEnter the number of cities : ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix for connected cities : \n");
    for (i = 1; i <= n; i++)
    {
        v[i] = 0;
        queue[i] = 0;
        for (j = 1; j <= n; j++)
            scanf("%d", &city[i][j]);
    }
    printf("\nEnter 1 for dfs and 2 for bfs : ");
    scanf("%d", &choice);
    printf("\nEnter the city to check connectivity of : ");
    scanf("%d", &s);
    printf("\nCities reachable from %d are : \n", s);
    if (choice == 1)
        dfs(s);
    if (choice == 2)
    {
        queue[++r] = s;
        bfs(s);
    }
    printf("\n");
    for (i = 1; i <= n; i++)
        count += v[i];
    if (count == n)
        printf("\n All cities are connected \n\n");
    else
        printf("\nAll cities are not connected \n\n");
}
