#include <stdio.h>
#include <limits.h>

#define V 4

void floydWarshall(int graph[V][V]) 
{
    int D[V][V];

    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            D[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) 
    {
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][k] + D[k][j] < D[i][j]) 
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    printf("Distance matrix of the shortest paths’ lengths:\n");
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        
        {
            if (D[i][j] == INT_MAX)
            
            {
                printf("%d\t", -1);
                continue;
            }
            
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int graph[V][V] = 
    {
        
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},                       // in the question user input is not asked, if it is asked use the commented code
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    // printf("Enter the weight matrix for the graph (%d x %d):\n", V, V);
    // int x;
    // int graph[V][V];
    // for (int i = 0; i < V; i++) 
    // {
    //     for (int j = 0; j < V; j++) 
    //     {
    //         scanf("%d", &x);

    //         if (x == -1)
    //         {
    //             graph[i][j] = INT_MAX;
    //             continue;
    //         }

    //         graph[i][j] = x;
            
    //     }
    // }

    floydWarshall(graph);

    return 0;
}

// sample input for the commented code

// Enter the weight matrix for the graph (4 x 4):
// 0
// 5
// -1
// 10
// -1
// 0
// 3
// -1               where -1 = infinity
// -1
// -1
// 0
// 1
// -1
// -1
// -1
// 0
