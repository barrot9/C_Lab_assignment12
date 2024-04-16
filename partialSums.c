#include <stdio.h>
#include <stdlib.h> /* For dynamic memory allocation */

/* Function prototype */
int* partialSums(int array[], int size);

int main(int argc, char *argv[]) {
    int size;
    int* myArray;

    /* Check if a file name is provided as a command-line argument */
    if (argc > 1) {
        /* Open the file for reading */
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            fprintf(stderr, "Unable to open file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        /* Read the size of the array from the file */
        fscanf(file, "%d", &size);

        /* Dynamically allocate memory for the array */
        myArray = (int*)malloc(size * sizeof(int));
        if (myArray == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        /* Read input for each element of the array from the file */
        for (int i = 0; i < size; i++) {
            fscanf(file, "%d", &myArray[i]);
        }

        /* Close the file */
        fclose(file);
    } 
    else {
        /* If no file name provided, prompt the user for input */
        printf("Enter the size of the array: ");
        scanf("%d", &size);

        /* Dynamically allocate memory for the array */
        myArray = (int*)malloc(size * sizeof(int));
        if (myArray == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        /* Getting input for each element of the array from the user */
        printf("Enter %d integers:\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &myArray[i]);
        }
    }

    printf("\n");
    /* Display the size of the array */
    printf("Size of the array: %d\n\n", size);

    /* Display the input */
    printf("Array data given by the user:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n\n");

    /* Calling partialSums */
    int* result = partialSums(myArray, size);

    /* Print the new array containing partial sums */
    printf("New array with partial sums:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    /* Free dynamically allocated memory */
    free(myArray);
    free(result); // Free the memory allocated by partialSums

    return 0;
}

/* Function definition */
int* partialSums(int array[], int size) {
    /* Dynamically allocate memory for the new array */
    int* newArray = (int*)malloc(size * sizeof(int));
    if (newArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    /* Calculate partial sums */
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
        newArray[i] = sum;
    }

    /* Return a pointer to the new array */
    return newArray;
}
