#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    // 检查是否可以将数组分成两个和相等的子集
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);//  计算数组总和
        //  如果总和为奇数，不能分为两个相等的子集
        if (sum % 2 != 0) {
            return false;
        }
        // dp[j] 表示是否存在和为 j 的子数组
        int target = sum / 2;
        vector<bool> dp(target + 1, false);//  初始化 dp 数组，所有元素设为 false
        dp[0] = true;//  初始化 dp[0] 为 true，表示和为 0 的子数组存在
        for (int num : nums) {//  遍历数组中的每个元素
            //  从目标和开始，遍历到当前元素的和
            for (int j = target; j >= num; j--) {//  遍历所有可能的和
                dp[j] = dp[j] || dp[j - num];//  更新 dp[j]，表示是否存在和为 j 的子数组
            }
        }
        
        return dp[target];//  返回 dp[target]，表示是否存在和为 target 的子数组
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Input: nums = [1,5,11,5]" << endl;
    cout << "Output: " << (sol.canPartition(nums1) ? "true" : "false") << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Input: nums = [1,2,3,5]" << endl;
    cout << "Output: " << (sol.canPartition(nums2) ? "true" : "false") << endl;
    
    return 0;
}