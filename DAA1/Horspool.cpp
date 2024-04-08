#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATTERN_LENGTH 5
#define STRING_LENGTH 20
#define ALPHABET_SIZE 256

void generateShiftTable(char pattern[], int shiftTable[]) 
{
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        shiftTable[i] = PATTERN_LENGTH;
    }
    for (i = 0; i < PATTERN_LENGTH - 1; i++)
    {
        shiftTable[pattern[i]] = PATTERN_LENGTH - 1 - i;
    }
}

int horspoolSearch(char pattern[], char string[], int shiftTable[]) 
{
    int patternLength = strlen(pattern);
    int stringLength = strlen(string);
    int i = PATTERN_LENGTH - 1;

    while (i < stringLength) 
    {
        int j = 0;
        while (j < patternLength && pattern[PATTERN_LENGTH - 1 - j] == string[i - j])
        {
            j++;
        }
        if (j == patternLength)
        {
            return i - PATTERN_LENGTH + 1;
        }

        i += shiftTable[string[i]];
    }
    
    return -1;
}

int main() 
{
    char pattern[PATTERN_LENGTH + 1];
    char string[STRING_LENGTH + 1];

    printf("Enter the pattern (5 characters): ");
    fgets(pattern, sizeof(pattern), stdin);

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return 1;
    }

    fgets(string, sizeof(string), file);

    fclose(file);

    int shiftTable[ALPHABET_SIZE];
    generateShiftTable(pattern, shiftTable);

    printf("Shift Table:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {
        if (shiftTable[i] != PATTERN_LENGTH) 
        {
            printf("%c: %d\n", i, shiftTable[i]);
        }
    }

    int position = horspoolSearch(pattern, string, shiftTable);

    if (position != -1)
        printf("Pattern found at position: %d\n", position);
    else
        printf("Pattern not found.\n");

    return 0;
}
