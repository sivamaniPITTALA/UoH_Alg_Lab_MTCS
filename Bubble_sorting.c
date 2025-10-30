#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, int n) { 
    for (int i = 0; i < n - 1; i++) {
        int flag = 1;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                flag = 0;
            }
        }
        if (flag) {
            break;
        }
    }
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);

    int arr[len];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    print_array(arr, len);

    bubble_sort(arr, len);

    printf("Sorted array: ");
    print_array(arr, len);
    
    return 0;
}