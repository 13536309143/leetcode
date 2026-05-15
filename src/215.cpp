#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         return quickSelect(nums, k);
//     }
    
// private:
//     int quickSelect(vector<int>& nums, int k) {
//         // 随机选择基准数
//         int pivot = nums[rand() % nums.size()];
//         // 将大于、小于、等于 pivot 的元素划分至 big, small, equal 中
//         vector<int> big, equal, small;
//         for (int num : nums) {
//             if (num > pivot)
//                 big.push_back(num);
//             else if (num < pivot)
//                 small.push_back(num);
//             else
//                 equal.push_back(num);
//         }
//         // 第 k 大元素在 big 中，递归划分
//         if (k <= big.size())
//             return quickSelect(big, k);
//         // 第 k 大元素在 small 中，递归划分
//         if (nums.size() - small.size() < k)
//             return quickSelect(small, k - nums.size() + small.size());
//         // 第 k 大元素在 equal 中，直接返回 pivot
//         return pivot;
//     }
// };
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
//使用编程语言的内置排序算法对数组 nums 进行排序，然后返回第 N?k 个元素即可。
int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {3, 2, 1, 5, 6, 5};
    int k1 = 2;
    cout << "Input: [3,2,1,5,6,4], k = 2" << endl;
    cout << "Output: " << sol.findKthLargest(nums1, k1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {3, 2, 3, 166, 66, 45, 5, 5, 6};
    int k2 = 4;
    cout << "Input: [3,2,3,1,2,4,5,5,6], k = 4" << endl;
    cout << "Output: " << sol.findKthLargest(nums2, k2) << endl;
    
    return 0;
}
