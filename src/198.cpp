#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // 动态规划
        // dp[i] 表示到第 i 个房屋时的最大金额
        // dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        // 初始化 dp 数组
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        // 遍历数组，计算 dp[i]
        for (int i = 2; i < n; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        // 返回 dp[n-1]
        // 因为 dp[n-1] 表示到第 n 个房屋时的最大金额
        // 而 dp[n-1] 就是最后房屋的最大金额
        // 所以返回 dp[n-1] 就是最后房屋的最大金额
        return prev1;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Input: [1,2,3,1]" << endl;
    cout << "Output: " << sol.rob(nums1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Input: [2,7,9,3,1]" << endl;
    cout << "Output: " << sol.rob(nums2) << endl;
    
    return 0;
}
