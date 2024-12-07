struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* res = head;
        while (head->next) {
            if (head->next->val == head->val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return res;
    }
};