#include <stdio.h>

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void counting_sort(int *arr, int n, int exp) {
    int frequency[10] = {0};
    int output[n];

    // Count frequency of digits
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        frequency[digit]++;
    }

    // Compute cumulative frequency (position)
    for (int i = 1; i < 10; i++) {
        frequency[i] += frequency[i - 1];
    }

    // Build the output array from right to left to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[frequency[digit] - 1] = arr[i];
        frequency[digit]--;
    }

    // Copy output to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int *arr, int n, int max) {
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(arr, n, exp);
    }
}

int main() {
    int len, max = 0;
    printf("Enter the length of the array: ");
    scanf("%d", &len);

    int arr[len];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Original array: ");
    print_array(arr, len);

    radixSort(arr, len, max);

    printf("Sorted array: ");
    print_array(arr, len);

    return 0;
}