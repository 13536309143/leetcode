#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) // 回溯法
    {
        vector<vector<int>> result;// 结果数组
        vector<int> path;// 路径数组
        backtrack(result, path, candidates, target, 0);// 回溯函数
        return result;// 返回结果数组
    }
    
private:
    void backtrack(vector<vector<int>>& result, vector<int>& path,const vector<int>& candidates, int target, int start) {// 回溯函数
        if (target == 0) {// 如果目标值为0
            // 将当前路径添加到结果数组中
            result.push_back(path);// 将当前路径添加到结果数组中
            return;// 返回
        }
        // 遍历数组，从start开始
        for (int i = start; i < candidates.size(); i++) {// 遍历数组
            if (candidates[i] > target) {
                continue;// 如果当前元素大于目标值，跳过
            }
            path.push_back(candidates[i]);// 将当前元素添加到路径数组中
            backtrack(result, path, candidates, target - candidates[i], i);// 递归调用回溯函数
            path.pop_back();// 恢复状态，将当前元素从路径数组中移除
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
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = solution.combinationSum(candidates1, target1);
    
    cout << "Test case 1:" << endl;
    cout << "candidates = [2,3,6,7], target = 7" << endl;
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [[2,2,3],[7]]" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    vector<vector<int>> result2 = solution.combinationSum(candidates2, target2);
    
    cout << "Test case 2:" << endl;
    cout << "candidates = [2,3,5], target = 8" << endl;
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: [[2,2,2,2],[2,3,3],[3,5]]" << endl;
    cout << endl;
    
    // Test case 3
    vector<int> candidates3 = {2};
    int target3 = 1;
    vector<vector<int>> result3 = solution.combinationSum(candidates3, target3);
    
    cout << "Test case 3:" << endl;
    cout << "candidates = [2], target = 1" << endl;
    cout << "Output: ";
    printResult(result3);
    cout << "Expected: []" << endl;
    
    return 0;
}