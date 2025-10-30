#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion(int arr[], int n, int key) {
    int j = n - 2; 

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
    printf("%d is inserted at %d index position in array\n", key, j + 1);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    while (1) {
        char choice;
        
        printf("Do you want to insert a new element?? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            int temp;

            printf("Enter the new element you want to insert: ");
            scanf("%d", &temp);
            n++;

            int *newArr = (int *)realloc(arr, n * sizeof(int));

            if (newArr == NULL) {
                printf("Memory reallocation failed.\n");
                free(arr);
                return 1;
            }
            arr = newArr;
            insertion(arr, n, temp);

            printf("Inserted array: ");
            printArray(arr, n);
        }
        else {
            break;
        }
    }
    free(arr);
    return 0;
}