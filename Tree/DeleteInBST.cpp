// https://leetcode.com/problems/delete-node-in-a-bst/

/*
For any particular node, all nodes in left subtree are smaller then any of the node in right subtree
TC - O(h) which will be O(n) for skewed tree
SC - O(1)
*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == nullptr)
            return nullptr;

        if(root->val == key)
            return helper(root);

        TreeNode* curr = root;
        while(curr)
        {
            if(key < curr->val)
            {
                if(curr->left && curr->left->val == key)
                {
                    curr->left = helper(curr->left);    // curr->left == key is the node to be deleted
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if(curr->right && curr->right->val == key)
                {
                    curr->right = helper(curr->right);
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }

        return root;
    }

    TreeNode* helper(TreeNode* root)    // Here, root is the node which is to be deleted
    {
        // If no left subtree, return first node of right subtree skipping the node to be deleted
        if(root->left == nullptr)
        {
            return root->right;
        }
        else if(root->right == nullptr)
        {
            return root->left;
        }

        TreeNode* rightChild = root->right;      
        TreeNode* leftTreeLastRight = findLastRightChild(root->left);   // Find rightmost node of left subtree of node to be deleted
        leftTreeLastRight->right = rightChild;
        return root->left;              // Returning left child of node that is to be deleted which will replace that node in the tree
    }

    TreeNode* findLastRightChild(TreeNode* root)
    {
        while(root && root->right)
            root = root->right;

        return root;
    }
};
