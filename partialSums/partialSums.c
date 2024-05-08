#include <stdio.h>
#include <stdlib.h> /* For dynamic memory allocation */

/* Function prototype */
int* partialSums(int array[], int size);

int main() {

    int size;
    int* myArray;
    int* result;
    int i = 0;

    /* prompt the user for input */
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    /* Dynamically allocate memory for the array */
    myArray = (int*)malloc(size * sizeof(int));
    if (myArray == NULL) {
        printf("Memory allocation failed");
        exit(0);
    }

    /* Getting input for each element of the array from the user */
    printf("\nEnter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &myArray[i]);
    }

    /* Display the size of the array */
    printf("\nSize of the array: %d\n\n", size);

    /* Display the input */
    printf("Array data:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }

    /* Calling partialSums */
    result = partialSums(myArray, size);

    /* Print the new array containing partial sums */
    printf("\n\nNew array with partial sums:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    printf("\n\n");

    /* Free dynamically allocated memory */
    free(myArray);
    free(result);  

    return 0;
}

/* Function definition */
int* partialSums(int array[], int size) {
    /* Dynamically allocate memory for the new array */
    int* newArray = (int*)malloc(size * sizeof(int));
    int sum = 0;
    int i = 0;
    if (newArray == NULL) {
        printf("Memory allocation failed");
        exit(0);
    }

    /* Calculate partial sums */
    
    for (i = 0; i < size; i++) {
        sum += array[i];
        newArray[i] = sum;
    }

    /* Return a pointer to the new array */
    return newArray;
}
