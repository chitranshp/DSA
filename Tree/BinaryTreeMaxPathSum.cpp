// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    /*

    The path could be going through:
    1.  Root node only
    2.  Left sub tree + root 
    3.  Right sub tree + root
    4.  Left sub tree + Right sub tree + root

    */
    int maxdfs(TreeNode *root, int &globalmax)
    {
        if(!root)
            return 0;
        //Maximum path going through the left and right child
        int l = maxdfs(root->left, globalmax);
        int r = maxdfs(root->right, globalmax);

        //Value to be returned for the parent call. It must include ATMOST one child of node. 
        int max_single = max(max(l,r) + root->val, root->val);

        //Max path sum for the node under consideration, such that no other ancestor of node is in the path
        int max_top = max(max_single, l + r + root->val);

        //Final comparison with the global max.
        globalmax = max(globalmax, max_top);

        return max_single;          //Returns the max sum path for a node(including that node) such that at most one child is involved.

    }
    
    int maxPathSum(TreeNode* root) 
    {
        int result = INT_MIN;
        maxdfs(root, result);
        return result;

    }
};
