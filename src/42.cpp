#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    water += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    water += right_max - height[right];
                }
                right--;
            }
        }
        
        return water;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result1 = solution.trap(height1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: [0,1,0,2,1,0,1,3,2,1,2,1]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 6" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    int result2 = solution.trap(height2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: [4,2,0,3,2,5]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 9" << endl;
    
    return 0;
}