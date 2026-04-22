#include <iostream>                 // 引入输入输出流库，用于cout输出
#include <queue>                  // 引入队列库，用于层序遍历创建和遍历二叉树
#include <vector>                 // 引入向量库，用于存储节点值
#include <stack>                  // 引入栈库，用于深度优先遍历
using namespace std;              // 使用标准命名空间，简化代码

// 定义二叉树节点结构体
struct TreeNode {
    int val;                      // 节点的值
    TreeNode* left;               // 指向左子节点的指针
    TreeNode* right;              // 指向右子节点的指针
    
    // 无参构造函数：默认值为0，左右子节点指针为nullptr
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // 有参构造函数：初始化节点的值，左右子节点指针为nullptr
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution类：包含翻转二叉树的方法
class Solution {
public:
    // 方法1：递归法（推荐，最优解）
    // 时间复杂度：O(n)，空间复杂度：O(h)，h为树的高度（递归栈深度）
    // 核心思想：递归地交换每个节点的左右子节点
    // 使用后序遍历：先处理左右子树，再处理根节点
    TreeNode* invertTree(TreeNode* root) {
        // 基准情况（Base Case）：
        // 如果当前节点为空，直接返回nullptr
        if (root == nullptr) {
            return nullptr;
        }
        
        // 递归翻转左子树
        // 将左子树翻转后的根节点赋给left指针
        TreeNode* left = invertTree(root->left);
        
        // 递归翻转右子树
        // 将右子树翻转后的根节点赋给right指针
        TreeNode* right = invertTree(root->right);
        
        // 交换当前节点的左右子节点
        // 注意：此时left和right已经是翻转后的子树
        root->left = right;   // 左指针指向原来的右子树（已翻转）
        root->right = left;   // 右指针指向原来的左子树（已翻转）
        
        // 返回翻转后的当前节点
        return root;
    }
    
    // 方法2：迭代法（使用队列，层序遍历）
    // 时间复杂度：O(n)，空间复杂度：O(n)
    // 核心思想：使用队列进行层序遍历，交换每层的左右子节点
    TreeNode* invertTree_Iterative(TreeNode* root) {
        // 边界情况检查：如果根节点为空，直接返回nullptr
        if (root == nullptr) {
            return nullptr;
        }
        
        // 创建队列，用于层序遍历
        queue<TreeNode*> q;
        // 将根节点加入队列
        q.push(root);
        
        // 遍历队列中的节点
        while (!q.empty()) {
            // 取出队首节点作为当前节点
            TreeNode* current = q.front();
            q.pop();
            
            // 交换当前节点的左右子节点
            // 使用临时变量temp保存左子节点
            TreeNode* temp = current->left;
            current->left = current->right;  // 左指针指向右子节点
            current->right = temp;           // 右指针指向原左子节点
            
            // 将左右子节点加入队列（如果存在）
            // 注意：此时左右子节点已经交换
            if (current->left != nullptr) {
                // 将现在的左子节点（原来是右子节点）加入队列
                q.push(current->left);
            }
            if (current->right != nullptr) {
                // 将现在的右子节点（原来是左子节点）加入队列
                q.push(current->right);
            }
        }
        
        // 返回翻转后的根节点
        return root;
    }
    
    // 方法3：迭代法（使用栈，深度优先遍历）
    // 时间复杂度：O(n)，空间复杂度：O(h)
    // 核心思想：使用栈进行深度优先遍历，交换每个节点的左右子节点
    TreeNode* invertTree_Stack(TreeNode* root) {
        // 边界情况检查：如果根节点为空，直接返回nullptr
        if (root == nullptr) {
            return nullptr;
        }
        
        // 创建栈，用于深度优先遍历
        stack<TreeNode*> st;
        // 将根节点压入栈中
        st.push(root);
        
        // 遍历栈中的节点
        while (!st.empty()) {
            // 取出栈顶节点作为当前节点
            TreeNode* current = st.top();
            st.pop();
            
            // 交换当前节点的左右子节点
            // 使用临时变量temp保存左子节点
            TreeNode* temp = current->left;
            current->left = current->right;  // 左指针指向右子节点
            current->right = temp;           // 右指针指向原左子节点
            
            // 将左右子节点压入栈中（如果存在）
            // 注意：此时左右子节点已经交换
            if (current->left != nullptr) {
                // 将现在的左子节点（原来是右子节点）压入栈中
                st.push(current->left);
            }
            if (current->right != nullptr) {
                // 将现在的右子节点（原来是左子节点）压入栈中
                st.push(current->right);
            }
        }
        
        // 返回翻转后的根节点
        return root;
    }
};

// 辅助函数：使用层序遍历的方式创建二叉树
// values: 包含树节点值的向量，-1表示null节点
// 返回值：创建的二叉树的根节点指针
TreeNode* createTree(vector<int> values) {
    // 处理空向量的情况
    if (values.empty()) {
        return nullptr;
    }
    
    // 创建根节点（向量第一个元素）
    TreeNode* root = new TreeNode(values[0]);
    
    // 使用队列进行层序遍历，建立节点关系
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;  // 从向量第二个元素开始（索引1）
    
    // 循环处理队列中的节点
    while (i < values.size()) {
        // 取出队首节点作为当前父节点
        TreeNode* current = q.front();
        q.pop();
        
        // 处理左子节点
        if (i < values.size()) {
            // 如果不是-1，说明有左子节点
            if (values[i] != -1) {
                // 创建左子节点
                current->left = new TreeNode(values[i]);
                // 将左子节点加入队列，以便后续处理它的子节点
                q.push(current->left);
            }
            i++;  // 处理完一个元素，索引加1
        }
        
        // 处理右子节点
        if (i < values.size()) {
            // 如果不是-1，说明有右子节点
            if (values[i] != -1) {
                // 创建右子节点
                current->right = new TreeNode(values[i]);
                // 将右子节点加入队列
                q.push(current->right);
            }
            i++;  // 处理完一个元素，索引加1
        }
    }
    
    // 返回创建的树的根节点
    return root;
}

// 辅助函数：层序遍历打印二叉树
// root: 二叉树的根节点
void printTree(TreeNode* root) {
    // 处理空树的情况
    if (root == nullptr) {
        cout << "[]" << endl;
        return;
    }
    
    // 使用队列进行层序遍历
    queue<TreeNode*> q;
    q.push(root);
    
    vector<int> result;  // 存储遍历结果的向量
    
    // 遍历并收集节点值
    while (!q.empty()) {
        // 取出队首节点
        TreeNode* current = q.front();
        q.pop();
        
        if (current != nullptr) {
            // 如果节点不为空，将其值加入结果
            result.push_back(current->val);
            // 将左右子节点加入队列（即使为nullptr也加入，用于保持位置信息）
            q.push(current->left);
            q.push(current->right);
        } else {
            // 如果节点为空，用-1表示
            result.push_back(-1);
        }
    }
    
    // 去除末尾的-1（这些是树右边的空节点）
    while (!result.empty() && result.back() == -1) {
        result.pop_back();
    }
    
    // 打印结果
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        if (result[i] == -1) {
            cout << "null";  // 用null表示空节点
        } else {
            cout << result[i];
        }
        if (i < result.size() - 1) {
            cout << ",";  // 节点之间用逗号分隔
        }
    }
    cout << "]" << endl;
}

// 辅助函数：释放二叉树占用的内存
// root: 要删除的树的根节点
void deleteTree(TreeNode* root) {
    // 后序遍历删除所有节点
    if (root == nullptr) {
        return;
    }
    
    // 先递归删除左子树
    deleteTree(root->left);
    // 再递归删除右子树
    deleteTree(root->right);
    // 最后删除当前节点
    delete root;
}

// 主函数：测试代码
int main() {
    Solution sol;  // 创建Solution类对象sol
    
    // 测试用例1：[4,2,7,1,3,6,9]
    // 翻转后：[4,7,2,9,6,3,1]
    cout << "Test Case 1:" << endl;
    cout << "Original tree: ";
    // 使用向量创建树：{根, 左子, 右子, 左左, 左右, 右左, 右右, ...}
    vector<int> vals1 = {4, 2, 7, 1, 3, 6, 9};
    TreeNode* root1 = createTree(vals1);
    printTree(root1);
    
    cout << "Inverted tree (recursive): ";
    // 使用递归法翻转树
    TreeNode* result1 = sol.invertTree(root1);
    printTree(result1);
    deleteTree(result1);
    
    // 测试用例2：[2,1,3]
    // 翻转后：[2,3,1]
    cout << "\nTest Case 2:" << endl;
    cout << "Original tree: ";
    vector<int> vals2 = {2, 1, 3};
    TreeNode* root2 = createTree(vals2);
    printTree(root2);
    
    cout << "Inverted tree (recursive): ";
    TreeNode* result2 = sol.invertTree(root2);
    printTree(result2);
    deleteTree(result2);
    
    // 测试用例3：空树 []
    // 翻转后：[]
    cout << "\nTest Case 3:" << endl;
    cout << "Original tree: ";
    TreeNode* root3 = nullptr;
    printTree(root3);
    
    cout << "Inverted tree (recursive): ";
    TreeNode* result3 = sol.invertTree(root3);
    printTree(result3);
    
    // 测试用例4：使用迭代方法验证
    cout << "\nTest Case 4 (using iterative method):" << endl;
    cout << "Original tree: ";
    vector<int> vals4 = {4, 2, 7, 1, 3, 6, 9};
    TreeNode* root4 = createTree(vals4);
    printTree(root4);
    
    cout << "Inverted tree (iterative): ";
    // 使用迭代法翻转树
    TreeNode* result4 = sol.invertTree_Iterative(root4);
    printTree(result4);
    deleteTree(result4);
    
    return 0;  // 程序正常结束
}
