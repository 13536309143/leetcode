#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class UnionFind {//  并查集类
private:
    unordered_map<string, string> parent;//  父节点映射
    unordered_map<string, double> value;//  值映射
    
public:
    string find(string x) {//  查找根节点
        if (parent.find(x) == parent.end()) {//  如果节点不存在，初始化为根节点
            parent[x] = x;//  初始化父节点为自身
            value[x] = 1.0;//  初始化值为1.0
            return x;//  返回根节点
        }
        
        if (parent[x] == x) { //  如果节点是根节点，直接返回根节点
            return x;//  返回根节点
        }
        
        string root = find(parent[x]);//  递归查找根节点
        value[x] = value[x] * value[parent[x]];//  更新当前节点的值
        parent[x] = root;//  更新当前节点的父节点
        
        return root;//  返回根节点
    }
    
    void unionSet(string x, string y, double val) {//  合并两个集合
        string rootX = find(x);//  查找根节点
        string rootY = find(y);//  查找根节点
        
        if (rootX == rootY) {//  如果两个节点的根节点相同，直接返回
            return;//  直接返回
        }
        
        parent[rootX] = rootY;//  合并两个集合
        value[rootX] = val * value[y] / value[x];//  更新根节点的值
    }
    
    bool isConnected(string x, string y) {//  判断两个节点是否连接
        if (parent.find(x) == parent.end() || parent.find(y) == parent.end()) {//  如果节点不存在，返回false
            return false;//  如果节点不存在，返回false
        }
        return find(x) == find(y);//  如果两个节点的根节点相同，返回true
    }
    
    double getResult(string x, string y) {//  获取两个节点的结果
        if (!isConnected(x, y)) {//  如果两个节点不连接，返回-1.0
            return -1.0;//  如果两个节点不连接，返回-1.0
        }
        return value[x] / value[y];//  如果两个节点连接，返回结果
    }
};

class Solution {//  解决方案类
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {//  计算除法结果
        UnionFind uf;//  初始化并查集
        vector<double> result;//  结果向量
        
        for (size_t i = 0; i < equations.size(); i++) {//  遍历所有等式
            uf.unionSet(equations[i][0], equations[i][1], values[i]);//  合并两个集合
        }
        
        for (const auto& query : queries) {//  遍历所有查询
            double res = uf.getResult(query[0], query[1]);//  获取查询结果
            result.push_back(res);//  将结果添加到结果向量
        }
        
        return result;//  返回结果向量
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<vector<string>> equations1 = {{"a","b"},{"b","c"}};
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    cout << "Input: equations = [[a,b],[b,c]], values = [2.0,3.0], queries = [[a,c],[b,a],[a,e],[a,a],[x,x]]" << endl;
    vector<double> result1 = sol.calcEquation(equations1, values1, queries1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<vector<string>> equations2 = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values2 = {1.5, 2.5, 5.0};
    vector<vector<string>> queries2 = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    cout << "Input: equations = [[a,b],[b,c],[bc,cd]], values = [1.5,2.5,5.0], queries = [[a,c],[c,b],[bc,cd],[cd,bc]]" << endl;
    vector<double> result2 = sol.calcEquation(equations2, values2, queries2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 3:" << endl;
    vector<vector<string>> equations3 = {{"a","b"}};
    vector<double> values3 = {0.5};
    vector<vector<string>> queries3 = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
    cout << "Input: equations = [[a,b]], values = [0.5], queries = [[a,b],[b,a],[a,c],[x,y]]" << endl;
    vector<double> result3 = sol.calcEquation(equations3, values3, queries3);
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}