//https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    void HelperPreOrder(TreeNode* root, vector<int> &res)
    {
        if(root)
        {
            res.push_back(root->val);
            HelperPreOrder(root->left, res);
            HelperPreOrder(root->right, res);
        }
        else
            return;
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        HelperPreOrder(root, res);
        return res;
    }
};
