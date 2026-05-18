#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        // 计算前缀积
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        
        // 计算后缀积     
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        
        return answer;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Input: [1,2,3,4]" << endl;
    vector<int> result1 = sol.productExceptSelf(nums1);
    cout << "Output: ";
    printVector(result1);
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "Input: [-1,1,0,-3,3]" << endl;
    vector<int> result2 = sol.productExceptSelf(nums2);
    cout << "Output: ";
    printVector(result2);
    
    return 0;
}
