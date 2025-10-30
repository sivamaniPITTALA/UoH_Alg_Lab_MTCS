#include<stdio.h>

void counting_sort(int *arr, int n, int max) {
    int frequency[max], i;
    for (i = 0; i < max; i++) {
        frequency[i] = 0;
    }
    for (i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }

    printf("Frequency array: ");
    print_array(frequency, max);

    int position[max];
    position[0] = frequency[0];
    for (i = 1; i < max; i++){
        position[i] = position[i-1] + frequency[i];
    }
    printf("Position array: ");
    print_array(position, max);

    int b[n];
    for (i = 0; i < n; i++){
        position[arr[i]] -= 1;
        b[position[arr[i]]] = arr[i];
    }
    printf("Sorted array: ");
    print_array(b, n);

    arr = b;

}

/// @brief 
/// @param arr 
/// @param n 
void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    int* a;

   counting_sort(arr, len, max + 1);
    
    return 0;
}