#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> oldToNew {{nullptr, nullptr}};
        Node* it = head;

        while (it) {
            oldToNew[it] = new Node(it->val);
            it = it->next;
        }

        it = head;
        while (it) {
            oldToNew[it]->next = oldToNew[it->next];
            oldToNew[it]->random = oldToNew[it->random];
            it = it->next;
        }

        return oldToNew[head];
    }
};