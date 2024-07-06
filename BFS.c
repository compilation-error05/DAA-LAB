#include <stdio.h>

int a[20][20] = {{0, 1, 0, 0, 1}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {1, 1, 0, 0, 0}};
int q[20] = {0}, visited[20] = {0}, f = 0, r = -1;
void bfs(int v, int n);
int displayBFS(int n);

int main()
{
    int v, n = 5, i, j;
    bfs(0, n);
    displayBFS(n);

    return 0;
}

void bfs(int v, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        if (a[v][i] == 1 && !visited[i])
            q[++r] = i;

    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++], n);
    }
}

int displayBFS(int n)
{
    int i;
    printf("\n BFS sequence:\n");
    for (i = 0; i < n; i++)
        if (visited[i])
            printf("%d\t", i);
        else
            printf("\n Bfs is not possible");
}