#include "Header.h"
using namespace std;

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
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