#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> val(n + 2, 1);
        
        for (int i = 0; i < n; i++) {
            val[i + 1] = nums[i];
        }
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + val[i - 1] * val[k] * val[j + 1]);
                }
            }
        }
        
        return dp[1][n];
    }
};


int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {3, 1, 5, 8};
    cout << "Input: nums = [3,1,5,8]" << endl;
    cout << "Output: " << sol.maxCoins(nums1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {1, 5};
    cout << "Input: nums = [1,5]" << endl;
    cout << "Output: " << sol.maxCoins(nums2) << endl;
    
        
    cout << "\nTest Case 3:" << endl;
    vector<int> nums3 = {1,7,5,8,3,2,4,6,8,6,5,2,7};
    cout << "Input: nums = [1,7,5,8,3,2,4,6,8,6,5,2,7]" << endl;
    cout << "Output: " << sol.maxCoins(nums3) << endl;
    
    return 0;
}