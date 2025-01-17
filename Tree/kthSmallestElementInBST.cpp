// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*
If we need to find kth largest, we can do inorder in reverse i.e. visit right then left
TC - O(n)
SC - O(n) recursion stack in worst case 
*/

class Solution {
public:
    void helper(TreeNode* root, int &k, int &res)
    {
        if(root == nullptr || res != INT_MIN)
            return;

        helper(root->left, k, res);
        
        k--;
        if(k == 0)
        {
            res = root->val;
            return;
        }
        
        helper(root->right, k, res);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = INT_MIN;
        helper(root, k, res);
        return res;
    }
};
