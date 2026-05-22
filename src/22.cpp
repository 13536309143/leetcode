#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);/// 回溯函数，用于生成所有可能的括号组合
        return result;// 返回结果向量
    }
    
private:
    void backtrack(vector<string>& result, string& current, int open, int close, int n) // 回溯函数，用于生成所有可能的括号组合
    {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back();
        }
        
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back();
        }
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    int n1 = 3;
    vector<string> result1 = solution.generateParenthesis(n1);
    
    cout << "Test case 1: n = " << n1 << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Expected: [\"((()))\", \"(()())\", \"(())()\", \"()(())\", \"()()()\"]" << endl;
    cout << endl;
    
    // Test case 2
    int n2 = 1;
    vector<string> result2 = solution.generateParenthesis(n2);
    
    cout << "Test case 2: n = " << n2 << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Expected: [\"()\"]" << endl;
    
    return 0;
}