#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) // 32. 最长有效括号
    {
        stack<int> st;// 存储括号的索引，用于计算有效括号的长度
        st.push(-1);// 初始化栈，-1 表示字符串开头没有括号
        int max_len = 0;// 最大有效括号长度
        
        for (int i = 0; i < s.size(); i++) {// 遍历字符串中的每个字符
            // 如果当前字符是左括号，将其索引入栈
            if (s[i] == '(') // 左括号入栈
            {
                st.push(i);// 左括号入栈，记录其索引
            }
             else 
            {
                st.pop();// 右括号出栈，记录其索引
                if (st.empty()) 
                {
                    st.push(i);// 右括号入栈，记录其索引
                } else 
                {
                    max_len = max(max_len, i - st.top());// 更新最大有效括号长度
                }
            }
        }
        
        return max_len;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "(()";
    int result1 = solution.longestValidParentheses(s1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: s = \"(()\"" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 2" << endl;
    cout << endl;
    
    // Test case 2
    string s2 = ")()())()))()()()()))((()()()()))";
    int result2 = solution.longestValidParentheses(s2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: s = \")()())()))()()()()))((()()()()))\"" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 4" << endl;
    cout << endl;
    
    // Test case 3
    string s3 = "";
    int result3 = solution.longestValidParentheses(s3);
    
    cout << "Test case 3:" << endl;
    cout << "Input: s = \"\"" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: 0" << endl;
    
    return 0;
}