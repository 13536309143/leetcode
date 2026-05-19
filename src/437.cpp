#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

struct TreeNode {//  二叉树节点结构体
    int val;//  节点值
    TreeNode* left;//  左子树指针
    TreeNode* right;//  右子树指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}//  构造函数
};

class Solution {//  解决方案类
public:
    int pathSum(TreeNode* root, int targetSum) {//  路径和等于目标值的路径数量
        unordered_map<long long, int> prefixSumCount;//  前缀和计数映射
        prefixSumCount[0] = 1;//  初始化前缀和为0的计数为1
        return dfs(root, 0, targetSum, prefixSumCount);//  递归计算路径数量
    }
    
private:
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumCount) {//  递归计算路径数量
        if (node == nullptr) {
            return 0;//  当前节点为空，返回0
        }
        
        currentSum += node->val;//  更新当前路径缀和
        int count = prefixSumCount[currentSum - targetSum];//  查找路径和等于目标值的路径数量
        
        prefixSumCount[currentSum]++;//  更新当前路径缀和计数
        
        count += dfs(node->left, currentSum, targetSum, prefixSumCount);//  递归计算左子树路径数量
        count += dfs(node->right, currentSum, targetSum, prefixSumCount);//  递归计算右子树路径数量
        
        prefixSumCount[currentSum]--;//  回溯更新当前路径缀和计数
        
        return count;//  返回路径数量
    }
};

TreeNode* buildTree(const vector<int>& vals) {//  构建二叉树
    if (vals.empty() || vals[0] == INT_MIN) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (vals[i] != INT_MIN) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        
        if (i < vals.size() && vals[i] != INT_MIN) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {10, 5, -3, 3, 2, INT_MIN, 11, 5, -2, INT_MIN, 1};
    TreeNode* root1 = buildTree(vals1);
    cout << "Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8" << endl;
    cout << "Output: " << sol.pathSum(root1, 8) << endl;
    deleteTree(root1);
    
    cout << "\nTest Case 2:" << endl;
    vector<int> vals2 = {5, 4, 8, 11, INT_MIN, 13, 4, 7, 2, INT_MIN, INT_MIN, 5, 1};
    TreeNode* root2 = buildTree(vals2);
    cout << "Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22" << endl;
    cout << "Output: " << sol.pathSum(root2, 22) << endl;
    deleteTree(root2);
    
    return 0;
}