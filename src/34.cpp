#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        return {left, right};
    }
    
private:
    // 二分查找左边界
    int findLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    int findRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};

void printResult(const vector<int>& result) {
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = solution.searchRange(nums1, target1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: nums = [5,7,7,8,8,10], target = 8" << endl;
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [3, 4]" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = solution.searchRange(nums2, target2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: nums = [5,7,7,8,8,10], target = 6" << endl;
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: [-1, -1]" << endl;
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = solution.searchRange(nums3, target3);
    
    cout << "Test case 3:" << endl;
    cout << "Input: nums = [], target = 0" << endl;
    cout << "Output: ";
    printResult(result3);
    cout << "Expected: [-1, -1]" << endl;
    
    return 0;
}