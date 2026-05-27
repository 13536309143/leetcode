#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {//// 删除倒数第n个节点
        if (head == nullptr) {// 如果头表为空
            return nullptr;// 返回空指针
        }
        ListNode* dummy = new ListNode(-1);// 创建一个虚拟头节点
        dummy->next = head;// 虚拟头节点指向头表
        
        ListNode* fast = dummy;// 快指针指向虚拟头节点
        ListNode* slow = dummy;// 慢指针指向虚拟头节点
        
        for (int i = 0; i <= n; i++) {// 快指针先走n步
            fast = fast->next;// 快指针走一步
        }
        
        while (fast != nullptr) {// 快指针走到头
            // 慢指针走到倒数第n个节点的前一个节点
            // 因为慢指针走n步，所以快指针走n步，慢指针走n步，所以慢指针走到倒数第n个节点的前一个节点
            fast = fast->next;// 快指针走一步
            slow = slow->next;// 慢指针走一步
        }
        
        ListNode* temp = slow->next;// 临时指针指向倒数第n个节点
        slow->next = slow->next->next;// 删除倒数第n个节点
        delete temp;// 释放倒数第n个节点的内存
        
        ListNode* result = dummy->next;// 返回头表
        delete dummy;// 释放虚拟头节点的内存
        return result;// 返回头表
    }
};

ListNode* createList(int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    
    return head;
}

void printList(ListNode* head) {
    cout << "[";
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) {
            cout << ", ";
        }
        curr = curr->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    
    cout << "Test case 1:" << endl;
    cout << "Input: head = [1,2,3,4,5], n = 2" << endl;
    ListNode* result1 = solution.removeNthFromEnd(head1, 2);
    cout << "Output: ";
    printList(result1);
    cout << "Expected: [1, 2, 3, 5]" << endl;
    cout << endl;
    
    // Test case 2
    int arr2[] = {1};
    ListNode* head2 = createList(arr2, 1);
    
    cout << "Test case 2:" << endl;
    cout << "Input: head = [1], n = 1" << endl;
    ListNode* result2 = solution.removeNthFromEnd(head2, 1);
    cout << "Output: ";
    printList(result2);
    cout << "Expected: []" << endl;
    cout << endl;
    
    // Test case 3
    int arr3[] = {1, 2};
    ListNode* head3 = createList(arr3, 2);
    
    cout << "Test case 3:" << endl;
    cout << "Input: head = [1,2], n = 1" << endl;
    ListNode* result3 = solution.removeNthFromEnd(head3, 1);
    cout << "Output: ";
    printList(result3);
    cout << "Expected: [1]" << endl;
    
    return 0;
}