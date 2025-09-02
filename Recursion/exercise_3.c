/* 3) Recursive List Sum
Write a recursive function that calculates the sum of the elements in a list.
Example: sum([1, 2, 3, 4]) → 10*/

#include <stdio.h>
#include <stdlib.h>

int sum(int arr[], int n) {
    if (n <= 0) {
        return 0; // Base case: empty array
    } else {
        return arr[n - 1] + sum(arr, n - 1); // Recursive case
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = sum(arr, n);
    printf("Sum of array elements: %d\n", result); // Output: 10
    return 0;
}

