#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) //  动态规划
    //  时间复杂度：O(n)
    //  空间复杂度：O(n)
    {
        vector<int> dp(n + 1, 0);//  初始化一个dp数组，用于存储每个整数的二进制表示中1的个数
        
        for (int i = 1; i <= n; i++) {//  遍历所有整数
            dp[i] = dp[i >> 1] //  右移一位，相当于除以2，将最低位的1去掉
                + (i & 1);//  计算当前整数的二进制表示中1的个数
        }
        
        return dp;//  返回dp数组
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    int n1 = 2;
    cout << "Input: n = 2" << endl;
    vector<int> result1 = sol.countBits(n1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 2:" << endl;
    int n2 = 5;
    cout << "Input: n = 5" << endl;
    vector<int> result2 = sol.countBits(n2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}