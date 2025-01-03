// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/*
TC - O(n)
SC - O(h) or O(n) in worst case(skewed trees)
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != nullptr && right != nullptr)
            return root;

        if(left == nullptr)
            return right;
        else
            return left;
    }
};
