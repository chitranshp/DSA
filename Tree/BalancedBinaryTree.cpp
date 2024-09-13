// https://leetcode.com/problems/balanced-binary-tree/

/*
Approach 1: Repeated redundant calls. 
TC - O(n ^ 2) (O(n) for each call to height function and isBalanced function)
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
    int findHeight(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int l = 1 + findHeight(root->left);
        int r = 1 + findHeight(root->right);

        return max(l, r);
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
            return true;

        int l = findHeight(root->left);
        int r = findHeight(root->right);

        if(abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        
        return false;
    }
};

/* 
Approach 2: One pass
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    int checker(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        
        int leftHeight = checker(root->left);
        if(leftHeight == -1)
            return -1;

        int rightHeight = checker(root->right);
        if(rightHeight == -1)
            return -1;

        if(abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) 
    {
        if(checker(root) == -1)
            return false;
        
        return true;
    }
};
