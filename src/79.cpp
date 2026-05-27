#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) // 递归 + 回溯
    {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.size()) {
            return true;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        
        board[i][j] = temp;
        
        return found;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word1 = "ABCCED";
    bool result1 = solution.exist(board1, word1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = \"ABCCED\"" << endl;
    cout << "Output: " << (result1 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test case 2
    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word2 = "SEE";
    bool result2 = solution.exist(board2, word2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = \"SEE\"" << endl;
    cout << "Output: " << (result2 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test case 3
    vector<vector<char>> board3 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word3 = "ABCB";
    bool result3 = solution.exist(board3, word3);
    
    cout << "Test case 3:" << endl;
    cout << "Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = \"ABCB\"" << endl;
    cout << "Output: " << (result3 ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    
    return 0;
}