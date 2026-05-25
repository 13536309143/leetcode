#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    int result1 = solution.search(nums1, target1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: nums = [4,5,6,7,0,1,2], target = 0" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 4" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    int result2 = solution.search(nums2, target2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: nums = [4,5,6,7,0,1,2], target = 3" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: -1" << endl;
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {1};
    int target3 = 0;
    int result3 = solution.search(nums3, target3);
    
    cout << "Test case 3:" << endl;
    cout << "Input: nums = [1], target = 0" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: -1" << endl;
    
    return 0;
}