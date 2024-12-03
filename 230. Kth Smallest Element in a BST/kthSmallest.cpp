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
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         if (!root) return -1;
//         vector<int> vec;
//         kthSmallestRecursion(root, vec);
//         return vec[k - 1];
//     }
//     void kthSmallestRecursion(TreeNode* root, vector<int>& vec) {
//         if (root->left) kthSmallestRecursion(root->left, vec);
//         vec.push_back(root->val);
//         if (root->right) kthSmallestRecursion(root->right, vec);
//     }
// };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        int ans;
        kthSmallestRecursion(root, k, ans);
        return ans;
    }
    void kthSmallestRecursion(TreeNode* root, int& count, int& ans) {
        if (root->left) kthSmallestRecursion(root->left, count, ans);
        --count;
        if (count == 0) ans = root->val;
        if (root->right && count > 0) kthSmallestRecursion(root->right, count, ans);
    }
};
