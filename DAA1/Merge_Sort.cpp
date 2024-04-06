#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int B[], int p, int C[], int q, int A[]) 
{
    for (int i = 0, j = 0, k = 0; i < p || j < q; k++) 
    {
        if (i < p && (j >= q || B[i] <= C[j])) 
        {
            A[k] = B[i++];
        }
        else
        {
            A[k] = C[j++];
        }
    }
}

void mergeSort(int A[], int n) 
{
    if (n > 1) 
    {
        int mid = n / 2, B[mid], C[n - mid];
        for (int i = 0; i < mid; i++) 
        {
            B[i] = A[i];
        }
        for (int i = mid; i < n; i++) 
        {
            C[i - mid] = A[i];
        }

        mergeSort(B, mid);
        mergeSort(C, n - mid);
        merge(B, mid, C, n - mid, A);
    }
}

int main() 
{
    FILE *fp = fopen("time_vs_n_merge.csv", "w");
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
        for (int k = 0; k < 100; k++) 
        { 
            for (int i = 0; i < n; i++) 
            {
                A[i] = rand() % 1000; 
            }

            struct timespec start, end;
            clock_gettime(CLOCK_MONOTONIC, &start);
            mergeSort(A, n);
            clock_gettime(CLOCK_MONOTONIC, &end);
            double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

            fprintf(fp, "%d,%.6f\n", n, time_taken);
        }
    }
    fclose(fp);
    printf("Experiment completed. Results saved to time_vs_n_merge.csv.\n");
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
