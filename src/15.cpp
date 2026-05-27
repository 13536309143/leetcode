#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 3) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

void printResult(vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = solution.threeSum(nums1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: nums = [-1,0,1,2,-1,-4]" << endl;
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [[-1,-1,2],[-1,0,1]]" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> result2 = solution.threeSum(nums2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: nums = [0,1,1]" << endl;
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: []" << endl;
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> result3 = solution.threeSum(nums3);
    
    cout << "Test case 3:" << endl;
    cout << "Input: nums = [0,0,0]" << endl;
    cout << "Output: ";
    printResult(result3);
    cout << "Expected: [[0,0,0]]" << endl;
    
    return 0;
}