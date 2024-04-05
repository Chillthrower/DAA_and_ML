#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    FILE *fp = fopen("time_vs_n_selection.csv", "w");
    if (!fp) { printf("Error opening file.\n"); return 1; }
    fprintf(fp, "n,time_taken\n");

    srand(time(NULL)); 

    for (int n = 100; n <= 2000; n += 100) 
    {
        int A[n];
        for (int k = 0; k < 10; k++) 
        {
            for (int i = 0; i < n; i++) A[i] = rand() % 1000; 

            struct timespec start, end;
            clock_gettime(CLOCK_MONOTONIC, &start); 

            for (int i = 0; i < n - 1; i++) 
            {
                int min = i;
                for (int j = i + 1; j < n; j++) if (A[j] < A[min]) min = j;
                int temp = A[i]; A[i] = A[min]; A[min] = temp;
            }

            clock_gettime(CLOCK_MONOTONIC, &end); 

            double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
            fprintf(fp, "%d,%.6f\n", n, time_taken);
        }
    }
    fclose(fp);
    printf("Experiment completed. Results saved to time_vs_n_selection.csv.\n");
    return 0;
}

    // FILE *fp = fopen("time_vs_n_merge.csv", "w");
    // if (!fp) { printf("Error opening file.\n"); return 1; }
    // fprintf(fp, "n,time_taken\n");

    // srand(time(NULL)); 
    // for (int n = 100; n <= 2000; n += 100) 
    // {
    //     int A[n];
    //     for (int k = 0; k < 100; k++) 
    //     { 
    //         for (int i = 0; i < n; i++) A[i] = rand() % 1000; 
    //                                                             --------> THIS COMMENTED SECTION HAS THE SAME SYNTAX FOR ALL 5 TYPES OF SORT WHERE ONLY "....." is CHANGED
    //         struct timespec start, end;
    //         clock_gettime(CLOCK_MONOTONIC, &start);
    //         ......
    //         clock_gettime(CLOCK_MONOTONIC, &end);
    //         double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    //         fprintf(fp, "%d,%.6f\n", n, time_taken);
    //     }
    // }
    // fclose(fp);
    // printf("Experiment completed. Results saved to time_vs_n_merge.csv.\n");
