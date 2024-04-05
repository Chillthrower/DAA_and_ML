#include <stdio.h>

#define MAX_SIZE 100

void warshall(int A[MAX_SIZE][MAX_SIZE], int n) 
{
    int R[MAX_SIZE][MAX_SIZE]; 

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            R[i][j] = A[i][j];
        }
    }

    
    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
            }
        }
    }

    
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
}

int main() 
{

    int n = 4; // Number of vertices
    int A[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},                         // in the question user input is not asked, if it is asked use the commented code
        {0, 0, 0, 0}
    };

    // int n;
    // printf("Enter the number of vertices: ");
    // scanf("%d", &n);

    // int A[MAX_SIZE][MAX_SIZE]; 

    
    // printf("Enter the adjacency matrix:\n");
    // for (int i = 0; i < n; i++) 
    // {
    //     for (int j = 0; j < n; j++) 
    //     {
    //         printf("Enter weight for edge from vertex %d to %d: ", i, j);
    //         scanf("%d", &A[i][j]);
    //     }
    // }

    
    warshall(A, n);

    return 0;
}

// sample input for the commented code

// Enter the number of vertices: 4
// Enter the adjacency matrix:
// Enter weight for edge from vertex 0 to 0: 0
// Enter weight for edge from vertex 0 to 1: 1
// Enter weight for edge from vertex 0 to 2: 0
// Enter weight for edge from vertex 0 to 3: 0
// Enter weight for edge from vertex 1 to 0: 0
// Enter weight for edge from vertex 1 to 1: 0          start -> 0 1 0 0
// Enter weight for edge from vertex 1 to 2: 1                   0 0 1 0
// Enter weight for edge from vertex 1 to 3: 0                   0 0 0 1
// Enter weight for edge from vertex 2 to 0: 0                   0 0 0 0
// Enter weight for edge from vertex 2 to 1: 0
// Enter weight for edge from vertex 2 to 2: 0
// Enter weight for edge from vertex 2 to 3: 1
// Enter weight for edge from vertex 3 to 0: 0
// Enter weight for edge from vertex 3 to 1: 0
// Enter weight for edge from vertex 3 to 2: 0
// Enter weight for edge from vertex 3 to 3: 0
