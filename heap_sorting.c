#include <stdio.h>

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void heapify(int arr[], int n, int i) {
    int largest = i;          
    int left = 2 * i + 1;    
    int right = 2 * i + 2;    

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
    // Build max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (largest) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
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

    heapSort(arr, len);

    printf("Sorted array: ");
    print_array(arr, len);

    return 0;
}