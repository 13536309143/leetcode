#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            int h = min(height[left], height[right]);
            int width = right - left;
            int currentWater = h * width;
            
            maxWater = max(maxWater, currentWater);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result1 = solution.maxArea(height1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: [1,8,6,2,5,4,8,3,7]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 49" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> height2 = {1, 1};
    int result2 = solution.maxArea(height2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: [1,1]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}