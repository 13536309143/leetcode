#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //  初始化结果为 0
        int result = 0;
        //  遍历数组中的每个数字
        for (int num : nums) {
            //  异或操作，出现两次的数字会抵消，出现一次的数字会保留
            result ^= num;
        }
        //  返回出现一次的数字
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {2, 2, 1};
    cout << "Input: nums = [2,2,1]" << endl;
    cout << "Output: " << sol.singleNumber(nums1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Input: nums = [4,1,2,1,2]" << endl;
    cout << "Output: " << sol.singleNumber(nums2) << endl;
    
    cout << "\nTest Case 3:" << endl;
    vector<int> nums3 = {1};
    cout << "Input: nums = [1]" << endl;
    cout << "Output: " << sol.singleNumber(nums3) << endl;
    
    return 0;
}