#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {//  找重复数
        int slow = 0;//  慢指针
        int fast = 0;//  快指针
        
        do {
            slow = nums[slow];//  慢指针每次移动一步
            fast = nums[nums[fast]];//  快指针每次移动两步
        } 
        while (slow != fast);//  当慢指针和快指针不相等时，继续移动
        //  第二次循环的目的是找到重复数
        slow = 0;//  慢指针重置到起始位置
        while (slow != fast) {//  当慢指针和快指针不相等时，继续移动
            slow = nums[slow];//  慢指针每次移动一步
            fast = nums[fast];//  快指针每次移动一步
        }
        
        return slow;//  返回重复数
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << "Input: nums = [1,3,4,2,2]" << endl;
    cout << "Output: " << sol.findDuplicate(nums1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Input: nums = [3,1,3,4,2]" << endl;
    cout << "Output: " << sol.findDuplicate(nums2) << endl;
    
    cout << "\nTest Case 3:" << endl;
    vector<int> nums3 = {3, 3, 3, 3, 3};
    cout << "Input: nums = [3,3,3,3,3]" << endl;
    cout << "Output: " << sol.findDuplicate(nums3) << endl;
    
    return 0;
}