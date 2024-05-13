#include <stdio.h>
#include <string.h>

void bruteForceStringMatch(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;

    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Brute force string matching algorithm:\n");
    bruteForceStringMatch(text, pattern);
    return 0;
}
