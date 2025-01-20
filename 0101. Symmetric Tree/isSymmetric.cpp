struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool areSymmetricTrees(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        if (p->val != q->val) return false;
        return areSymmetricTrees(p->left, q->right) && areSymmetricTrees(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return areSymmetricTrees(root->left, root->right);
    }
};