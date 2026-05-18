#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << "Input: s = \"leetcode\", wordDict = [\"leet\", \"code\"]" << endl;
    cout << "Output: " << (sol.wordBreak(s1, wordDict1) ? "true" : "false") << endl;
    
    cout << "\nTest Case 2:" << endl;
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << "Input: s = \"applepenapple\", wordDict = [\"apple\", \"pen\"]" << endl;
    cout << "Output: " << (sol.wordBreak(s2, wordDict2) ? "true" : "false") << endl;
    
    cout << "\nTest Case 3:" << endl;
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Input: s = \"catsandog\", wordDict = [\"cats\", \"dog\", \"sand\", \"and\", \"cat\"]" << endl;
    cout << "Output: " << (sol.wordBreak(s3, wordDict3) ? "true" : "false") << endl;
    
    return 0;
}