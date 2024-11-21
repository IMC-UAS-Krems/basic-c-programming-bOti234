#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int is_positive_integer(const char *str) {
    // Check if the string is a valid positive integer
    char *endptr;
    long val = strtol(str, &endptr, 10);

    // Validate conversion and check if the value is greater than 0
    if (*endptr != '\0' || val <= 0) {
        return 0; // Not a valid positive integer
    }
    return 1; // Valid positive integer
}


int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE
    if(argc != 3)
    {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc-1);
        return 0;
    }

    int data[2];
    for(int i = 1; i < argc; i++)
    {
        if(!is_positive_integer(argv[i]))
        {
            printf("Incorrect usage. The parameters you provided are not positive integers\n");
            return 0;
        }
        data[i-1] = strtol(argv[i], NULL, 10);
    }

    int rows = data[0];
    int cols = data[1];
    
    int matrix[rows][cols];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            int random_number = rand() % (maxrand - minrand + 1) + minrand;
            matrix[i][j] = random_number;
        }
    }

    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) 
    {
        printf("Error opening file for writing.\n");
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1)
            {
                fprintf(file, " ");  // Print space between numbers, except after the last number
            }
        }
        if(i == rows - 1)
        {
            fprintf(file, "\r");
        }
        else
        {
            fprintf(file, "\n");
        }
    }
    fclose(file);

    return 0;
}