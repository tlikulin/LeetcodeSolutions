struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr;
        ListNode dummy(0, head);
        ListNode* frw;
        ListNode* bck;
        frw = bck = &dummy;
        for (int i = 0; i <= n; ++i)
            frw = frw->next;
        while (frw) {
            bck = bck->next;
            frw = frw->next;
        }
        bck->next = bck->next->next;
        return dummy.next;
    }
};