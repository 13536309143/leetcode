#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                if (j >= 2) {
                    dp[0][j] = dp[0][j - 2];
                }
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "aa";
    string p1 = "a";
    bool result1 = solution.isMatch(s1, p1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: s = \"aa\", p = \"a\"" << endl;
    cout << "Output: " << (result1 ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;
    
    // Test case 2
    string s2 = "aa";
    string p2 = "a*";
    bool result2 = solution.isMatch(s2, p2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: s = \"aa\", p = \"a*\"" << endl;
    cout << "Output: " << (result2 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test case 3
    string s3 = "ab";
    string p3 = ".*";
    bool result3 = solution.isMatch(s3, p3);
    
    cout << "Test case 3:" << endl;
    cout << "Input: s = \"ab\", p = \".*\"" << endl;
    cout << "Output: " << (result3 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test case 4
    string s4 = "aab";
    string p4 = "c*a*b";
    bool result4 = solution.isMatch(s4, p4);
    
    cout << "Test case 4:" << endl;
    cout << "Input: s = \"aab\", p = \"c*a*b\"" << endl;
    cout << "Output: " << (result4 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    
    return 0;
}