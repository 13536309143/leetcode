#include <iostream>                 // 引入输入输出流库，用于cout输出
#include <string>                    // 引入字符串库，使用string类型
#include <cctype>                    // 引入字符处理库，使用isdigit()函数判断字符是否为数字
#include <climits>                   // 引入整数限制库，使用INT_MAX、INT_MIN、LONG_MAX等常量
using namespace std;                 // 使用标准命名空间，简化代码中的类型书写

class Solution {                    // 定义Solution类
public:
    // myAtoi函数：将字符串转换为32位有符号整数
    int myAtoi(string s) {
        int n = s.size();           // 获取字符串s的长度
        int i = 0;                  // 初始化索引i，用于遍历字符串
        int sign = 1;               // 初始化符号标志，1表示正数，-1表示负数
        long result = 0;            // 初始化结果变量，使用long类型避免中间过程溢出

        // 步骤1：跳过前导空格
        // 循环条件：i在字符串范围内且当前字符是空格
        while (i < n && s[i] == ' ') {
            i++;                    // 索引后移，跳过空格
        }

        // 步骤2：处理符号位
        // 检查是否有符号字符（+或-）
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            // 三元运算符：如果当前字符是'-'，则sign为-1，否则为1
            sign = (s[i] == '-') ? -1 : 1;
            i++;                    // 索引后移，跳过符号字符
        }

        // 步骤3：转换数字
        // 循环处理连续的数字字符
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0'; // 将字符数字转换为整数值（利用ASCII码的差值）

            // 步骤3.1：检查是否会发生溢出
            // 判断条件：如果当前result大于(LONG_MAX - digit) / 10
            // 这个数学表达式的含义是：如果result * 10 + digit会超过LONG_MAX
            // 那么(LONG_MAX - digit) / 10会小于result，所以会触发这个条件
            if (result > (LONG_MAX - digit) / 10) {
                // 如果符号为正，返回INT_MAX；否则返回INT_MIN（处理溢出截断）
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit; // 将当前数字累加到结果中
            i++;                    // 索引后移，处理下一个字符
        }

        // 步骤4：应用符号
        // 将之前记录的符号应用到结果上（例如处理负号）
        result *= sign;

        // 步骤5：处理32位整数范围
        // 确保结果在32位有符号整数范围内[-2147483648, 2147483647]
        if (result > INT_MAX) {     // 如果结果大于INT_MAX (2147483647)
            return INT_MAX;         // 返回INT_MAX作为截断值
        } else if (result < INT_MIN) { // 如果结果小于INT_MIN (-2147483648)
            return INT_MIN;         // 返回INT_MIN作为截断值
        }

        // 步骤6：返回最终结果
        // 将long类型转换为int类型并返回
        return static_cast<int>(result);
    }
};

// 主函数，用于测试myAtoi函数
int main() {
    Solution sol;                   // 创建Solution类对象sol
    // 测试用例1："42" -> 42
    string test1 = "44";
    cout << "输入: \"" << test1 << "\" 输出: " << sol.myAtoi(test1) << endl;

    // 测试用例2："   -042" -> -42
    // 说明：三个前导空格被忽略，符号为负，数字042转换后为42（前导零自动忽略）
    string test2 = "   -042";
    cout << "输入: \"" << test2 << "\" 输出: " << sol.myAtoi(test2) << endl;

    // 测试用例3："1337c0d3" -> 1337
    // 说明：遇到非数字字符'c'时停止转换，只转换前面的数字部分
    string test3 = "1337c0d3";
    cout << "输入: \"" << test3 << "\" 输出: " << sol.myAtoi(test3) << endl;

    // 测试用例4："0-1" -> 0
    // 说明：第一个字符'0'被转换，遇到'-'停止，所以结果为0
    string test4 = "0-1";
    cout << "输入: \"" << test4 << "\" 输出: " << sol.myAtoi(test4) << endl;

    // 测试用例5："words and 987" -> 0
    // 说明：第一个字符'w'不是数字，直接返回0（没有读取到任何数字）
    string test5 = "words and 987";
    cout << "输入: \"" << test5 << "\" 输出: " << sol.myAtoi(test5) << endl;

    // 测试用例6："2147483647" -> 2147483647
    // 说明：这是INT_MAX的边界值，正常返回
    string test6 = "2147483647";
    cout << "输入: \"" << test6 << "\" 输出: " << sol.myAtoi(test6) << endl;

    // 测试用例7："-2147483648" -> -2147483648
    // 说明：这是INT_MIN的边界值，正常返回
    string test7 = "-2147483648";
    cout << "输入: \"" << test7 << "\" 输出: " << sol.myAtoi(test7) << endl;

    // 测试用例8："2147483648" -> 2147483647
    // 说明：超过INT_MAX，发生溢出，需要截断到INT_MAX
    string test8 = "2147483648";
    cout << "输入: \"" << test8 << "\" 输出: " << sol.myAtoi(test8) << endl;

    return 0;                       // 程序正常结束
}
