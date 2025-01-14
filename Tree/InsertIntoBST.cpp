// https://leetcode.com/problems/insert-into-a-binary-search-tree/

/*
Find a suitable(satisying condition of binary search tree) node whose child node is empty, and then insert our node. Our newly inserted node will be a leaf as it's left 
and right child will be null always because of the way we are inserting it
TC - O(n) worst case
SC - O(1)
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }

        TreeNode* curr = root;
        while(curr)
        {
            if(val < curr->val)
            {
                if(curr->left == nullptr)
                {
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            }
            else
            {
                if(curr->right == nullptr)
                {
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};
