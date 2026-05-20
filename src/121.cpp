#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {//  计算最大利润
        int minPrice = INT_MAX;//  最低价格
        int maxProfit = 0;//  最大利润
        
        for (int price : prices) {//  遍历价格数组
            minPrice = min(minPrice, price);//  更新最低价格
            maxProfit = max(maxProfit, price - minPrice);//  更新最大利润
        }
        
        return maxProfit;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Input: [7,1,5,3,6,4]" << endl;
    cout << "Output: " << sol.maxProfit(prices1) << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Input: [7,6,4,3,1]" << endl;
    cout << "Output: " << sol.maxProfit(prices2) << endl;
    
    return 0;
}