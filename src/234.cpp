#include <iostream>                 // 引入输入输出流库，用于cout输出
#include <stack>                    // 引入栈库，用于栈方法
#include <vector>                   // 引入向量库，用于创建链表
using namespace std;                // 使用标准命名空间，简化代码

// 定义单链表节点结构体
struct ListNode {
    int val;                        // 节点的值
    ListNode* next;                 // 指向下一个节点的指针
    
    // 无参构造函数：默认值为0，指针为nullptr
    ListNode() : val(0), next(nullptr) {}
    // 有参构造函数：初始化节点的值和指针
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution类：包含判断链表是否为回文的方法
class Solution {
public:
    // 方法1：快慢指针 + 反转（最优解）
    // 时间复杂度：O(n)，空间复杂度：O(1)
    // 核心思想：通过快慢指针找到链表中点，反转后半部分，然后比较前半部分和反转后的后半部分
    bool isPalindrome(ListNode* head) {
        // 边界情况：空链表或只有一个节点一定是回文
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        // 第一步：使用快慢指针找到链表中点
        // 慢指针每次移动1步，快指针每次移动2步
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 循环条件：快指针的下一个节点和下下一个节点都不为空
        // 这样当循环结束时，slow正好指向链表的中点（偶数长度时指向前半部分最后一个节点）
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;       // 慢指针移动1步
            fast = fast->next->next; // 快指针移动2步
        }
        
        // 第二步：反转后半部分链表
        // 从slow->next开始反转，反转后secondHalf指向新的头节点
        ListNode* secondHalf = reverseList(slow->next);
        
        // 第三步：比较前半部分和反转后的后半部分
        ListNode* p1 = head;          // 指向前半部分的指针
        ListNode* p2 = secondHalf;    // 指向后半部分（已反转）的指针
        bool result = true;           // 假设是回文
        
        // 比较两个部分的值
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;       // 发现不匹配，不是回文
                break;
            }
        // while (p2 != nullptr) {
        //     if (p1->val == p2->val) {
        //         // 当前节点相等，但你不能就此得出 result = true 并 break
        //         // 因为后面的节点可能不相等，所以你只能什么都不做，继续往下看
        //     } else {
        //         result = false; 
        //         break;
        //     }
            p1 = p1->next;
            p2 = p2->next;
        }        
        // 第四步：恢复链表结构（可选，但保持链表完整性）
        // 如果题目要求保持链表不变，需要将后半部分再反转回去
        // slow->next = reverseList(secondHalf);
        
        return result;
    }
    
    // 方法2：使用栈（简单直观，但空间复杂度为O(n)）
    // 时间复杂度：O(n)，空间复杂度：O(n)
    // 核心思想：将所有节点的值入栈，然后出栈与链表前半部分比较
    bool isPalindrome_Stack(ListNode* head) {
        // 边界情况
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        // 第一步：将所有节点的值入栈
        ListNode* current = head;
        stack<int> s;
        
        while (current != nullptr) {
            s.push(current->val);
            current = current->next;
        }
        
        // 第二步：出栈并与链表前半部分比较
        current = head;
        while (current != nullptr) {
            if (current->val != s.top()) {
                return false;
            }
            s.pop();
            current = current->next;
        }
        
        return true;
    }
    
    // 方法3：递归方法（空间复杂度O(n)）
    // 时间复杂度：O(n)，空间复杂度：O(n)（递归栈的深度）
    // 核心思想：递归到链表末尾，然后从后往前与前端节点比较
    bool isPalindrome_Recursive(ListNode* head) {
        // 边界情况
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        // 使用全局指针记录前端位置
        frontPointer = head;
        return recursivelyCheck(head);
    }
    
private:
    ListNode* frontPointer;  // 全局指针，用于递归方法，记录前端位置
    
    // 反转链表的辅助函数
    // head: 要反转的链表头节点
    // 返回值：反转后的链表头节点
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;      // 指向前一个节点的指针，初始为nullptr
        ListNode* current = head;      // 指向当前节点的指针
        ListNode* nextNode = nullptr;  // 指向下一个节点的指针
        
        // 遍历链表，逐个节点反转
        while (current != nullptr) {
            nextNode = current->next;  // 1. 保存下一个节点的指针
            current->next = prev;      // 2. 反转当前节点的指针，指向前一个节点
            prev = current;            // 3. prev移动到当前节点
            current = nextNode;        // 4. current移动到下一个节点
        }
        
        return prev;  // 返回反转后的头节点（原链表的尾节点）
    }
    
    // 递归检查函数（方法3使用）
    // currentNode: 当前递归到的节点
    // 返回值：从当前节点到末尾是否构成回文
    bool recursivelyCheck(ListNode* currentNode) {
        // 递归终止条件：到达链表末尾
        if (currentNode == nullptr) {
            return true;  // 递归到达末尾，返回true
        }
        
        // 递归检查后续节点
        // 先递归到链表末尾，再从后往前比较
        if (!recursivelyCheck(currentNode->next)) {
            return false;  // 如果后续节点不构成回文，直接返回false
        }
        
        // 比较前端节点和后端节点
        if (frontPointer->val != currentNode->val) {
            return false;  // 发现不匹配，返回false
        }
        
        // 前端指针前移
        frontPointer = frontPointer->next;
        
        return true;  // 当前节点与前端节点匹配，返回true
    }
};

// 辅助函数：从向量创建链表
// vals: 包含节点值的向量
// 返回值：创建的链表的头节点指针
ListNode* createList(vector<int> vals) {
    // 处理空向量的情况
    if (vals.empty()) {
        return nullptr;
    }
    
    // 创建头节点（向量第一个元素）
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    
    // 遍历向量中的剩余元素，依次添加到链表中
    for (size_t i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    
    return head;  // 返回创建的链表的头节点
}

// 辅助函数：打印链表
// head: 要打印的链表的头节点
void printList(ListNode* head) {
    cout << "[";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << ",";
        }
        current = current->next;
    }
    cout << "]" << endl;
}

// 辅助函数：释放链表内存
// head: 要删除的链表的头节点
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// 主函数：测试代码
int main() {
    Solution sol;  // 创建Solution类对象sol
    
    // 测试用例1：[1,2,2,1] - 是回文
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {1, 2, 2, 1};
    ListNode* head1 = createList(vals1);
    cout << "Input: ";
    printList(head1);
    cout << "Output: " << (sol.isPalindrome(head1) ? "true" : "false") << endl;
    deleteList(head1);
    
    // 测试用例2：[1,2] - 不是回文
    cout << "\nTest Case 2:" << endl;
    vector<int> vals2 = {1, 2};
    ListNode* head2 = createList(vals2);
    cout << "Input: ";
    printList(head2);
    cout << "Output: " << (sol.isPalindrome(head2) ? "true" : "false") << endl;
    deleteList(head2);
    
    // 测试用例3：[1] - 单个节点是回文
    cout << "\nTest Case 3:" << endl;
    vector<int> vals3 = {1};
    ListNode* head3 = createList(vals3);
    cout << "Input: ";
    printList(head3);
    cout << "Output: " << (sol.isPalindrome(head3) ? "true" : "false") << endl;
    deleteList(head3);
    
    // 测试用例4：[1,2,3,2,1] - 是回文
    cout << "\nTest Case 4:" << endl;
    vector<int> vals4 = {1, 2, 3, 2, 1};
    ListNode* head4 = createList(vals4);
    cout << "Input: ";
    printList(head4);
    cout << "Output: " << (sol.isPalindrome(head4) ? "true" : "false") << endl;
    deleteList(head4);
    
    // 测试用例5：[1,2,3,4,5] - 不是回文
    cout << "\nTest Case 5:" << endl;
    vector<int> vals5 = {1, 2, 3, 4, 5};
    ListNode* head5 = createList(vals5);
    cout << "Input: ";
    printList(head5);
    cout << "Output: " << (sol.isPalindrome(head5) ? "true" : "false") << endl;
    deleteList(head5);
    
    // 测试用例6：使用栈方法验证
    cout << "\nTest Case 6 (using stack method):" << endl;
    vector<int> vals6 = {1, 2, 3, 2, 1};
    ListNode* head6 = createList(vals6);
    cout << "Input: ";
    printList(head6);
    cout << "Output: " << (sol.isPalindrome_Stack(head6) ? "true" : "false") << endl;
    deleteList(head6);
    
    return 0;  // 程序正常结束
}