#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {//  前K个高频元素
        unordered_map<int, int> freqMap;//  频率映射
        int maxFreq = 0;//  最大频率
        
        for (int num : nums) {//  遍历所有元素
            freqMap[num]++;//  增加频率
            maxFreq = max(maxFreq, freqMap[num]);//  更新最大频率
        }
        
        vector<vector<int>> buckets(maxFreq + 1);//  桶数组
        for (auto& pair : freqMap) {//  遍历频率映射
            buckets[pair.second].push_back(pair.first);//  将元素添加到对应的桶中
        }
        
        vector<int> result;//  结果数组
        for (int i = maxFreq; i >= 0 && result.size() < k; i--) {//  从大到小遍历桶数组
            for (int num : buckets[i]) {//  遍历当前桶中的元素
                result.push_back(num);//  将元素添加到结果数组
                if (result.size() == k) {//  如果结果数组已满
                    break;//  跳出当前桶
                }
            }
        }
        
        return result;//  返回结果数组
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    cout << "Input: nums = [1,1,1,2,2,3], k = 2" << endl;
    vector<int> result1 = sol.topKFrequent(nums1, k1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {1};
    int k2 = 1;
    cout << "Input: nums = [1], k = 1" << endl;
    vector<int> result2 = sol.topKFrequent(nums2, k2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 3:" << endl;
    vector<int> nums3 = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k3 = 2;
    cout << "Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2" << endl;
    vector<int> result3 = sol.topKFrequent(nums3, k3);
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}