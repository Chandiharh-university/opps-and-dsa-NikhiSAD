#include <iostream>
#include <vector>
#include <limits>

int findSecondLargest(const std::vector<int>& arr) {
    int largest = std::numeric_limits<int>::min();
    int secondLargest = std::numeric_limits<int>::min();

    for (int num : arr) {
        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest && num < largest) {
            secondLargest = num;
        }
    }
    return secondLargest;
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int& num : arr) {
        std::cin >> num;
    }

    int result = findSecondLargest(arr);
    if (result == std::numeric_limits<int>::min()) {
        std::cout << "No second largest element found.\n";
    } else {
        std::cout << "The second largest element is: " << result << std::endl;
    }

    return 0;
}
