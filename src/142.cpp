#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        //  快慢指针判断是否有环
        ListNode* slow = head;
        ListNode* fast = head;
        //  初始化快慢指针
        bool hasCycle = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            //  检查是否有环
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        //  没有环，返回 nullptr
        if (!hasCycle) {
            return nullptr;
        }
        //  有环，找到环入口节点
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        //  返回环入口节点
        return slow;
    }
};

ListNode* createListWithCycle(const vector<int>& vals, int pos) {
    if (vals.empty()) {
        return nullptr;
    }
    //  创建链表
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    ListNode* cycleNode = nullptr;
    //  处理循环节点
    if (pos == 0) {
        cycleNode = head;
    }
    
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
        
        //  设置环入口节点
        if (i == pos) {
            cycleNode = curr;
        }
    }
    //  连接环入口节点
    if (cycleNode != nullptr) {
        curr->next = cycleNode;
    }
    //  返回链表头节点
    return head;
}

void printResult(ListNode* result) {
    if (result == nullptr) {
        cout << "null" << endl;
    } else {
        cout << "Index: " << result->val << endl;
    }
}

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {3, 2, 0, -4};
    ListNode* head1 = createListWithCycle(vals1, 1);
    ListNode* result1 = sol.detectCycle(head1);
    cout << "Input: head = [3,2,0,-4], pos = 1" << endl;
    cout << "Output: ";
    printResult(result1);
    
    cout << "\nTest Case 2:" << endl;
    vector<int> vals2 = {1, 2};
    ListNode* head2 = createListWithCycle(vals2, 0);
    ListNode* result2 = sol.detectCycle(head2);
    cout << "Input: head = [1,2], pos = 0" << endl;
    cout << "Output: ";
    printResult(result2);
    
    cout << "\nTest Case 3:" << endl;
    vector<int> vals3 = {1};
    ListNode* head3 = createListWithCycle(vals3, -1);
    ListNode* result3 = sol.detectCycle(head3);
    cout << "Input: head = [1], pos = -1" << endl;
    cout << "Output: ";
    printResult(result3);
    
    return 0;
}