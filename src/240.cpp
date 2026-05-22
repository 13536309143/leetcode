#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) // 从右上角开始搜索
    {
        if (matrix.empty() || matrix[0].empty()) // 空矩阵
        {
            return false;// 空矩阵，直接返回false
        }
        
        int rows = matrix.size();// 行数
        int cols = matrix[0].size();// 列数
        
        int row = 0;// 当前行行索引
        int col = cols - 1;// 当前列列索引
        
        while (row < rows && col >= 0) // 当前行行索引在矩阵范围内，当前列列索引在矩阵范围内
        {
            if (matrix[row][col] == target) // 当前元素等于目标值
            {
                return true;// 找到目标值，返回true
            } else if (matrix[row][col] > target) // 当前元素大于目标值
            {
                col--;// 当前元素大于目标值，向左移动一列
            } else {
                row++;// 当前元素小于目标值，向下移动一行
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target1 = 5;
    cout << "Input: target = 5" << endl;
    cout << "Output: " << (sol.searchMatrix(matrix1, target1) ? "true" : "false") << endl;
    
    cout << "\nTest Case 2:" << endl;
    int target2 = 20;
    cout << "Input: target = 20" << endl;
    cout << "Output: " << (sol.searchMatrix(matrix1, target2) ? "true" : "false") << endl;
    
    return 0;
}