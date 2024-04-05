#include <stdio.h>
#include <string.h>

#define M 100

int main() {
    char T[M], P[6];
    int n, m, i = -1;

    printf("Enter pattern (max 5 characters): ");
    scanf("%s", P);

    FILE *f = fopen("input.txt", "r");
    if (!f) { printf("Error opening file!\n"); return 1; }
    fgets(T, M, f);
    fclose(f);

    for (; (n = strlen(T)), (m = strlen(P)), ++i <= n - m;)
        for (int j = 0; j < m && P[j] == T[i + j]; ++j)
            if (j == m - 1) 
            { 
                printf("Pattern found at index: %d\n", i); 
                return 0; 
            }

    printf("Pattern not found.\n");
    return 0;
}
