#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {0, 1, 2, 3, 0, 5, 0, 7, 8, 3, 10, 3, 12};
    cout << "Input: [0,1,2,3,0,5,0,7,8,3,10,3,12]" << endl;
    sol.moveZeroes(nums1);
    cout << "Output: [";
    for (size_t i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {0};
    cout << "Input: [0]" << endl;
    sol.moveZeroes(nums2);
    cout << "Output: [";
    for (size_t i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}