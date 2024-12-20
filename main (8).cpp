#include <iostream>

using namespace std;

void quickSort(int arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void countSort(int arr, int n) {
    int output[n];
    int count[10] = {0};

    // Store count of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Change count[i] so that count[i] now contains actual position of
    // this digit in output
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr, so that arr now
    // contains sorted numbers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(int arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: \n";
    printArray(arr, n);

    // Quick Sort
    quickSort(arr, 0, n - 1);
    cout << "Sorted array using Quick Sort: \n";
    printArray(arr, n);

    // Reset the array
    for (int i = 0; i < n; i++)
        arr[i] = {64, 34, 25, 12, 22, 11, 90};

    // Counting Sort (for smaller ranges)
    countSort(arr, n);
    cout << "Sorted array using Counting Sort: \n";
    printArray(arr, n);

    return 0;
}