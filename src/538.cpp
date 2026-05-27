#include <iostream>
#include <vector>
#include <queue>

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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
    
private:
    void dfs(TreeNode* node, int& sum) {// 递归函数
        if (node == nullptr) {// 如果当前节点为空
            return;
        }
        
        dfs(node->right, sum);// 先遍历右子树
        int temp = node->val;// 保存当前节点的值
        node->val += sum;// 将当前节点的值加上sum
        sum += temp;// 将sum加上当前节点的值加上当前节点的值
        dfs(node->left, sum);// 遍历左子树
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

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "[]" << endl;
        return;
    }
    
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node == nullptr) {
            result.push_back(-1);
            continue;
        }
        
        result.push_back(node->val);
        q.push(node->left);
        q.push(node->right);
    }
    
    while (!result.empty() && result.back() == -1) {
        result.pop_back();
    }
    
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == -1) {
            cout << "null";
        } else {
            cout << result[i];
        }
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nodes1 = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
    TreeNode* root1 = buildTree(nodes1);
    cout << "Test case 1:" << endl;
    cout << "Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]" << endl;
    solution.convertBST(root1);
    cout << "Output: ";
    printTree(root1);
    cout << "Expected: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]" << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nodes2 = {0, -1, 1};
    TreeNode* root2 = buildTree(nodes2);
    cout << "Test case 2:" << endl;
    cout << "Input: [0,null,1]" << endl;
    solution.convertBST(root2);
    cout << "Output: ";
    printTree(root2);
    cout << "Expected: [1,null,1]" << endl;
    cout << endl;
    
    // Test case 3
    vector<int> nodes3 = {1, 0, 2};
    TreeNode* root3 = buildTree(nodes3);
    cout << "Test case 3:" << endl;
    cout << "Input: [1,0,2]" << endl;
    solution.convertBST(root3);
    cout << "Output: ";
    printTree(root3);
    cout << "Expected: [3,3,2]" << endl;
    
    return 0;
}