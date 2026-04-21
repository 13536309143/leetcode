#include <iostream>                 // 引入输入输出流库，用于cout输出
#include <unordered_set>             // 引入哈希集合库（虽然未使用，但保留以备扩展）
#include <vector>                   // 引入向量容器库，用于辅助函数createList
using namespace std;                 // 使用标准命名空间，简化代码

// 定义链表节点结构体
struct ListNode {
    int val;                        // 节点的值
    ListNode* next;                 // 指向下一个节点的指针
    
    // 构造函数：初始化节点的值和指针
    // x: 节点的值
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution类：包含找到两个链表相交节点的方法
class Solution {
public:
    // 方法1：双指针法（最优解）
    // 时间复杂度：O(m+n)，空间复杂度：O(1)
    // 核心思想：让两个指针分别遍历两个链表，当一个指针到达末尾时切换到另一个链表的头部
    // 如果两个链表相交，两个指针最终会在相交节点相遇；如果不相交，两个指针都会变成nullptr
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // 边界情况检查：如果任一链表为空，直接返回nullptr
        if (!headA || !headB) {
            return nullptr;
        }
        
        // 初始化两个指针，分别指向两个链表的头节点
        ListNode* pa = headA;
        ListNode* pb = headB;
        
        // 当两个指针不相等时继续循环
        // 循环终止条件：pa == pb
        // 1. 如果链表相交，两个指针会在相交节点相遇
        // 2. 如果链表不相交，两个指针会同时变成nullptr，然后相遇
        while (pa != pb) {
            // 指针pa向前移动一步
            // 如果pa到达链表A的末尾（nullptr），则切换到链表B的头节点
            // 否则，pa移动到下一个节点
            pa = (pa == nullptr) ? headB : pa->next;
            
            // 指针pb向前移动一步
            // 如果pb到达链表B的末尾（nullptr），则切换到链表A的头节点
            // 否则，pb移动到下一个节点
            pb = (pb == nullptr) ? headA : pb->next;
        }
        
        // 返回相交节点
        // 如果链表相交，返回相交节点的指针
        // 如果链表不相交，返回nullptr（两个指针都变成nullptr时pa == pb为true，循环结束）
        return pa;
    }
    
    // 方法2：长度差法
    // 时间复杂度：O(m+n)，空间复杂度：O(1)
    // 核心思想：先计算两个链表的长度差，让较长的链表先走差值步，然后同时前进找到交点
    ListNode* getIntersectionNode_Length(ListNode* headA, ListNode* headB) {
        // 计算两个链表的长度
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        // 计算两个链表的长度差（取绝对值）
        int diff = abs(lenA - lenB);
        
        // 确定哪个链表较长，哪个较短
        // 三元运算符：如果lenA >= lenB，longList指向headA，否则指向headB
        ListNode* longList = (lenA >= lenB) ? headA : headB;
        // 相反地，shortList指向较短的链表
        ListNode* shortList = (lenA >= lenB) ? headB : headA;
        
        // 让较长的链表先移动diff步，消除长度差
        // 这样两个指针就会处于对齐的位置
        for (int i = 0; i < diff; i++) {
            longList = longList->next;
        }
        
        // 现在同时移动两个指针，每次移动一步
        // 当两个指针相遇时，就是相交的节点
        while (longList && shortList) {
            // 检查当前两个节点是否是同一个节点（相交）
            if (longList == shortList) {
                return longList;     // 返回相交节点
            }
            // 同时向前移动一步
            longList = longList->next;
            shortList = shortList->next;
        }
        
        // 如果循环结束还没有返回，说明两个链表不相交
        return nullptr;
    }
    
private:
    // 辅助函数：计算链表的长度
    // head: 链表的头节点指针
    // 返回值：链表中的节点数量
    int getLength(ListNode* head) {
        int length = 0;               // 初始化长度为0
        ListNode* curr = head;       // 使用curr指针遍历链表
        
        // 遍历链表，计数节点
        while (curr) {
            length++;                // 节点数加1
            curr = curr->next;       // 移动到下一个节点
        }
        
        return length;               // 返回链表长度
    }
    
    // 辅助函数：计算整数的绝对值
    // x: 输入的整数
    // 返回值：x的绝对值
    int abs(int x) {
        // 如果x >= 0，返回x；否则返回-x
        return (x >= 0) ? x : -x;
    }
};

// 辅助函数：从向量创建链表
// vals: 包含要创建链表值的向量
// 返回值：创建好的链表的头节点指针
ListNode* createList(vector<int> vals) {
    // 处理空向量的情况
    if (vals.empty()) {
        return nullptr;
    }
    
    // 创建链表的头节点
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    
    // 遍历向量中的剩余元素，依次添加到链表中
    // 从索引1开始（索引0已经是头节点）
    for (size_t i = 1; i < vals.size(); i++) {
        // 创建新节点并连接到当前节点
        curr->next = new ListNode(vals[i]);
        // 移动curr指针到新创建的节点
        curr = curr->next;
    }
    
    return head;                     // 返回链表头节点
}

// 辅助函数：打印链表（用于调试）
// head: 链表的头节点指针
// 输出格式：[val1,val2,val3,...]
void printList(ListNode* head) {
    ListNode* curr = head;          // 使用curr指针遍历链表
    cout << "[";                    // 开始输出左括号
    
    // 遍历链表，输出每个节点的值
    while (curr) {
        cout << curr->val;           // 输出当前节点的值
        
        // 如果不是最后一个节点，输出逗号分隔符
        if (curr->next) {
            cout << ",";
        }
        
        curr = curr->next;           // 移动到下一个节点
    }
    
    cout << "]";                    // 输出右括号，完成格式化输出
}

// 辅助函数：释放链表占用的内存
// head: 链表的头节点指针
// 注意：对于相交的链表，只需要删除一次共享节点
void deleteList(ListNode* head) {
    // 遍历链表，逐个删除节点
    while (head) {
        ListNode* temp = head;       // 保存当前节点的指针
        head = head->next;           // 先移动head到下一个节点
        delete temp;                 // 然后删除当前节点（避免删除后无法访问next）
    }
}

// 主函数：测试代码
int main() {
    Solution sol;                    // 创建Solution类对象sol
    
    // 测试用例1：两个链表相交
    // A: 4 -> 1 -> 8 -> 4 -> 5
    // B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    // 其中节点8是相交节点
    cout << "Test Case 1:" << endl;
    
    // 创建相交部分：8 -> 4 -> 5
    ListNode* intersect1 = new ListNode(8);
    intersect1->next = new ListNode(4);
    intersect1->next->next = new ListNode(5);
    
    // 创建链表A：4 -> 1 -> 8（然后连接到intersect1）
    ListNode* headA1 = new ListNode(4);
    headA1->next = new ListNode(1);
    headA1->next->next = intersect1;
    
    // 创建链表B：5 -> 6 -> 1 -> 8（然后连接到intersect1）
    ListNode* headB1 = new ListNode(5);
    headB1->next = new ListNode(6);
    headB1->next->next = new ListNode(1);
    headB1->next->next->next = intersect1;
    
    // 调用方法1（双指针法）查找相交节点
    ListNode* result1 = sol.getIntersectionNode(headA1, headB1);
    if (result1) {
        cout << "Intersection value: " << result1->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    
    // 释放链表A的内存（intersect1会被deleteList(headA1)删除）
    // 注意：不要再次删除intersect1，因为它是共享的
    deleteList(headA1);
    
    // 测试用例2：两个链表不相交
    // A: 2 -> 6 -> 4
    // B: 1 -> 5
    cout << "\nTest Case 2:" << endl;
    
    ListNode* headA2 = new ListNode(2);
    headA2->next = new ListNode(6);
    headA2->next->next = new ListNode(4);
    
    ListNode* headB2 = new ListNode(1);
    headB2->next = new ListNode(5);
    
    // 查找相交节点（应该返回nullptr）
    ListNode* result2 = sol.getIntersectionNode(headA2, headB2);
    if (result2) {
        cout << "Intersection value: " << result2->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    
    // 释放两个链表的内存（这两个链表不相交，所以可以正常删除）
    deleteList(headA2);
    deleteList(headB2);
    
    // 测试用例3：使用长度差法测试
    // A: 1 -> 9 -> 1 -> 2 -> 4
    // B: 3 -> 2 -> 4
    // 其中节点2是相交节点
    cout << "\nTest Case 3 (using length method):" << endl;
    
    // 创建相交部分：2 -> 4
    ListNode* intersect3 = new ListNode(2);
    intersect3->next = new ListNode(4);
    
    // 创建链表A：1 -> 9 -> 1 -> 2（然后连接到intersect3）
    ListNode* headA3 = new ListNode(1);
    headA3->next = new ListNode(9);
    headA3->next->next = new ListNode(1);
    headA3->next->next->next = intersect3;
    
    // 创建链表B：3 -> 2（然后连接到intersect3）
    ListNode* headB3 = new ListNode(3);
    headB3->next = intersect3;
    
    // 调用方法2（长度差法）查找相交节点
    ListNode* result3 = sol.getIntersectionNode_Length(headA3, headB3);
    if (result3) {
        cout << "Intersection value: " << result3->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    
    // 释放链表A的内存（intersect3会被deleteList(headA3)删除）
    deleteList(headA3);
    
    return 0;                       // 程序正常结束
}
/*### 核心算法实现
1. 方法1：双指针法（最优解） - getIntersectionNode
   
   - 时间复杂度：O(m+n)
   - 空间复杂度：O(1)
   - 核心思想：让两个指针分别遍历两个链表，当一个到达末尾时切换到另一个链表的头部，最终会在相交节点相遇
2. 方法2：哈希集合法 （代码中未使用）
   
   - 时间复杂度：O(m+n)
   - 空间复杂度：O(m)
3. 方法3：长度差法 - getIntersectionNode_Length
   
   - 时间复杂度：O(m+n)
   - 空间复杂度：O(1)
   - 核心思想：先计算两个链表的长度差，让较长的链表先走差值步，然后同时前进*/