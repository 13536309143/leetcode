#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> result1 = solution.maxSlidingWindow(nums1, k1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: nums = [1,3,-1,-3,5,3,6,7], k = 3" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Expected: [3, 3, 5, 5, 6, 7]" << endl;
    cout << endl;
    
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = solution.maxSlidingWindow(nums2, k2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: nums = [1], k = 1" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Expected: [1]" << endl;
    
    return 0;
}