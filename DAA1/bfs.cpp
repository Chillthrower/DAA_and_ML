#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void bfs(int source, int n, int a[MAX_VERTICES][MAX_VERTICES], int s[MAX_VERTICES]) 
{
    int f = 1, r = 1, v, u, q[MAX_VERTICES];
    q[r] = source;
    s[source] = 1;
    while (f <= r) 
    {
        u = q[f++];
        for (v = 0; v < n; v++) 
        {
            if (s[v] == 0 && a[u][v] == 1) 
            {
                q[++r] = v;
                s[v] = 1;
            }
        }
    }
}

int main() 
{
    int v;
    printf("Enter the number of vertices:\n");
    scanf("%d", &v);

    int a[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < v; i++) 
    {
        for (int j = 0; j < v; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    int s[MAX_VERTICES] = {0}; 

    int source;
    printf("Enter the source vertex:\n");
    scanf("%d", &source);

    bfs(source, v, a, s);

    printf("BFS Reachability:\n");
    for (int i = 0; i < v; i++) 
    {
        if (s[i] == 1) 
        {
            printf("%d is reachable from %d\n", i, source);
        } else 
        {
            printf("%d is not reachable from %d\n", i, source);
        }
    }

    return 0;
}

// sample input

// Enter the number of vertices:
// 5
// Enter the adjacency matrix:
// 0 1 0 0 0
// 1 0 0 0 0
// 0 0 0 1 0
// 0 0 1 0 0
// 0 0 0 0 0
// Enter the source vertex:
// 0
