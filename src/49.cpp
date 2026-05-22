#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)// 分组异位词
     {
        unordered_map<string, vector<string>> map;// 异位词映射
        
        for (string s : strs) {// 遍历字符串数组
            string key = s;// 当前字符串
            sort(key.begin(), key.end());// 对当前字符串排序
            map[key].push_back(s);// 将当前字符串添加到异位词映射中
        }
        
        vector<vector<string>> result;// 结果向量
        for (auto& pair : map) {// 遍历异位词映射
            result.push_back(pair.second);// 将当前异位词组添加到结果向量
        }
        
        return result;// 返回结果向量
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = solution.groupAnagrams(strs1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: [\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "[";
        for (int j = 0; j < result1[i].size(); j++) {
            cout << "\"" << result1[i][j] << "\"";
            if (j < result1[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << endl;
    
    // Test case 2
    vector<string> strs2 = {""};
    vector<vector<string>> result2 = solution.groupAnagrams(strs2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: [\"\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "[";
        for (int j = 0; j < result2[i].size(); j++) {
            cout << "\"" << result2[i][j] << "\"";
            if (j < result2[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << endl;
    
    // Test case 3
    vector<string> strs3 = {"a"};
    vector<vector<string>> result3 = solution.groupAnagrams(strs3);
    
    cout << "Test case 3:" << endl;
    cout << "Input: [\"a\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << "[";
        for (int j = 0; j < result3[i].size(); j++) {
            cout << "\"" << result3[i][j] << "\"";
            if (j < result3[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result3.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}