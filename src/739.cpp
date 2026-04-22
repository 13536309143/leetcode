#include <iostream>                 // 引入输入输出流库，用于cout输出
#include <vector>                  // 引入向量库，用于存储温度数组和结果
#include <stack>                   // 引入栈库，实现单调栈算法
using namespace std;               // 使用标准命名空间，简化代码

// Solution类：包含计算每日温度的算法
class Solution {
public:
    // 方法1：单调递减栈（推荐，最优解）
    // 时间复杂度：O(n)，空间复杂度：O(n)
    // 核心思想：维护一个存储索引的栈，栈中温度单调递减
    // 当遇到更高温度时，计算距离并弹出栈中元素
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();           // 获取温度数组的长度
        vector<int> answer(n, 0);             // 初始化结果数组，全部为0
                                              // 0表示没有找到更高温度
        stack<int> st;                       // 单调递减栈，存储索引
                                              // 栈中存储的是温度数组的索引
                                              // 栈顶元素对应的温度是栈中最小的
        
        // 遍历温度数组
        for (int i = 0; i < n; i++) {
            // 当栈不为空且当前温度高于栈顶温度时
            // 这表示栈顶索引对应的温度找到了更高温度
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                // 取出栈顶索引
                int prevIndex = st.top();
                st.pop();                     // 弹出栈顶元素
                
                // 计算天数差：当前索引减去栈顶索引
                // 即从prevIndex天到i天之间相差多少天
                answer[prevIndex] = i - prevIndex;
            }
            
            // 将当前索引压入栈中
            // 此时栈中所有索引对应的温度都大于等于当前温度
            st.push(i);
        }
        
        // 栈中剩余的索引对应的温度没有更高温度
        // answer数组中这些位置已经是0，无需额外处理
        
        return answer;                        // 返回结果数组
    }
    
    // 方法2：暴力法（仅用于对比，时间复杂度较高）
    // 时间复杂度：O(n?)，空间复杂度：O(n)
    // 核心思想：对每个温度，向后线性查找第一个更高温度
    vector<int> dailyTemperatures_BruteForce(vector<int>& temperatures) {
        int n = temperatures.size();           // 获取温度数组的长度
        vector<int> answer(n, 0);             // 初始化结果数组，全部为0
        
        // 外层循环：遍历每一天
        for (int i = 0; i < n; i++) {
            // 内层循环：从第i+1天开始向后查找
            for (int j = i + 1; j < n; j++) {
                // 如果找到更高温度
                if (temperatures[j] > temperatures[i]) {
                    // 计算天数差
                    answer[i] = j - i;
                    break;                    // 找到后跳出内层循环
                }
            }
            // 如果内层循环结束都没找到，answer[i]保持为0
        }
        
        return answer;                        // 返回结果数组
    }
};

// 主函数：测试代码
int main() {
    Solution sol;                            // 创建Solution类对象sol
    
    // 测试用例1：[73,74,75,71,69,72,76,73]
    // 预期结果：[1,1,4,2,1,1,0,0]
    cout << "Test Case 1:" << endl;
    vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    cout << "Input: [73,74,75,71,69,72,76,73]" << endl;
    vector<int> result1 = sol.dailyTemperatures(temps1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    
    // 测试用例2：[30,40,50,60]
    // 预期结果：[1,1,1,0]
    cout << "\nTest Case 2:" << endl;
    vector<int> temps2 = {30, 40, 50, 60};
    cout << "Input: [30,40,50,60]" << endl;
    vector<int> result2 = sol.dailyTemperatures(temps2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    
    // 测试用例3：[30,60,90]
    // 预期结果：[1,1,0]
    cout << "\nTest Case 3:" << endl;
    vector<int> temps3 = {30, 60, 90};
    cout << "Input: [30,60,90]" << endl;
    vector<int> result3 = sol.dailyTemperatures(temps3);
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    
    // 测试用例4：全部递减的温度 [8,7,6,5,4,3,2,1]
    // 预期结果：[0,0,0,0,0,0,0,0]（都没有更高温度）
    cout << "\nTest Case 4 (all decreasing):" << endl;
    vector<int> temps4 = {8, 7, 6, 5, 4, 3, 2, 1};
    cout << "Input: [8,7,6,5,4,3,2,1]" << endl;
    vector<int> result4 = sol.dailyTemperatures(temps4);
    cout << "Output: [";
    for (size_t i = 0; i < result4.size(); i++) {
        cout << result4[i];
        if (i < result4.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    
    return 0;                               // 程序正常结束
}
