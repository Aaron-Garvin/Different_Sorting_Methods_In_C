#include <stdio.h>

// Function to merge two sorted halves into one sorted array
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;

    // Sizes of two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int first[50];   // Size should be >= n1
    int second[50];  // Size should be >= n2

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        first[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        second[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[]
    i = 0; // index of first[]
    j = 0; // index of second[]
    k = left; // index of merged array

    while (i < n1 && j < n2) {
        if (first[i] <= second[j]) {
            arr[k] = first[i];
            i++;
        } else {
            arr[k] = second[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of first[]
    while (i < n1) {
        arr[k] = first[i];
        i++;
        k++;
    }

    // Copy any remaining elements of second[]
    while (j < n2) {
        arr[k] = second[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Recursively divide
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
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
    int arr[] = {8, 4, 6, 2, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1); // Call merge sort

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
