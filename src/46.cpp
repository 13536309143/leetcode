#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) // 回溯法
    {
        vector<vector<int>> result;// 结果数组
        backtrack(result, nums, 0);// 回溯函数
        return result;// 返回结果数组
    }
    
private:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, int start) // 回溯函数
    {
        if (start == nums.size()) {// 如果递归到数组末尾
            // 将当前排列添加到结果数组中
            result.push_back(nums);// 将当前排列添加到结果数组中
            return;// 返回
        }
        
        for (int i = start; i < nums.size(); i++) {// 遍历数组
            // 交换当前元素和数组末尾的元素
            swap(nums[start], nums[i]);
            backtrack(result, nums, start + 1);// 回溯函数
            swap(nums[start], nums[i]);// 恢复交换，准备下一次递归
        }
    }
};

void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}                    [1,2,3]
                    /   |   \
                   /    |    \
            [1,2,3]  [2,1,3]  [3,2,1]
            /   \     /   \     /   \
        [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,2,1] [3,1,2]

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = solution.permute(nums1);
    
    cout << "Test case 1: nums = [1,2,3]" << endl;
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 1};
    vector<vector<int>> result2 = solution.permute(nums2);
    
    cout << "Test case 2: nums = [0,1]" << endl;
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: [[0,1],[1,0]]" << endl;
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {1};
    vector<vector<int>> result3 = solution.permute(nums3);
    
    cout << "Test case 3: nums = [1]" << endl;
    cout << "Output: ";
    printResult(result3);
    cout << "Expected: [[1]]" << endl;
    
    return 0;
}