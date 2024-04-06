#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int A[], int l, int r) 
{
    int pivot = A[r], i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (A[j] <= pivot) 
        { 
            int temp = A[++i]; 
            A[i] = A[j]; 
            A[j] = temp; 
        }
    }

    int temp = A[i + 1]; 
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1;
}

void quickSort(int A[], int l, int r) 
{
    if (l < r) 
    { 
        int s = partition(A, l, r); 
        quickSort(A, l, s - 1); 
        quickSort(A, s + 1, r); 
    }
}

int main() 
{
    FILE *fp = fopen("time_vs_n_quick.csv", "w");
    if (!fp) 
    { 
        printf("Error opening file.\n"); 
        return 1; 
    }
    fprintf(fp, "n,time_taken\n");

    srand(time(NULL)); 

    for (int n = 100; n <= 2000; n += 100) 
    {
        int A[n];
        for (int k = 0; k < 10; k++) 
        { 
            for (int i = 0; i < n; i++) 
            {
                A[i] = rand() % 1000; 
            }

            struct timespec start, end;
            clock_gettime(CLOCK_MONOTONIC, &start); 
            quickSort(A, 0, n - 1);
            clock_gettime(CLOCK_MONOTONIC, &end); 

            double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
            fprintf(fp, "%d,%.6f\n", n, time_taken);
        }
    }

    fclose(fp);
    printf("Experiment completed. Results saved to time_vs_n_quick.csv.\n");
    return 0;
}

    // FILE *fp = fopen("time_vs_n_bubble.csv", "w");
    // if (!fp) 
    // { 
    //     printf("Error opening file.\n"); 
    //     return 1; 
    // }

    // fprintf(fp, "n,time_taken\n");
    // srand(time(NULL)); 

    // for (int n = 100; n <= 2000; n += 100) 
    // {
    //     int A[n];
    //     for (int k = 0; k < 10; k++) 
    //     {
    //         for (int i = 0; i < n; i++) 
    //         {
    //             A[i] = rand() % 1000;
    //         } 

    //         struct timespec start, end;
    //         clock_gettime(CLOCK_MONOTONIC, &start); 

    //          .................................                      --------> THIS COMMENTED SECTION HAS THE SAME SYNTAX FOR ALL 5 TYPES OF SORT WHERE ONLY "....." is CHANGED

    //         clock_gettime(CLOCK_MONOTONIC, &end); 

    //         double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    //         fprintf(fp, "%d,%.6f\n", n, time_taken);
    //     }
    // }
    // fclose(fp);
    // printf("Experiment completed. Results saved to time_vs_n_bubble.csv.\n");
    // return 0;
