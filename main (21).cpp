#include <iostream>
#include <vector>
using namespace std;

void findCombinations(int target, int start, vector<int>& combination, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }

    for (int i = start; i <= target; ++i) {
        combination.push_back(i);
        findCombinations(target - i, i, combination, result);
        combination.pop_back();
    }
}

vector<vector<int>> generateNumbersWithSum(int sum) {
    vector<vector<int>> result;
    vector<int> combination;
    findCombinations(sum, 1, combination, result);
    return result;
}

int main() {
    int sum = 5; // Example input
    vector<vector<int>> result = generateNumbersWithSum(sum);

    cout << "Combinations for sum " << sum << ":\n";
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
