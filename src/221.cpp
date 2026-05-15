#include <iostream>                 // 引入输入输出流库，用于cout输出
#include <vector>                  // 引入向量库，用于存储二维矩阵和dp数组
#include <algorithm>               // 引入算法库，用于min和max函数
using namespace std;              // 使用标准命名空间，简化代码

// Solution类：包含计算最大正方形的方法
class Solution {
public:
    // 方法：动态规划（最优解）
    // 时间复杂度：O(m×n)，空间复杂度：O(m×n)
    // 核心思想：使用动态规划计算每个位置作为右下角的最大正方形边长
    // dp[i][j]表示以矩阵中第i行第j列的元素为右下角的最大正方形的边长
    int maximalSquare(vector<vector<char>>& matrix) {
        // 边界情况检查：如果矩阵为空或第一行为空，返回0
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int m = matrix.size();                     // 获取矩阵的行数
        int n = matrix[0].size();                  // 获取矩阵的列数
        vector<vector<int>> dp(m, vector<int>(n, 0));  // 创建dp数组，初始化为0
        int maxSide = 0;                           // 记录最大正方形的边长
        
        // 遍历矩阵的每个元素
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 如果当前位置是'1'，则可以形成正方形
                if (matrix[i][j] == '1') {
                    // 边界情况：第一行或第一列
                    // 这些位置只能形成边长为1的正方形（如果是'1'的话）
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // 状态转移方程：
                        // 当前位置的最大正方形边长 = min(左上角, 左边, 上边) + 1
                        // 这三个方向中的最小值决定了当前能形成的最大正方形
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    
                    // 更新最大边长
                    maxSide = max(maxSide, dp[i][j]);
                }
                // 如果当前位置是'0'，则dp[i][j]保持为0，无法形成正方形
            }
        }
        
        // 返回最大正方形的面积（边长的平方）
        return maxSide * maxSide;
    }
};

// 主函数：测试代码
int main() {
    Solution sol;  // 创建Solution类对象sol
    
    // 测试用例1：4x5矩阵，最大正方形面积为4
    cout << "Test Case 1:" << endl;
    vector<vector<char>> matrix1 = {
        {'1','0','1','0','0'},   // 第一行
        {'1','0','1','1','1'},   // 第二行
        {'1','1','1','1','1'},   // 第三行
        {'1','0','0','1','0'}    // 第四行
    };
    cout << "Input: [[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]" << endl;
    cout << "Output: " << sol.maximalSquare(matrix1) << endl;
    
    // 测试用例2：2x2矩阵，最大正方形面积为1
    cout << "\nTest Case 2:" << endl;
    vector<vector<char>> matrix2 = {
        {'0','1'},   // 第一行
        {'1','0'}    // 第二行
    };
    cout << "Input: [[0,1],[1,0]]" << endl;
    cout << "Output: " << sol.maximalSquare(matrix2) << endl;
    
    // 测试用例3：1x1矩阵，只有一个'0'，面积为0
    cout << "\nTest Case 3:" << endl;
    vector<vector<char>> matrix3 = {
        {'0'}    // 第一行
    };
    cout << "Input: [[0]]" << endl;
    cout << "Output: " << sol.maximalSquare(matrix3) << endl;
    
    return 0;  // 程序正常结束
}
