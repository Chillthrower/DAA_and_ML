#include <stdio.h>
#include <math.h>

void heapify(int n, int a[]) 
{
    int k, v, heap, j;

    for (int i = floor(n / 2) - 1; i >= 0; i--) 
    {
        k = i;
        v = a[k];
        heap = 0;

        while (!heap && 2 * k < n) 
        {
            j = 2 * k + 1;
            if (j < n - 1 && a[j] < a[j + 1]) 
            {
                j++;
            }
            if (v >= a[j]) 
            {
                heap = 1;
            } else 
            {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
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
    {0, 9, 6, 7, 5, 4, 2, 3, 8}; 
    int n = sizeof(H) / sizeof(H[0]) - 1; 

    printf("Array before heap sort: ");
    for (int i = 1; i <= n; i++) 
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    heapSort(n, H);

    printf("Array after heap sort: ");
    for (int i = 1; i <= n; i++) 
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    return 0;
}
