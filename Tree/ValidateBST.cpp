// https://leetcode.com/problems/validate-binary-search-tree/

/*
For each node, we will maintain max allowed value and min allowed value. This is because we are not checking at individual root level but for entire subtree for ex.
a tree rooted at 5, there cannot be another node in entire left subtree of 5 with a value >= 5
TC - O(n)
SC - O(n) worst case recursion stack
*/

class Solution {
public:
    bool validate(TreeNode* root, long low, long high)
    {
        if(root == nullptr)
            return true;

        if(root->val <= low || root->val >= high)
            return false;

        return validate(root->left, low, root->val) && validate(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;

        long low = LONG_MIN, high = LONG_MAX;
        return validate(root, low, high);
    }
};

/*
Approach 2: Use inorder
Inorder of a BST must always be in ascending order
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    // prev is being passed by reference such that it will preserve it's value across recursion calls
    bool validate(TreeNode* root, long &prev)
    {
        if(root == nullptr)
            return true;

        if(validate(root->left, prev) == false)
            return false;

        if(prev != LONG_MIN && root->val <= prev)
            return false;

        prev = root->val;
        return validate(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;

        long prev = LONG_MIN;  
        return validate(root, low);
    }
};
