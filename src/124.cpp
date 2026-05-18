#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    //  节点值
    int val;
    //  左子树指针
    //  右子树指针
    TreeNode* left;//  左子树指针
    //  右子树指针
    TreeNode* right;//  右子树指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}//  构造函数，初始化节点值和左右子树指针
};

class Solution {//  解决方案类
public:
    int maxPathSum(TreeNode* root) {//  输入：二叉树根指针
        //  输出：最大路径和
        int maxSum = INT_MIN;//  最大路径和，初始化为最小整数
        //  递归计算最大路径和
        dfs(root, maxSum);//  递归计算最大路径和，从根节点开始
        return maxSum;//  返回最大路径和
    }
    
private:
    int dfs(TreeNode* node, int& maxSum) {//  输入：当前节点指针，最大路径和引用
        if (node == nullptr) {//  特殊情况处理，空节点返回 0
            return 0;
        }
        //  递归计算左子树和右子树的最大路径和
        int leftGain = max(dfs(node->left, maxSum), 0);//  左子树的最大路径和，取 0 或左子树的最大路径和
        //  递归计算右子树和右子树的最大路径和
        int rightGain = max(dfs(node->right, maxSum), 0);//  右子树的最大路径和，取 0 或右子树的最大路径和
        
        //  计算当前节点的最大路径和
        //  当前节点的最大路径和 = 当前节点值 + 左子树的最大路径和 + 右子树的最大路径和
        int currentPathSum = node->val + leftGain + rightGain;
        if (currentPathSum > maxSum) {
            maxSum = currentPathSum;//  更新最大路径和
        }
        //  返回当前节点的最大路径和
        //  当前节点的最大路径和 = 当前节点值 + 左子树的最大路径和 + 右子树的最大路径和
        //  取 0 或当前节点路径和
        return node->val + max(leftGain, rightGain);
    }
};
//  构建二叉树
//  输入：节点值向量
//  输出：二叉树根指针
TreeNode* buildTree(const vector<int>& vals) {//  输入：节点值向量
    //  输出：二叉树根指针
    if (vals.empty() || vals[0] == INT_MIN) {//  特殊情况处理，空向量或根节点值为 INT_MIN
        return nullptr;///  返回空指针
    }
    //  创建根节点
    //  根节点值 = 第一个元素
    TreeNode* root = new TreeNode(vals[0]);
    //  创建队列，用于层序遍历
    //  队列中存储节点指针
    queue<TreeNode*> q;//  队列，用于层序遍历
    //  将根节点入队
    q.push(root);
    
    //  遍历节点值向量，从第二个元素开始
    //  遍历到队列为空或遍历到节点值向量末尾
    //  每次遍历，从队列中出队一个节点，将其左右子树创建并入队
    int i = 1;//  节点值向量索引，从第二个元素开始
    //  遍历到队列为空或遍历到节点值向量末尾
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front();//  出队一个节点
        q.pop();//  出队一个节点
        //  创建左子树
        //  左子树值 = 当前节点值的左子树值
        //  左子树指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        //  左子树节点指针 = 左子树节点指针
        if (vals[i] != INT_MIN) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);//  将左子树节点入队
        }
        i++;
        
        if (i < vals.size() && vals[i] != INT_MIN) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);//  将右子树节点入队
        }
        i++;
    }
    //  返回根节点
    return root;
}
//  删除二叉树
//  输入：二叉树根指针
//  输出：无
//  功能：递归删除二叉树的所有节点
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
//  主函数
//  输入：无
//  输出：无
//  功能：测试最大路径和函数
int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {1, 2, 3};
    TreeNode* root1 = buildTree(vals1);
    cout << "Input: root = [1,2,3]" << endl;
    cout << "Output: " << sol.maxPathSum(root1) << endl;
    deleteTree(root1);
    
    cout << "\nTest Case 2:" << endl;
    vector<int> vals2 = {-10, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode* root2 = buildTree(vals2);
    cout << "Input: root = [-10,9,20,null,null,15,7]" << endl;
    cout << "Output: " << sol.maxPathSum(root2) << endl;
    deleteTree(root2);
    
    return 0;
}