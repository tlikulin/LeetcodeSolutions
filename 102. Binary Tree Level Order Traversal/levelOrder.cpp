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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderRecursion(root, res, 0);
        return res;
    }
    void levelOrderRecursion(TreeNode* root, vector<vector<int>>& res, int level) {
        if (!root) return;

        if (res.size() <= level) res.push_back({root->val});
        else                    res[level].push_back(root->val);

        levelOrderRecursion(root->left, res, level + 1);
        levelOrderRecursion(root->right, res, level + 1);
    }
};