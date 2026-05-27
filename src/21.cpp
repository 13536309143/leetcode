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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        curr->next = (list1 != nullptr) ? list1 : list2;
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
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
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);
    
    cout << "Test case 1:" << endl;
    cout << "Input: l1 = [1,2,4], l2 = [1,3,4]" << endl;
    ListNode* result1 = solution.mergeTwoLists(list1, list2);
    cout << "Output: ";
    printList(result1);
    cout << "Expected: [1, 1, 2, 3, 4, 4]" << endl;
    cout << endl;
    
    // Test case 2
    ListNode* list3 = createList(nullptr, 0);
    ListNode* list4 = createList(nullptr, 0);
    
    cout << "Test case 2:" << endl;
    cout << "Input: l1 = [], l2 = []" << endl;
    ListNode* result2 = solution.mergeTwoLists(list3, list4);
    cout << "Output: ";
    printList(result2);
    cout << "Expected: []" << endl;
    cout << endl;
    
    // Test case 3
    ListNode* list5 = createList(nullptr, 0);
    int arr3[] = {0};
    ListNode* list6 = createList(arr3, 1);
    
    cout << "Test case 3:" << endl;
    cout << "Input: l1 = [], l2 = [0]" << endl;
    ListNode* result3 = solution.mergeTwoLists(list5, list6);
    cout << "Output: ";
    printList(result3);
    cout << "Expected: [0]" << endl;
    
    return 0;
}