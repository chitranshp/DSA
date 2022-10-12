//https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    void postorderHelper(TreeNode* root, vector<int>& ListNodes)
    {
        if(root)
        {
            postorderHelper(root->left, ListNodes);
            postorderHelper(root->right, ListNodes);
            ListNodes.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ListNodes;
        postorderHelper(root, ListNodes);
        return ListNodes;
    }
};
