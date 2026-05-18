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
    ListNode* reverseList(ListNode* head) {
        return reverseIterative(head);
    }
    
    ListNode* reverseIterative(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* reverseRecursive(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* newHead = reverseRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
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
    vector<int> vals1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(vals1);
    cout << "Original: ";
    printList(head1);
    
    ListNode* reversed1 = sol.reverseIterative(head1);
    cout << "Reversed (iterative): ";
    printList(reversed1);
    deleteList(reversed1);
    
    cout << "\nTest Case 2:" << endl;
    vector<int> vals2 = {1, 2};
    ListNode* head2 = createList(vals2);
    cout << "Original: ";
    printList(head2);
    
    ListNode* reversed2 = sol.reverseRecursive(head2);
    cout << "Reversed (recursive): ";
    printList(reversed2);
    deleteList(reversed2);
    
    cout << "\nTest Case 3:" << endl;
    ListNode* head3 = nullptr;
    cout << "Original: ";
    printList(head3);
    
    ListNode* reversed3 = sol.reverseIterative(head3);
    cout << "Reversed (iterative): ";
    printList(reversed3);
    
    return 0;
}
