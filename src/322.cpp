#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {//  动态规划
        //  初始化dp数组，dp[i]表示金额为i时的最小硬币数
        vector<int> dp(amount + 1, INT_MAX);//  初始化dp数组为INT_MAX
        dp[0] = 0;//  金额为0时，不需要任何硬币
        for (int i = 1; i <= amount; i++) {//  遍历金额从1到amount
            for (int coin : coins) {//  遍历所有硬币
                if (coin <= i && dp[i - coin] != INT_MAX) {//  如果当前硬币小于等于当前金额，且dp[i-coin]不是INT_MAX
                    dp[i] = min(dp[i], dp[i - coin] + 1);//  更新dp[i]为当前金额的最小硬币数
                }
            }
        }
        //  返回dp[amount]，如果dp[amount]是INT_MAX，说明没有解，返回-1
        //  如果dp[amount]不是INT_MAX，说明dp[amount]是解，返回dp[amount]
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Input: coins = [1,2,5], amount = 11" << endl;
    cout << "Output: " << sol.coinChange(coins1, amount1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Input: coins = [2], amount = 3" << endl;
    cout << "Output: " << sol.coinChange(coins2, amount2) << endl;
    
    cout << "\nTest Case 3:" << endl;
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Input: coins = [1], amount = 0" << endl;
    cout << "Output: " << sol.coinChange(coins3, amount3) << endl;
    
    return 0;
}