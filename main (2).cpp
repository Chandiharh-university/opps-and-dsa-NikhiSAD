#in#include <iostream>
#include <vector>

void multiplyMatrices(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) {
    int rows1 = mat1.size(), cols1 = mat1[0].size();
    int rows2 = mat2.size(), cols2 = mat2[0].size();

    if (cols1 != rows2) {
        std::cout << "Matrix multiplication is not possible.\n";
        return;
    }

    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    std::cout << "Resultant Matrix:\n";
    for (const auto& row : result) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    std::cout << "Enter rows and columns for Matrix 1: ";
    std::cin >> rows1 >> cols1;
    std::cout << "Enter rows and columns for Matrix 2: ";
    std::cin >> rows2 >> cols2;

    std::vector<std::vector<int>> mat1(rows1, std::vector<int>(cols1));
    std::vector<std::vector<int>> mat2(rows2, std::vector<int>(cols2));

    std::cout << "Enter elements of Matrix 1:\n";
    for (auto& row : mat1) {
        for (int& elem : row) {
            std::cin >> elem;
        }
    }

    std::cout << "Enter elements of Matrix 2:\n";
    for (auto& row : mat2) {
        for (int& elem : row) {
            std::cin >> elem;
        }
    }

    multiplyMatrices(mat1, mat2);

    return 0;
}

