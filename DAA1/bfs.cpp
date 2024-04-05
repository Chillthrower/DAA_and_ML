#include <stdio.h>

#define MAX_VERTICES 6

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = 
{
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0}
};

void bfs(int start) {
    int queue[MAX_VERTICES], front = 0, rear = -1;
    int visited[MAX_VERTICES] = {0};
    printf("Nodes reachable from node %d: %d ", start, start);
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) 
    {
        int currentVertex = queue[front++];
        for (int i = 0; i < MAX_VERTICES; i++) 
        {
            if (adjacencyMatrix[currentVertex][i] && !visited[i]) 
            {
                visited[i] = 1;
                printf("%d ", i);
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() 
{
    bfs(1);
    return 0;
}
