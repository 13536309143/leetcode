#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 遍历网格中的每个位置
    // 如果当前位置是 '1'，则将岛屿数量加一
    // 并使用深度优先搜索（DFS）将当前岛屿的所有 '1' 标记为已访问
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << "Input:" << endl;
    for (auto& row : grid1) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "Output: " << sol.numIslands(grid1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Input:" << endl;
    for (auto& row : grid2) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "Output: " << sol.numIslands(grid2) << endl;
    
    return 0;
}
