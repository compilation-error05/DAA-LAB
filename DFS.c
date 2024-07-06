#include <stdio.h>

int G[10][10], visited[10];
G[10][10];
void display(int v);
void DFS(int i, int n);

int main()
{
    int i, j, n;
    printf("\nEnter number of vertices:");
    scanf("%d", &n);

    printf("\nEnter adjecency matrix(Transitive closer)) of the graph:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\n DFS Sequence:\n");
    DFS(0, n);
    return 0;
}

void display(int v)
{
    printf("\t%d", v);
}

void DFS(int i, int n)
{
    int j;
    display(i);
    visited[i] = 1;

    for (j = 0; j < n; j++)
        if (!visited[j] && G[i][j] == 1)
            DFS(j, n);
}
