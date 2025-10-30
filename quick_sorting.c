//quick sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int used_pivots[100];
int used_count = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    // store the pivots in the array if same pivot is repeated the regenerate the pivot again
    int randomIndex;
    int pivot;
    do {
        randomIndex = low + rand() % (high - low + 1);
        pivot = arr[randomIndex];
        int found = 0;
        for (int k = 0; k < used_count; k++) {
            if (used_pivots[k] == pivot) {
                found = 1;
                break;
            }
        }
        if (!found) break;
    } while (1);
    used_pivots[used_count++] = pivot;
    swap(&arr[randomIndex], &arr[high]);
    pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    FILE *fp = fopen("Inputs/input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    int arr[100]; // assuming max 100 elements
    int size = 0;
    while (fscanf(fp, "%d", &arr[size]) != EOF && size < 100) {
       size++;
    }
    fclose(fp);

    printf("The input array from the file is with the %d size\nThe elements are : [",size);
    size -= 1;
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n",arr[size]);

    used_count = 0;
    QuickSort(arr, 0, size);

    FILE *out = fopen("Outputs/QuickSortOutput.txt", "w");
    if (out == NULL) {
        printf("Error opening out.txt\n");
        return 1;
    }

    printf("After the Quick Sort the Elements are : [");

    for (int i = 0; i < size; i++) {
        fprintf(out, "%d ", arr[i]);
        printf("%d, ", arr[i]);
    }
    fprintf(out, "%d ", arr[size]);
    printf("%d]\n",arr[size]);
    
    fprintf(out, "\n");
    
    fclose(out);

    return 0;
}
