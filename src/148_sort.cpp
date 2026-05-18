#include <iostream>
#include <vector>
#include <algorithm>
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
        if (head == nullptr) {
            return nullptr;
        }
        
        //  第一步：将链表值提取到数组
        vector<int> values;
        ListNode* curr = head;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        
        sort(values.begin(), values.end());
        
        ListNode dummy(0);
        curr = &dummy;
        for (int val : values) {
            curr->next = new ListNode(val);
            curr = curr->next;
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
    ListNode* sorted1 = sol.sortList(head1);
    cout << "Output: ";
    printList(sorted1);
    deleteList(sorted1);
    
    cout << "\nTest Case 2:" << endl;
    vector<int> vals2 = {-1, 5, 3, 4, 0};
    ListNode* head2 = createList(vals2);
    cout << "Input: [-1,5,3,4,0]" << endl;
    ListNode* sorted2 = sol.sortList(head2);
    cout << "Output: ";
    printList(sorted2);
    deleteList(sorted2);
    
    cout << "\nTest Case 3:" << endl;
    ListNode* head3 = nullptr;
    cout << "Input: []" << endl;
    ListNode* sorted3 = sol.sortList(head3);
    cout << "Output: ";
    printList(sorted3);
    
    return 0;
}