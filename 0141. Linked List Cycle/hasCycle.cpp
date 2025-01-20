struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != slow) {
            if (!fast || !fast->next) {
                return false;
            } else {
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        return true;
    }
};