#include <algorithm>

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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiam = 0;
        diameterOfBinaryTreeRecursion(root, maxDiam);
        return maxDiam;
    }
    int diameterOfBinaryTreeRecursion(TreeNode* root, int& maxDiam) {
        if (!root) return 0;

        int L = diameterOfBinaryTreeRecursion(root->left, maxDiam);
        int R = diameterOfBinaryTreeRecursion(root->right, maxDiam);
        maxDiam = std::max(maxDiam, L+R);

        return 1 + std::max(L, R);
    }
};