#include <stdio.h>

// Function to swap two numbers using index
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Use last element as pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j); // Swap current element with smaller element
        }
    }

    swap(arr, i + 1, high); // Place pivot in correct position
    return i + 1;           // Return pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Get partition index

        // Recursively sort left and right parts
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {9, 4, 6, 2, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1); // Sort the array

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
