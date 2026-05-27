#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) // 判断括号是否有效
    {
        stack<char> st;/// 用于存储左括号
        unordered_map<char, char> mapping = {///// 映射表
            {')', '('},///// 右括号对应左括号
            {'}', '{'},///// 右括号对应左括号
            {']', '['}///// 右括号对应左括号
        };
        
        for (char c : s) {// 遍历字符串
            if (mapping.find(c) != mapping.end()) {// 如果是右括号
                if (st.empty() || st.top() != mapping[c]) {// 如果栈为空或栈顶元素不是对应的左括号
                    return false;// 返回false
                }
                st.pop();// 如果是右括号，出栈
            } else {
                st.push(c);// 如果是左括号，入栈
            }
        }
        
        return st.empty();// 如果栈为空，说明所有括号都匹配了
        // 如果栈不为空，说明有括号没有匹配
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "()";
    bool result1 = solution.isValid(s1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: " << (result1 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test case 2
    string s2 = "()[]{}";
    bool result2 = solution.isValid(s2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: s = \"" << s2 << "\"" << endl;
    cout << "Output: " << (result2 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test case 3
    string s3 = "(]";
    bool result3 = solution.isValid(s3);
    
    cout << "Test case 3:" << endl;
    cout << "Input: s = \"" << s3 << "\"" << endl;
    cout << "Output: " << (result3 ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;
    
    // Test case 4
    string s4 = "([])";
    bool result4 = solution.isValid(s4);
    
    cout << "Test case 4:" << endl;
    cout << "Input: s = \"" << s4 << "\"" << endl;
    cout << "Output: " << (result4 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test case 5
    string s5 = "([)]";
    bool result5 = solution.isValid(s5);
    
    cout << "Test case 5:" << endl;
    cout << "Input: s = \"" << s5 << "\"" << endl;
    cout << "Output: " << (result5 ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    
    return 0;
}