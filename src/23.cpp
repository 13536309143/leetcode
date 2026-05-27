#include <iostream>
#include <vector>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        int k = lists.size();
        while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[k - 1 - i]);
            }
            k = (k + 1) / 2;
        }
        
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = (l1 != nullptr) ? l1 : l2;
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    
    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
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
    vector<vector<int>> input1 = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> lists1;
    for (const auto& nums : input1) {
        lists1.push_back(createList(nums));
    }
    
    cout << "Test case 1:" << endl;
    cout << "Input: [[1,4,5],[1,3,4],[2,6]]" << endl;
    ListNode* result1 = solution.mergeKLists(lists1);
    cout << "Output: ";
    printList(result1);
    cout << "Expected: [1, 1, 2, 3, 4, 4, 5, 6]" << endl;
    cout << endl;
    
    // Test case 2
    vector<ListNode*> lists2;
    cout << "Test case 2:" << endl;
    cout << "Input: []" << endl;
    ListNode* result2 = solution.mergeKLists(lists2);
    cout << "Output: ";
    printList(result2);
    cout << "Expected: []" << endl;
    cout << endl;
    
    // Test case 3
    vector<ListNode*> lists3 = {createList({})};
    cout << "Test case 3:" << endl;
    cout << "Input: [[]]" << endl;
    ListNode* result3 = solution.mergeKLists(lists3);
    cout << "Output: ";
    printList(result3);
    cout << "Expected: []" << endl;
    
    return 0;
}