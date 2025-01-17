// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/*
LCA will be the last processed(highest depth) ancestor which is common to both p & q

If p and q are on opposite sides of the root:
This is the crucial case, as one will be in the left subtree and the other will be in the right subtree.
In this case, the current root is the LCA, because it is the deepest node where p and q diverge.

TC - O(n)
SC - O(n) for skewed tree
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;

        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};
