#include <stdio.h>

#define MAX_VERTICES 100

typedef struct 
{ 
    int items[MAX_VERTICES], top; 
} Stack;

void topSortUtil(int v, int adj[MAX_VERTICES][MAX_VERTICES], int V, int vis[], Stack *S) 
{
    vis[v] = 1;
    for (int i = 0; i < V; i++)
    {
        if (adj[v][i] && !vis[i]) 
        {
            topSortUtil(i, adj, V, vis, S);
        }
    }
    S->items[++(S->top)] = v;
}

void topSort(int adj[MAX_VERTICES][MAX_VERTICES], int V) 
{
    int vis[MAX_VERTICES] = {0};
    Stack S = { .top = -1 };
    for (int i = 0; i < V; i++)
    {
        if (!vis[i]) 
        {
            topSortUtil(i, adj, V, vis, &S);
        }
    }
    printf("Topological sorting of the graph: ");
    while (S.top >= 0)
    {
        printf("%d ", S.items[S.top--]);
    }
}

int main() {
    int V = 5;
    int edges[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}}; //belo visual representation
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};                                              
    
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++)
    {
        adj[edges[i][0]][edges[i][1]] = 1;
    }

    topSort(adj, V);
    return 0;
}

// 0 ---> 1 ----> 3 ----> 4
//  \      \      /
//   \      \    /
//    \      \  /
//     -----> 2

