#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        
        for (int i = 1; i < n; i++) {
            int tempMax = currMax;
            
            currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], tempMax * nums[i], currMin * nums[i]});
            
            maxProd = max(maxProd, currMax);
        }
        
        return maxProd;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {2, 3, -2, 4, 2};
    cout << "Input: [2,3,-2,4,2]" << endl;
    cout << "Output: " << sol.maxProduct(nums1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {-2, 0, -1};
    cout << "Input: [-2,0,-1]" << endl;
    cout << "Output: " << sol.maxProduct(nums2) << endl;
    
    return 0;
}