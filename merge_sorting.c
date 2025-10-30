//Merge sort
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2]; 

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


void mergeSort(int arr[], int size) {
    if (size > 0) {
        mergeSortHelper(arr, 0, size);
    }
}

int main() {
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

    mergeSort(arr, size);

    FILE *out = fopen("Outputs/MergeOutput.txt", "w");
    if (out == NULL) {
        printf("Error opening out.txt\n");
        return 1;
    }

    printf("After the Merge Sort the Elements are : [");

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