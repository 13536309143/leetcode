#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        
        int prefixSum = 0;// 当前前缀和
        int result = 0;// 结果
        
        for (int num : nums) {// 遍历数组
            prefixSum += num;// 当前前缀和加上当前元素的值
            int need = prefixSum - k;// 需要的前缀和
            if (prefixCount.find(need) != prefixCount.end()) {// 如果需要的前缀和在前缀和的个数中，说明存在一个子数组的和为k
                result += prefixCount[need];// 结果加上需要的前缀和的个数
            }
            prefixCount[prefixSum]++;// 当前前缀和的个数加1
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    int result1 = solution.subarraySum(nums1, k1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: nums = [1,1,1], k = 2" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 2" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    int result2 = solution.subarraySum(nums2, k2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: nums = [1,2,3], k = 3" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 2" << endl;
    
    return 0;
}