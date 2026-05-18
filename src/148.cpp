#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        //  找到中间节点
        ListNode* mid = getMid(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;
        //  递归排序左右两半
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);
        //  合并左右两半
        return merge(left, right);
    }
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        
        return dummy.next;
    }
};

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    
    return head;
}

void printList(ListNode* head) {
    ListNode* curr = head;
    cout << "[";
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) {
            cout << ",";
        }
        curr = curr->next;
    }
    cout << "]" << endl;
}

void deleteList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {4, 2, 1, 3};
    ListNode* head1 = createList(vals1);
    cout << "Input: [4,2,1,3]" << endl;
    cout << "Output: ";
    ListNode* sorted1 = sol.sortList(head1);
    printList(sorted1);
    deleteList(sorted1);
    
    cout << "\nTest Case 2:" << endl;
    vector<int> vals2 = {-1, 5, 3, 4, 0};
    ListNode* head2 = createList(vals2);
    cout << "Input: [-1,5,3,4,0]" << endl;
    cout << "Output: ";
    ListNode* sorted2 = sol.sortList(head2);
    printList(sorted2);
    deleteList(sorted2);
    
    cout << "\nTest Case 3:" << endl;
    ListNode* head3 = nullptr;
    cout << "Input: []" << endl;
    cout << "Output: ";
    ListNode* sorted3 = sol.sortList(head3);
    printList(sorted3);
    
    return 0;
}