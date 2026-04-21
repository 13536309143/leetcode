#include <iostream>                 // 引入输入输出流库，用于cout输出
#include <unordered_map>             // 引入哈希映射库，用于存储节点的父节点指针
#include <unordered_set>             // 引入哈希集合库，用于存储已访问的节点
#include <queue>                    // 引入队列库，用于层序遍历创建二叉树
#include <climits>                   // 引入整数限制库，使用INT_MIN表示null节点
using namespace std;                 // 使用标准命名空间，简化代码

// 定义二叉树节点结构体
struct TreeNode {
    int val;                        // 节点的值
    TreeNode* left;                  // 指向左子节点的指针
    TreeNode* right;                 // 指向右子节点的指针
    
    // 构造函数：初始化节点的值和左右子节点指针
    // x: 节点的值
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution类：包含找到两个节点最近公共祖先的方法
class Solution {
public:
    // 方法1：递归法（推荐，最优解）
    // 时间复杂度：O(n)，空间复杂度：O(n)（递归栈的深度，最坏情况下为n）
    // 核心思想：使用后序遍历，从底向上查找
    // 后序遍历的顺序是：左子树 -> 右子树 -> 根节点，这样可以在回溯过程中找到LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 基准情况（Base Case）
        // 如果当前节点为空，返回nullptr
        if (root == nullptr) {
            return nullptr;
        }
        
        // 如果当前节点是p或q，返回当前节点
        // 这表示在当前子树中找到了目标节点之一
        if (root == p || root == q) {
            return root;
        }
        
        // 递归查找左右子树
        // 在左子树中查找p或q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // 在右子树中查找p或q
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // 判断情况：
        // 情况1：如果左右子树都不为空，说明p和q分别在左右子树中
        // 这意味着当前节点就是最近公共祖先（LCA）
        // 因为后序遍历保证了此时左右子树都已经处理完毕
        if (left != nullptr && right != nullptr) {
            return root;
        }
        
        // 情况2：如果只有左子树不为空，说明p和q都在左子树中
        // 返回左子树的结果（可能是p、q或者它们的LCA）
        if (left != nullptr) {
            return left;
        }
        
        // 情况3：如果只有右子树不为空，说明p和q都在右子树中
        // 返回右子树的结果（可能是p、q或者它们的LCA）
        if (right != nullptr) {
            return right;
        }
        
        // 情况4：如果左右子树都为空，说明p和q都不在这棵子树中
        // 返回nullptr
        return nullptr;
    }
    
    // 方法2：使用父指针 + 集合（空间换时间）
    // 时间复杂度：O(n)，空间复杂度：O(n)
    // 核心思想：先记录每个节点的父节点，然后从p向上遍历标记所有祖先，再从q向上查找第一个被标记的节点
    TreeNode* lowestCommonAncestor_WithParent(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 边界情况检查
        if (root == nullptr) {
            return nullptr;
        }
        
        // 第一步：使用DFS记录每个节点的父节点
        // unordered_map的键是子节点，值是父节点指针
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;  // 根节点的父节点为nullptr
        
        // 调用递归函数记录所有节点的父节点
        dfsRecordParent(root, parent);
        
        // 第二步：从p节点开始向上遍历，将访问过的节点加入集合
        // 这个集合存储了p及其所有祖先节点
        unordered_set<TreeNode*> ancestors;
        TreeNode* curr = p;
        while (curr != nullptr) {
            ancestors.insert(curr);      // 将当前节点加入集合
            curr = parent[curr];         // 移动到父节点
        }
        
        // 第三步：从q节点开始向上遍历，找到第一个在集合中的祖先
        // 这个节点就是p和q的最近公共祖先
        curr = q;
        while (curr != nullptr) {
            // 检查当前节点是否在p的祖先集合中
            if (ancestors.find(curr) != ancestors.end()) {
                return curr;  // 找到最近公共祖先
            }
            curr = parent[curr];  // 移动到父节点
        }
        
        // 理论上不会执行到这里，因为p和q都在树中
        return nullptr;
    }
    
private:
    // 辅助函数：深度优先搜索记录每个节点的父节点
    // node: 当前节点
    // parent: 存储节点父节点关系的哈希映射（引用传递以避免复制）
    void dfsRecordParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
        // 如果当前节点为空，直接返回
        if (node == nullptr) {
            return;
        }
        
        // 处理左子节点
        // 如果左子节点存在，记录其父节点为当前节点
        if (node->left != nullptr) {
            parent[node->left] = node;
            // 递归处理左子树
            dfsRecordParent(node->left, parent);
        }
        
        // 处理右子节点
        // 如果右子节点存在，记录其父节点为当前节点
        if (node->right != nullptr) {
            parent[node->right] = node;
            // 递归处理右子树
            dfsRecordParent(node->right, parent);
        }
    }
};

// 辅助函数：从向量创建二叉树（层序遍历的方式）
// vals: 包含树节点值的向量，INT_MIN表示null节点
// 返回值：创建的二叉树的根节点指针
TreeNode* createTree(vector<int> vals) {
    // 处理空向量的情况
    if (vals.empty()) {
        return nullptr;
    }
    
    // 创建根节点（向量第一个元素）
    TreeNode* root = new TreeNode(vals[0]);
    
    // 使用队列进行层序遍历，建立节点关系
    // 队列存储需要处理子节点的父节点
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);  // 将根节点加入队列
    
    int i = 1;  // 从向量第二个元素开始（索引1）
    
    // 循环处理队列中的节点，建立父子关系
    while (i < vals.size()) {
        // 取出队列首部的节点作为当前父节点
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();
        
        // 处理左子节点
        if (i < vals.size()) {
            // 如果不是INT_MIN，说明有左子节点
            if (vals[i] != INT_MIN) {
                // 创建左子节点
                current->left = new TreeNode(vals[i]);
                // 将左子节点加入队列，以便后续处理它的子节点
                nodeQueue.push(current->left);
            }
            i++;  // 处理完一个元素，索引加1
        }
        
        // 处理右子节点
        if (i < vals.size()) {
            // 如果不是INT_MIN，说明有右子节点
            if (vals[i] != INT_MIN) {
                // 创建右子节点
                current->right = new TreeNode(vals[i]);
                // 将右子节点加入队列
                nodeQueue.push(current->right);
            }
            i++;  // 处理完一个元素，索引加1
        }
    }
    
    return root;  // 返回创建的树的根节点
}

// 辅助函数：在二叉树中查找值为val的节点
// root: 二叉树的根节点
// val: 要查找的值
// 返回值：找到的节点指针，如果没找到返回nullptr
TreeNode* findNode(TreeNode* root, int val) {
    // 如果树为空，返回nullptr
    if (root == nullptr) {
        return nullptr;
    }
    
    // 如果当前节点的值匹配，返回当前节点
    if (root->val == val) {
        return root;
    }
    
    // 递归在左子树中查找
    TreeNode* leftResult = findNode(root->left, val);
    // 如果在左子树中找到了，返回结果
    if (leftResult != nullptr) {
        return leftResult;
    }
    
    // 如果左子树没找到，在右子树中查找
    return findNode(root->right, val);
}

// 辅助函数：打印树的结构（先序遍历）
// root: 要打印的树的根节点
// level: 当前节点的层级（用于缩进显示）
void printTree(TreeNode* root, int level = 0) {
    // 如果当前节点不为空，打印它
    if (root != nullptr) {
        // 根据层级添加缩进（每个层级两个空格）
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }
        // 打印节点，格式为 "L:值"
        cout << "L:" << root->val << endl;
        
        // 如果有左子节点或右子节点，递归打印它们
        if (root->left != nullptr || root->right != nullptr) {
            // 递归打印左子树，层级加1
            if (root->left != nullptr) {
                printTree(root->left, level + 1);
            }
            // 递归打印右子树，层级加1
            if (root->right != nullptr) {
                printTree(root->right, level + 1);
            }
        }
    }
}

// 辅助函数：释放二叉树占用的内存（后序遍历删除）
// root: 要删除的树的根节点
void deleteTree(TreeNode* root) {
    // 如果树为空，直接返回
    if (root == nullptr) {
        return;
    }
    
    // 后序遍历：先删除左子树
    deleteTree(root->left);
    // 再删除右子树
    deleteTree(root->right);
    // 最后删除当前节点
    delete root;
}

// 主函数：测试代码
int main() {
    Solution sol;  // 创建Solution类对象sol
    
    // 测试用例1：查找节点5和节点1的LCA
    // 树结构：
    //       3
    //      / \
    //     5   1
    //    / \ / \
    //   6  2 0  8
    //     / \
    //    7   4
    cout << "Test Case 1:" << endl;
    
    // 使用层序遍历的方式创建树
    // INT_MIN表示null节点
    vector<int> vals1 = {3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4};
    TreeNode* root1 = createTree(vals1);
    
    // 查找值为5和1的节点
    TreeNode* p1 = findNode(root1, 5);
    TreeNode* q1 = findNode(root1, 1);
    
    // 打印树的结构
    cout << "Tree structure:" << endl;
    printTree(root1);
    
    // 使用递归法查找LCA
    TreeNode* result1 = sol.lowestCommonAncestor(root1, p1, q1);
    if (result1) {
        cout << "LCA of 5 and 1: " << result1->val << endl;
    }
    
    // 测试用例2：查找节点5和节点4的LCA
    // 节点5可以是自己的祖先
    cout << "\nTest Case 2:" << endl;
    TreeNode* p2 = findNode(root1, 5);
    TreeNode* q2 = findNode(root1, 4);
    
    TreeNode* result2 = sol.lowestCommonAncestor(root1, p2, q2);
    if (result2) {
        cout << "LCA of 5 and 4: " << result2->val << endl;
    }
    
    // 测试用例3：查找节点1和节点2的LCA
    // 树结构：
    //   1
    //  /
    // 2
    cout << "\nTest Case 3:" << endl;
    vector<int> vals3 = {1, 2, INT_MIN};
    TreeNode* root3 = createTree(vals3);
    
    TreeNode* p3 = findNode(root3, 1);
    TreeNode* q3 = findNode(root3, 2);
    
    cout << "Tree structure:" << endl;
    printTree(root3);
    
    TreeNode* result3 = sol.lowestCommonAncestor(root3, p3, q3);
    if (result3) {
        cout << "LCA of 1 and 2: " << result3->val << endl;
    }
    
    // 测试用例4：使用父指针方法验证结果
    cout << "\nTest Case 4 (using parent pointer method):" << endl;
    TreeNode* result4 = sol.lowestCommonAncestor_WithParent(root1, p1, q1);
    if (result4) {
        cout << "LCA of 5 and 1 (with parent method): " << result4->val << endl;
    }
    
    // 释放内存
    deleteTree(root1);
    deleteTree(root3);
    
    return 0;  // 程序正常结束
}
