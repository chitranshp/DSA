// https://leetcode.com/problems/diameter-of-binary-tree/

/*
We are calculating in bottom up manner. Each node will be processed only once.
TC - O(n)
SC - O(n)
*/

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
    int helper(TreeNode *root, int &res)
    {
        if(root == nullptr)
            return 0;

        int l = helper(root->left, res);
        int r = helper(root->right, res);

        res = max(res, l + r);

        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = -1;
        helper(root, res);
        return res;
    }
};
