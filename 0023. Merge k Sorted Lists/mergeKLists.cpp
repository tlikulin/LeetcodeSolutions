#include <vector>
#include <queue>

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto myCmp = [] (const ListNode* p, const ListNode* q) {return p->val < q->val;};
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(myCmp)> maxHeap(myCmp);

        for (auto head : lists) {
            while (head) {
                maxHeap.push(head);
                head = head->next;
            }
        }

        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        while (!maxHeap.empty()) {
            curr = maxHeap.top(); maxHeap.pop();
            curr->next = prev;
            prev = curr;
        }

        return curr;
    }
};