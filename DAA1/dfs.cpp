#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 6

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = 
{
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0}
};

int visited[MAX_VERTICES] = {0};

void dfs(int vertex) 
{
    visited[vertex] = 1;
    for (int i = 0; i < MAX_VERTICES; i++) 
    {
        if (adjacencyMatrix[vertex][i] && !visited[i]) 
        {
            dfs(i);
        }
    }
}

bool isConnected() 
{
    dfs(0);
    for (int i = 0; i < MAX_VERTICES; i++) 
    {
        if (!visited[i]) 
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    if (isConnected()) 
    {
        printf("The graph is connected.\n");
    } 
    else 
    {
        printf("The graph is not connected.\n");
    }

    return 0;
}
