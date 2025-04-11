#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;

    // Start from index 1 (second element)
    for (i = 1; i < n; i++) {
        key = arr[i];        // Store the current element
        j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift the larger element to the right
            j = j - 1;            // Move to the previous element
        }

        // Insert the key at the correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {5, 3, 8, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements

    printf("Original array: ");
    printArray(arr, n);  // Show array before sorting

    insertionSort(arr, n);  // Sort the array

    printf("Sorted array (ascending): ");
    printArray(arr, n);  // Show array after sorting

    return 0;
}
