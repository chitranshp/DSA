// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    void dfs(TreeNode* root, int maxancestor, int minancestor, int &maxdiff)
    {
        if(root)
        {
            maxancestor = max(root->val, maxancestor);
            minancestor = min(root->val, minancestor);
            maxdiff = max(abs(maxancestor - minancestor), maxdiff);
            dfs(root->left, maxancestor, minancestor, maxdiff);
            dfs(root->right, maxancestor, minancestor, maxdiff);
        }
    }

    int maxAncestorDiff(TreeNode* root) 
    {
        int maxdiff = INT_MIN;
        dfs(root, root->val, root->val, maxdiff);
        return maxdiff;
    }
};
