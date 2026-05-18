#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {//  最长连续序列
        if (nums.empty()) {
            return 0;//  特殊情况处理，空数组返回 0
        }
        
        unordered_set<int> numSet(nums.begin(), nums.end());//  去重
        int longest = 0;     //  最长连续序列长度
        
        for (auto it = numSet.begin(); it != numSet.end(); ) {//  遍历去重后的集合
            int num = *it;//  当前数字
            
            if (numSet.count(num - 1)) {//  如果当前数字的前一个数字在集合中
                ++it;//  跳过当前数字，继续遍历
                continue;//  跳过当前循环，继续下一次循环
            }
            
            int currentNum = num;//  当前数字
            int currentLength = 1;//  当前连续序列长度
            
            while (numSet.count(currentNum + 1)) {
                currentNum++;//  当前数字增加 1
                currentLength++;//  当前连续序列长度增加 1
                numSet.erase(currentNum);//  从集合中删除当前数字
            }
            
            it = numSet.erase(it);//  从集合中删除当前数字
            
            longest = max(longest, currentLength);//  更新最长连续序列长度
            
            if (longest > numSet.size() + currentLength) {
                break;//  如果当前最长序列长度大于集合大小加上当前序列长度，提前终止循环
            }
        }
        
        return longest;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Input: nums = [100,4,200,1,3,2]" << endl;
    cout << "Output: " << sol.longestConsecutive(nums1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Input: nums = [0,3,7,2,5,8,4,6,0,1]" << endl;
    cout << "Output: " << sol.longestConsecutive(nums2) << endl;
    
    cout << "\nTest Case 3:" << endl;
    vector<int> nums3 = {1, 0, 1, 2};
    cout << "Input: nums = [1,0,1,2]" << endl;
    cout << "Output: " << sol.longestConsecutive(nums3) << endl;
    
    return 0;
}