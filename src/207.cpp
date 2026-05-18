#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建邻接表
        vector<vector<int>> adj(numCourses);
        // 入度数组
        vector<int> inDegree(numCourses, 0);
        
        // 初始化邻接表和入度数组
        for (auto& pre : prerequisites) {
            int ai = pre[0];
            int bi = pre[1];
            adj[bi].push_back(ai);  // bi -> ai
            inDegree[ai]++;
        }
        
        // 队列存储入度为0的节点
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // 记录拓扑排序的节点数
        int count = 0;
        
        // 进行拓扑排序
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            // 遍历当前节点的所有邻居
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // 如果拓扑排序的节点数等于课程数，说明没有环
        return count == numCourses;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "numCourses = 2, prerequisites = [[1,0]]" << endl;
    cout << "Output: " << (sol.canFinish(numCourses1, prerequisites1) ? "true" : "false") << endl;
    
    cout << "\nTest Case 2:" << endl;
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "numCourses = 2, prerequisites = [[1,0],[0,1]]" << endl;
    cout << "Output: " << (sol.canFinish(numCourses2, prerequisites2) ? "true" : "false") << endl;
    
    return 0;
}
