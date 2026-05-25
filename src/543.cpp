#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {// 主函数，用于计算二叉树的直径
        int diameter = 0;// 初始化直径为0
        dfs(root, diameter);// 调用dfs归函数，计算直径
        return diameter;// 返回直径
    }
    
private:
    int dfs(TreeNode* node, int& diameter) {// 递归函数，用于计算二叉树的直径
        if (node == nullptr) {// 如果当前节点为空
            return 0;// 如果当前节点为空，返回0
        }
        
        int left_depth = dfs(node->left, diameter);// 递归调用dfs函数，计算左子树的深度
        int right_depth = dfs(node->right, diameter);// 递归调用dfs函数，计算右子树的深度
        
        diameter = max(diameter, left_depth + right_depth);// 更新直径
        
        return max(left_depth, right_depth) + 1;// 返回当前节点的深度
    }
};

TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nodes1 = {1, 2, 3, 4, 5};
    TreeNode* root1 = buildTree(nodes1);
    int result1 = solution.diameterOfBinaryTree(root1);
    
    cout << "Test case 1:" << endl;
    cout << "Input: root = [1,2,3,4,5]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 3" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nodes2 = {1, 2};
    TreeNode* root2 = buildTree(nodes2);
    int result2 = solution.diameterOfBinaryTree(root2);
    
    cout << "Test case 2:" << endl;
    cout << "Input: root = [1,2]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}