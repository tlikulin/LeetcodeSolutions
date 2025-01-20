#include <algorithm>
#include <limits.h>

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
    int getMinimumDifference(TreeNode* root) {
        int MD = INT_MAX;
        int prev = INT_MAX;
        getMinimumDifferenceRecursion(root, prev, MD);
        return MD;
    }
    void getMinimumDifferenceRecursion(TreeNode* root, int& prev, int& MD) {
        if (root->left) getMinimumDifferenceRecursion(root->left, prev, MD);
        MD = std::min(MD, abs(prev - root->val));
        prev = root->val;
        if (root->right) getMinimumDifferenceRecursion(root->right, prev, MD);
    }
};
