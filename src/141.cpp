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
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        //  快慢指针判断是否有环
        ListNode* slow = head;
        ListNode* fast = head;
        //  初始化快慢指针
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            //  检查是否有环
            if (slow == fast) {
                return true;
            }
        }
        //  没有环，返回 false
        return false;
    }
};

ListNode* createListWithCycle(const vector<int>& vals, int pos) {
    if (vals.empty()) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    ListNode* cycleNode = nullptr;
    
    if (pos == 0) {
        cycleNode = head;
    }
    
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
        
        if (i == pos) {
            cycleNode = curr;
        }
    }
    
    if (cycleNode != nullptr) {
        curr->next = cycleNode;
    }
    
    return head;
}

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {3, 2, 0, -4};
    ListNode* head1 = createListWithCycle(vals1, 1);
    cout << "Input: head = [3,2,0,-4], pos = 1" << endl;
    cout << "Output: " << (sol.hasCycle(head1) ? "true" : "false") << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<int> vals2 = {1, 2};
    ListNode* head2 = createListWithCycle(vals2, 0);
    cout << "Input: head = [1,2], pos = 0" << endl;
    cout << "Output: " << (sol.hasCycle(head2) ? "true" : "false") << endl;
    
    cout << "\nTest Case 3:" << endl;
    vector<int> vals3 = {1};
    ListNode* head3 = createListWithCycle(vals3, -1);
    cout << "Input: head = [1], pos = -1" << endl;
    cout << "Output: " << (sol.hasCycle(head3) ? "true" : "false") << endl;
    
    return 0;
}