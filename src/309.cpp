#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)//     动态规划
     {
        int n = prices.size();//  获取股票数组的长度
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(3, 0));//  初始化dp数组，dp[i][0]表示第i天持有股票的最大利润，dp[i][1]表示第i天不持有股票且未冷冻期的最大利润，dp[i][2]表示第i天不持有股票且在冷冻期的最大利润
        dp[0][0] = -prices[0];//  第一天持有股票，利润为负数
        dp[0][1] = 0;//  第一天不持有股票且未冷冻期，利润为0
        dp[0][2] = 0;//  第一天不持有股票且在冷冻期，利润为0
        
        for (int i = 1; i < n; i++) {//  遍历股票股票数组
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);//  第i天持有股票，利润为第i天的股票价格减去第i天的股票价格
            dp[i][1] = dp[i-1][0] + prices[i];//  第i天不持有股票，利润为第i天的股票价格加上 dp[i-1][0] + prices[i];                                                                                                                                                                                                        
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);//  第i天不持有股票且在冷冻期，利润为第i天的利润加上 dp[i-1][1] + prices[i];
        }
        
        return max(dp[n-1][1], dp[n-1][2]);//  返回第n天不持有股票且未冷冻期的最大利润和第n天不持有股票且在冷冻期的最大利润中的较大值
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << "Input: prices = [1,2,3,0,2]" << endl;
    cout << "Output: " << sol.maxProfit(prices1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> prices2 = {1};
    cout << "Input: prices = [1]" << endl;
    cout << "Output: " << sol.maxProfit(prices2) << endl;
    
    cout << "\nTest Case 3:" << endl;
    vector<int> prices3 = {1,7,5,8,3,2,4,6,8,6,5,2,7};
    cout << "Input: prices = [1,7,5,8,3,2,4,6,8,6,5,2,7]" << endl;
    cout << "Output: " << sol.maxProfit(prices3) << endl;
    
    return 0;
}