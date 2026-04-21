#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rank.resize(n);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        for (auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }
        
        unordered_map<int, unordered_map<int, int>> sourceGroups;
        unordered_map<int, unordered_map<int, int>> targetGroups;
        
        for (int i = 0; i < n; i++) {
            int root = find(i);
            sourceGroups[root][source[i]]++;
            targetGroups[root][target[i]]++;
        }
        
        int matches = 0;
        for (auto& [root, sourceCount] : sourceGroups) {
            for (auto& [val, count] : sourceCount) {
                matches += min(count, targetGroups[root][val]);
            }
        }
        
        return n - matches;
    }
    
private:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> source = {1, 2, 3, 4};
    vector<int> target = {2, 1, 4, 5};
    vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};
    
    int result = sol.minimumHammingDistance(source, target, allowedSwaps);
    cout << "示例1结果: " << result << endl;
    
    source = {1, 2, 3, 4};
    target = {1, 3, 2, 4};
    allowedSwaps = {};
    result = sol.minimumHammingDistance(source, target, allowedSwaps);
    cout << "示例2结果: " << result << endl;
    
    source = {5, 1, 2, 4, 3};
    target = {1, 5, 4, 2, 3};
    allowedSwaps = {{0, 4}, {4, 2}, {1, 3}, {1, 4}};
    result = sol.minimumHammingDistance(source, target, allowedSwaps);
    cout << "示例3结果: " << result << endl;
    
    return 0;
}
