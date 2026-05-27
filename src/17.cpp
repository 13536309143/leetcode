#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {// 17. 电话号码的字母组合
        vector<string> result;// 结果向量
        if (digits.empty()) {// 如果输入为空
            return result;// 返回空向量
        }
        
        unordered_map<char, string> mapping = {// 映射表
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        string current;// 当前字符串
        backtrack(digits, 0, mapping, current, result);// 回溯函数
        return result;// 返回结果向量
    }
    
    void backtrack(string& digits, int index, unordered_map<char, string>& mapping, 
                   string& current, vector<string>& result) {// 回溯函数
        if (index == digits.size()) {// 如果当前索引等于输入字符串的长度
            result.push_back(current);// 将当前字符串添加到结果向量
            return;// 返回
        }
        
        string letters = mapping[digits[index]];// 获取当前数字对应的字母
        for (char c : letters) {// 遍历当前数字对应的字母
            current.push_back(c);// 将当前字母添加到当前字符串
            backtrack(digits, index + 1, mapping, current, result);// 递归调用回溯函数
            current.pop_back();// 回溯，将当前字母从当前字符串中移除
        }
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string digits1 = "23";
    vector<string> result1 = solution.letterCombinations(digits1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: digits = \"23\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Expected: [\"ad\",\"ae\",\"af\",\"bd\",\"be\",\"bf\",\"cd\",\"ce\",\"cf\"]" << endl;
    cout << endl;
    
    // Test case 2
    string digits2 = "2";
    vector<string> result2 = solution.letterCombinations(digits2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: digits = \"2\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Expected: [\"a\",\"b\",\"c\"]" << endl;
    cout << endl;
    
    // Test case 3: empty input
    string digits3 = "";
    vector<string> result3 = solution.letterCombinations(digits3);
    
    cout << "Test case 3:" << endl;
    cout << "Input: digits = \"\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Expected: []" << endl;
    
    return 0;
}