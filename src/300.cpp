#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)//  最长递增子序列
    {
        vector<int> tails;//  初始化tails向量，用于存储最长递增子序列的尾元素
        
        for (int num : nums) {//  遍历nums向量中的所有元素
            auto it = lower_bound(tails.begin(), tails.end(), num);//  查找tails向量中第一个大于等于num的元素的迭代器
            
            if (it == tails.end()) {//  如果it等于tails.end()，说明num大于所有元素
                tails.push_back(num);//  将num添加到tails向量的末尾
            } else {//  如果it不等于tails.end()，说明num小于等于tails向量中的元素
                *it = num;//  将num赋值给it指向的元素
            }
        }
        
        return tails.size();
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Input: nums = [10,9,2,5,3,7,101,18]" << endl;
    cout << "Output: " << sol.lengthOfLIS(nums1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Input: nums = [0,1,0,3,2,3]" << endl;
    cout << "Output: " << sol.lengthOfLIS(nums2) << endl;
    
    cout << "\nTest Case 3:" << endl;
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Input: nums = [7,7,7,7,7,7,7]" << endl;
    cout << "Output: " << sol.lengthOfLIS(nums3) << endl;
    
    return 0;
}