#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rob(TreeNode* root) //  动态规划
    //  时间复杂度：O(n)
    //  空间复杂度：O(n)
    {
        vector<int> result = dfs(root);//  递归遍历二叉树，返回当前节点的二元组
        return max(result[0], result[1]);//  返回当前节点的二元组中较大的那个
    }
    vector<int> dfs(TreeNode* node) //  动态规划
    //  时间复杂度：O(n)
    //  空间复杂度：O(n)
    {
        if (node == nullptr) {//  如果当前节点为空，返回0
            return {0, 0};//  递归边界，返回0
        }
        
        vector<int> left = dfs(node->left);//  递归遍历左子树，返回左子树的二元组
        vector<int> right = dfs(node->right);//  递归遍历右子树，返回右子树的二元组
        
        int robCurrent = node->val + left[1] + right[1];//  如果当前节点被偷，左子树和右子树都不能被偷
        int notRobCurrent = max(left[0], left[1]) + max(right[0], right[1]);//  如果当前节点不被偷，左子树和右子树都可以被偷
        
        return {robCurrent, notRobCurrent};//  返回当前节点的二元组
    }
};

TreeNode* buildTree(const vector<int>& vals) {
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
    vector<int> vals1 = {3, 2, 3, INT_MIN, 3, INT_MIN, 1};
    TreeNode* root1 = buildTree(vals1);
    cout << "Input: root = [3,2,3,null,3,null,1]" << endl;
    cout << "Output: " << sol.rob(root1) << endl;
    deleteTree(root1);
    
    cout << "\nTest Case 2:" << endl;
    vector<int> vals2 = {3, 4, 5, 1, 3, INT_MIN, 1};
    TreeNode* root2 = buildTree(vals2);
    cout << "Input: root = [3,4,5,1,3,null,1]" << endl;
    cout << "Output: " << sol.rob(root2) << endl;
    deleteTree(root2);
    
    return 0;
}