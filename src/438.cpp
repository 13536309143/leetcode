#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {//  找到字符串中所有字母异位词
        vector<int> result;//  存储结果的向量
        int sLen = s.size();//  字符串s的长度
        int pLen = p.size();//  字符串p的长度
        
        if (sLen < pLen) {//  如果字符串s的长度小于字符串p的长度，直接返回空向量
            return result;//  返回空向量
        }
        
        vector<int> pCount(26, 0);//  字符串p中每个字母出现的次数
        vector<int> sCount(26, 0);//  字符串s中每个字母出现的次数
        
        for (int i = 0; i < pLen; i++) {//  统计字符串p中每个字母出现的次数
            pCount[p[i] - 'a']++;//  统计字符串p中每个字母出现的次数
            sCount[s[i] - 'a']++;//  统计字符串s中每个字母出现的次数
        }
        
        if (pCount == sCount) {//  如果字符串p和字符串s的每个字母出现的次数都相同，说明字符串s的前pLen个字符是字符串p的字母异位词
            result.push_back(0);//  将0添加到结果向量中
        }
        
        for (int i = pLen; i < sLen; i++) {//  遍历字符串s的剩余字符
            sCount[s[i] - 'a']++;//  统计字符串s中每个字母出现的次数
            sCount[s[i - pLen] - 'a']--;//  统计字符串s中每个字母出现的次数
            
            if (pCount == sCount) {//  如果字符串p和字符串s的每个字母出现的次数都相同，说明字符串s的当前字符是字符串p的字母异位词
                result.push_back(i - pLen + 1);//  将当前字符的索引添加到结果向量中
            }
        }
        
        return result;//  返回结果向量
    }
};
        
int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    string s1 = "cbaebabacd";
    string p1 = "abc";
    cout << "Input: s = \"cbaebabacd\", p = \"abc\"" << endl;
    vector<int> result1 = sol.findAnagrams(s1, p1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 2:" << endl;
    string s2 = "abab";
    string p2 = "ab";
    cout << "Input: s = \"abab\", p = \"ab\"" << endl;
    vector<int> result2 = sol.findAnagrams(s2, p2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}