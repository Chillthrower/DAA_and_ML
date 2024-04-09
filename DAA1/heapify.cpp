#include <stdio.h>
#include <math.h>

void heapify(int n, int a[]) 
{
    for (int i = 1; i < n; i++) 
    {
        int child = i;
        while (child > 0) 
        {
            int parent = (child - 1) / 2;
            if (a[child] > a[parent]) 
            {
                int temp = a[child];
                a[child] = a[parent];
                a[parent] = temp;
                child = parent;
            } 
            else 
            {
                break;
            }
        }
    }
}

void heapSort(int n, int a[]) 
{
    int temp;
    
    heapify(n, a);

    for (int i = n - 1; i > 0; i--) 
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(i, a);
    }
}

int main() 
{
    int H[] = 
    {9, 6, 7, 5, 4, 2, 3, 8}; 
    int n = sizeof(H) / sizeof(H[0]); 

    printf("Array before heap sort: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    heapSort(n, H);

    printf("Array after heap sort: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    return 0;
}
