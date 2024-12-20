#include <iostream>
#include <vector>

using namespace std;

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}

void bucketSort(int arr[], int n) {
    vector<vector<int>> buckets(10);

    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < 10; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Merge the sorted buckets
    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: \n";
    printArray(arr, n);

    // Radix Sort
    radixSort(arr, n);
    cout << "Sorted array using Radix Sort: \n";
    printArray(arr, n);

    // Reset the array
    for (int i = 0; i < n; i++)
        arr[i] = {170, 45, 75, 90, 802, 24, 2, 66};

    // Bucket Sort
    bucketSort(arr, n);
    cout << "Sorted array using Bucket Sort: \n";
    printArray(arr, n);

    return 0;
}