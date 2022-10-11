//https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    void inorderHelper(TreeNode* root, vector<int> &ListNodes)
    {
        if(root)
        {
            inorderHelper(root->left, ListNodes);
            ListNodes.push_back(root->val);
            inorderHelper(root->right, ListNodes);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ListNodes;
        inorderHelper(root, ListNodes);
        return ListNodes;
    }
};
