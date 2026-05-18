#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {//  动态规划
        int sum = accumulate(nums.begin(), nums.end(), 0);//  计算nums的和
        
        if (sum < abs(target) || (sum + target) % 2 != 0) {//  如果sum小于绝对值的target，或者sum+target不是偶数
            //  说明没有解，返回0
            return 0;
        }
        //  计算targetSum，即sum+target的一半
        //  因为sum+target是偶数，所以targetSum是整数
        //  因为dp数组的索引是整数，所以targetSum+1
        int targetSum = (sum + target) / 2;//  计算targetSum
        vector<int> dp(targetSum + 1, 0);//  初始化dp数组为0
        dp[0] = 1;//  金额为0时，不需要任何硬币
        /*
        按照题意，其实就是准备两个背包，一个背包package_a存放标记为正的元素，另一个背包package_b存放标记为负的元素。package_a - package_b = target。设nums的元素和为sum, 可以列出方程：
        package_a - package_b = target;
        package_a + package_b = sum;
        则 package_a = (target + sum)/2。
        所以根据题意给的target和sum，我们可以求出package_a的值。
        */
        for (int num : nums) {//  遍历所有数字
            for (int j = targetSum; j >= num; j--) {//  遍历targetSum到num
                dp[j] += dp[j - num];//  更新dp[j]为当前金额的方案数
            }
        }
        //  返回dp[targetSum]，即dp[targetSum]表示金额为targetSum时的方案数
        //  说明有dp[targetSum]种方法使nums的和等于target
        return dp[targetSum];
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "Input: nums = [1,1,1,1,1], target = 3" << endl;
    cout << "Output: " << sol.findTargetSumWays(nums1, target1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {1};
    int target2 = 1;
    cout << "Input: nums = [1], target = 1" << endl;
    cout << "Output: " << sol.findTargetSumWays(nums2, target2) << endl;
    
    return 0;
}