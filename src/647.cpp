#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    string s1 = "abc";
    cout << "Input: s = \"abc\"" << endl;
    cout << "Output: " << sol.countSubstrings(s1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    string s2 = "aaa";
    cout << "Input: s = \"aaa\"" << endl;
    cout << "Output: " << sol.countSubstrings(s2) << endl;
    
    return 0;
}