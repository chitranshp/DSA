// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

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
    long long UnderSum(TreeNode *root, long long totaltreesum, long long int &result)       //Resutl is passed by reference
    {
       if(!root)
            return 0;

        long long totalsum = root->val + UnderSum(root->left, totaltreesum, result) + UnderSum(root->right, totaltreesum, result);

        //          max(0, (0 - x) * x)  = 0
        result = max(result, ((totaltreesum - totalsum) * totalsum));         //Stores the final maximum product of sums
        return totalsum;          //This is the total sum for all the tree.
    }

    int maxProduct(TreeNode* root) 
    {
        long long result = 0, mod = 1e9+7;
        long long totaltreesum =  UnderSum(root, totaltreesum, result);

        result = 0;
        UnderSum(root, totaltreesum, result);

        return result % mod;
    }
};
