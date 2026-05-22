#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    cout << "[";
    for (int i = 0; i < matrix.size(); i++) {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < matrix.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    cout << "Test case 1:" << endl;
    cout << "Input: ";
    printMatrix(matrix1);
    
    solution.rotate(matrix1);
    
    cout << "Output: ";
    printMatrix(matrix1);
    cout << "Expected: [[7,4,1],[8,5,2],[9,6,3]]" << endl;
    cout << endl;
    
    // Test case 2
    vector<vector<int>> matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    
    cout << "Test case 2:" << endl;
    cout << "Input: ";
    printMatrix(matrix2);
    
    solution.rotate(matrix2);
    
    cout << "Output: ";
    printMatrix(matrix2);
    cout << "Expected: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]" << endl;
    
    return 0;
}