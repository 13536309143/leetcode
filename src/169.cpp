#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {3,2,3,2,1,3,4,55,6,76,7,7,7,7,7,32,2,2,2,2,2};
    cout << "Input: [3,2,3,2,1,3,4,55,6,76,7,7,7,7,7,32,2,2,2,2,2]" << endl;
    cout << "Output: " << sol.majorityElement(nums1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Input: [2,2,1,1,1,2,2]" << endl;
    cout << "Output: " << sol.majorityElement(nums2) << endl;
    
    return 0;
}
