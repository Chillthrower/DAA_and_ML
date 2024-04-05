#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    FILE *fp = fopen("time_vs_n_insertion.csv", "w");
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

            for (int i = 1; i < n; i++) 
                for (int j = i - 1; j >= 0 && A[j] > A[j + 1]; j--) 
                    { int temp = A[j]; A[j] = A[j + 1]; A[j + 1] = temp; }

            clock_gettime(CLOCK_MONOTONIC, &end); 

            double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
            fprintf(fp, "%d,%.6f\n", n, time_taken);
        }
    }
    fclose(fp);
    printf("Experiment completed. Results saved to time_vs_n_insertion.csv.\n");
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
    //                                                             --------> THIS COMMENTED SECTION HAS THE SAME SYNTAX FOR ALL 5 TYPES OF SORT WHERE "....." is CHANGED
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
