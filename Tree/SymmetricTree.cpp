//https://leetcode.com/problems/symmetric-tree/

/*
TC - O(n)
SC - O(h)
*/
class Solution {
public:
    bool checkSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 && !root2)
            return false;
        if(!root1 && root2)
            return false;
        
        return ((root1->val == root2->val) && checkSymmetric(root1->left, root2->right) && checkSymmetric(root1->right, root2->left));
        
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        
        return checkSymmetric(root->left, root->right);    
    }
};
