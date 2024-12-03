/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val > list2->val) swap(list1, list2);
        ListNode* res = list1;
        ListNode* temp;
        while (list1 && list1->next && list2) {
            if (list1->val <= list2->val) {
                if (list2->val <= list1->next->val) {
                    temp = list2->next;
                    list2->next = list1->next;
                    list1->next = list2;
                    list1 = list2;
                    list2 = temp;
                } else 
                    list1 = list1->next;
            }
        }
        if (list1 && list2)
            list1->next = list2;
        return res;
    }
};