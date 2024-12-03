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
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         vector<ListNode*> nodes = {head};
//         while (nodes.back()->next) {
//             nodes.push_back(nodes.back()->next);
//         }

//         return nodes[nodes.size()/2];
//     }
// };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow; ListNode* fast;
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
