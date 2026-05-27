#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {// 下一个排列
        int n = nums.size();// 数组长度
        if (n <= 1) return;// 数组长度小于等于1，直接返回
        
        int i = n - 2;// 从倒数第二个元素开始遍历
        while (i >= 0 && nums[i] >= nums[i + 1]) {// 找到第一个非递增元素
            i--;// 向前遍历
        }
        
        if (i >= 0) {// 找到非递增元素
            // 找到第一个大于非递增元素的元素
            // 交换非递增元素和大于大于非递增元素的元素
            int j = n - 1;// 从倒数第一个元素开始遍历
            while (nums[j] <= nums[i]) {// 找到第一个大于非递增元素的元素
                j--;// 向前遍历
            }
            int temp = nums[i];// 交换非递增元素和大于大于非递增元素的元素
            nums[i] = nums[j];// 交换非递增元素和大于大于非递增元素的元素
            nums[j] = temp;// 交换非递增元素和大于大于非递增元素的元素
        }
        
        // 反转非递增元素后的元素
        // 使非递增元素后的元素递增
        // 使非递增元素后的元素最小
        int left = i + 1;
        int right = n - 1;
        // 反转非递增元素之后的元素
        while (left < right) {
            int temp = nums[left];// 交换非递增元素和大于大于非递增元素的元素
            nums[left] = nums[right];// 交换非递增元素和大于大于非递增元素的元素
            nums[right] = temp;// 交换非递增元素和大于大于非递增元素的元素
            left++;// 向中间遍历
            right--;// 向中间遍历
        }
    }
};

void printVector(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 2, 3};
    cout << "Test case 1:" << endl;
    cout << "Input: ";
    printVector(nums1);
    solution.nextPermutation(nums1);
    cout << "Output: ";
    printVector(nums1);
    cout << "Expected: [1, 3, 2]" << endl;
    cout << endl;
    
    vector<int> nums2 = {3, 2, 1};
    cout << "Test case 2:" << endl;
    cout << "Input: ";
    printVector(nums2);
    solution.nextPermutation(nums2);
    cout << "Output: ";
    printVector(nums2);
    cout << "Expected: [1, 2, 3]" << endl;
    cout << endl;
    
    vector<int> nums3 = {1, 1, 5};
    cout << "Test case 3:" << endl;
    cout << "Input: ";
    printVector(nums3);
    solution.nextPermutation(nums3);
    cout << "Output: ";
    printVector(nums3);
    cout << "Expected: [1, 5, 1]" << endl;
    
    return 0;
}