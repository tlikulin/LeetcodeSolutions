#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int smallVal = std::min(p->val, q->val);
        int largeVal = std::max(p->val, q->val);

        while (root) {
            if (root->val > largeVal) root = root->left;
            else if (root->val < smallVal)root = root->right;
            else return root;
        }
        return nullptr;
    }
};