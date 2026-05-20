#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) //  广度优先搜索
    {
        vector<string> result;//  存储结果的向量
        queue<string> q;//  广度优先搜索的队列
        unordered_set<string> visited;//  存储已访问的字符串的集合
        q.push(s);//  将初始字符串s入队
        visited.insert(s);//  将初始字符串s加入已访问集合
        bool found = false;//  标志是否找到有效字符串
        //  广度优先搜索
        while (!q.empty()) {//  当队列不为空时，继续搜索
            int size = q.size();//  当前队列的大小
            //  遍历当前队列中的所有字符串
            for (int i = 0; i < size; i++) {//  遍历当前队列中的所有字符串
                string current = q.front();//  获取当前队列中的字符串
                q.pop();//  出队
                if (isValid(current)) {//  如果当前字符串是有效字符串
                    result.push_back(current);//  将有效字符串加入结果向量
                    found = true;//  标志找到有效字符串
                }
                if (found) {//  如果已经找到有效字符串，继续下一个字符串
                    continue;
                }
                for (int j = 0; j < current.size(); j++) {//  遍历当前字符串中的所有字符
                    if (current[j] != '(' && current[j] != ')') {//  如果当前字符不是括号，继续下一个字符
                        continue;
                    }
                    string next = current.substr(0, j) + current.substr(j + 1);//  从当前字符串中删除当前字符
                    //  如果下一个字符串未被访问过，加入队列和已访问集合
                    if (visited.find(next) == visited.end()) {//  如果下一个字符串未被访问过
                        visited.insert(next);//  加入已访问集合
                        q.push(next);//  加入队列
                    }
                }
            }
            
            if (found) {//  如果已经找到有效字符串，继续下一个字符串
                break;
            }
        }
        
        return result;//  返回结果向量
    }
    
private:
    bool isValid(string s) {//  检查字符串是否是有效括号字符串
        int count = 0;//  初始化计数器
        for (char c : s) {//  遍历字符串中的所有字符
            if (c == '(') {//  如果当前字符是左括号
                count++;//  增加计数器
            } else if (c == ')') {//  如果当前字符是右括号
                count--;//  减少计数器
                if (count < 0) {//  如果计数器小于0，说明括号匹配失败
                    return false;//  返回false
                }
            }
        }
        return count == 0;//  如果计数器等于0，说明括号匹配成功，返回true
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    string s1 = "()())()";
    cout << "Input: s = \"" << s1 << "\"" << endl;
    vector<string> result1 = sol.removeInvalidParentheses(s1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 2:" << endl;
    string s2 = "(a)())()";
    cout << "Input: s = \"" << s2 << "\"" << endl;
    vector<string> result2 = sol.removeInvalidParentheses(s2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 3:" << endl;
    string s3 = ")(";
    cout << "Input: s = \"" << s3 << "\"" << endl;
    vector<string> result3 = sol.removeInvalidParentheses(s3);
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}