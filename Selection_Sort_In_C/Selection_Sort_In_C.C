#include <stdio.h>

/*
<stdio.h> : It is a header file that contains declarations (predefined code) for standard input/output functions
*/

void selectionSort(int arr[], int n) {

//Here we take array and size of array (n) as parameters of the function
    

    int i, j, minIndex, temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
/*
Here the inner for loop is use to compare every value with the first unsorted element,
untill we get smaller value then the first unsorted value
*/

//Then Swap the smallest element with the first unsorted element 

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

//After the swap we start getting our first, secound, third....... sorted element
    
}

/*
The outter for loop trys to repeat the comparing and swap process till n-1
*/

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Function use to print the array

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array (ascending): ");
    printArray(arr, n);

    return 0;
}
