#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        return dp[n];
    }
};

int main() {
    
    cout << "Test Case 1:" << endl;
    int n1 = 12;
    cout << "Input: n = 12" << endl;
    cout << "Output: " << Solution().numSquares(n1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    int n2 = 13;
    cout << "Input: n = 13" << endl;
    cout << "Output: " << Solution().numSquares(n2) << endl;
    
    return 0;
}