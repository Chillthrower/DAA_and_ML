#include <stdio.h>

int main() {
    int H[] = {0, 9, 6, 7, 5, 4, 2, 3, 8}; 
    int n = sizeof(H) / sizeof(H[0]) - 1; 

    printf("Array before heapify: ");
    for (int i = 1; i <= n; i++) 
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    for (int i = n / 2; i >= 1; i--) 
    {
        int k = i;
        int v = H[k];
        int heap = 0;
        while (!heap && 2 * k <= n) 
        {
            int j = 2 * k;
            if (j < n && H[j] < H[j + 1])
            {
                j++;
            }
            if (v >= H[j])
            {
                heap = 1;
            }
            else 
            {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }

    printf("Array after heapify: ");
    for (int i = 1; i <= n; i++) 
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    return 0;
}
