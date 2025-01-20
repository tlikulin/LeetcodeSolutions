#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        std::unordered_map<Node*, Node*> old_to_new;
        std::unordered_set<Node*> completed;

        std::queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr_node = q.front();
            q.pop();

            if (!old_to_new[curr_node])
                old_to_new[curr_node] = new Node(curr_node->val);

            for (Node* conn : curr_node->neighbors) {
                if (!old_to_new[conn]) {
                    old_to_new[conn] = new Node(conn->val);
                    q.push(conn);
                }
                if (!completed.contains(conn)) {
                    old_to_new[curr_node]->neighbors.push_back(old_to_new[conn]);
                    old_to_new[conn]->neighbors.push_back(old_to_new[curr_node]);
                }
            }

            completed.insert(curr_node);
        }

        return old_to_new[node];
    }
};