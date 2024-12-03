/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int* prev = nullptr;
        bool valid = true;
        isValidBSTRecursion(root, prev, valid);
        return valid;
    }
    void isValidBSTRecursion(TreeNode* root, int*& prev, bool& valid) {
        if (root->left) isValidBSTRecursion(root->left, prev, valid);

        if (prev && *prev >= root->val) valid = false;
        if (!valid) return;
        prev = &root->val;

        if (root->right) isValidBSTRecursion(root->right, prev, valid);
    }
};