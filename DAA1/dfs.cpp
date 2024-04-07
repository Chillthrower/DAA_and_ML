#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void dfs(int v, int a[MAX_VERTICES][MAX_VERTICES], int visited[], int vertex) 
{
    visited[vertex] = 1; 

    for (int i = 0; i < v; i++) 
    {
        if (a[vertex][i] && !visited[i]) 
        { 
            dfs(v, a, visited, i); 
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

    int visited[MAX_VERTICES] = {0}; 

    dfs(v, a, visited, 0);

    int connected = 1;
    for (int i = 0; i < v; i++) 
    {
        if (!visited[i]) 
        {
            connected = 0;
            break;
        }
    }

    if (connected) 
    {
        printf("The graph is connected\n");
    } else 
    {
        printf("The graph is disconnected\n");
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
