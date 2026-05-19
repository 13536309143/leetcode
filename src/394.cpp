#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {//  解码字符串
        
        stack<int> countStack;//  计数栈
        stack<string> stringStack;//  字符串栈
        string currentString = "";//  当前字符串
        int count = 0;//  当前计数
        
        for (char c : s) {//  遍历所有字符
            if (isdigit(c)) {//  如果字符是数字
                count = count * 10 + (c - '0');//  累加计数
            } else if (c == '[') {//  如果字符是左括号
                countStack.push(count);//  将当前计数压入栈
                stringStack.push(currentString);//  将当前字符串压入栈
                currentString = "";//  清空当前字符串
                count = 0;//  重置当前计数
            } else if (c == ']') {//  如果字符是右括号
                string prevString = stringStack.top();//  从栈顶获取上一个字符串
                stringStack.pop();//  从栈顶弹出上一个字符串
                int repeatCount = countStack.top();//  从栈顶获取上一个计数
                countStack.pop();//  从栈顶弹出上一个计数
                
                for (int i = 0; i < repeatCount; i++) {//  重复当前字符串
                    prevString += currentString;//  累加当前字符串
                }
                currentString = prevString;//  更新当前字符串
            } else {
                currentString += c;//  累加当前字符
            }
        }
        
        return currentString;//  返回当前字符串
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    string s1 = "3[a]2[bc]";
    cout << "Input: s = \"3[a]2[bc]\"" << endl;
    cout << "Output: \"" << sol.decodeString(s1) << "\"" << endl;
    
    cout << "\nTest Case 2:" << endl;
    string s2 = "3[a2[c]]";
    cout << "Input: s = \"3[a2[c]]\"" << endl;
    cout << "Output: \"" << sol.decodeString(s2) << "\"" << endl;
    
    cout << "\nTest Case 3:" << endl;
    string s3 = "2[abc]3[cd]ef";
    cout << "Input: s = \"2[abc]3[cd]ef\"" << endl;
    cout << "Output: \"" << sol.decodeString(s3) << "\"" << endl;
    
    cout << "\nTest Case 4:" << endl;
    string s4 = "abc3[cd]xyz";
    cout << "Input: s = \"abc3[cd]xyz\"" << endl;
    cout << "Output: \"" << sol.decodeString(s4) << "\"" << endl;
    
    return 0;
}