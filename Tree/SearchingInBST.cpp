// https://leetcode.com/problems/search-in-a-binary-search-tree/

/*
TC - O(logn)
SC - O(logn) Recursion stack
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val)
            return root;
        
        if(root->val > val)
            return searchBST(root->left, val);
        
        return searchBST(root->right, val);
    }
};

/*
TC - O(logn)
SC - O(1)
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;

        TreeNode* curr = root;
        while(curr != nullptr && curr->val != val)
        {
            curr = curr->val > val ? curr->left: curr->right;
        }

        return curr;
    }
};
