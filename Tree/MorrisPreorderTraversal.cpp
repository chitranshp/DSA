// https://leetcode.com/problems/binary-tree-preorder-traversal/

/*
In inorder traveral, we print the node when we return back from exploring it's left subtree. Whereas in preorder traveral, we first process the node then explore the left subtree.

So, only difference between inorder and postorder traversal will be where we are processing/printing current node
TC - O(n) ammortized
SC - O(1)
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;

        while(curr != nullptr)
        {
            // Base case: This will be called for and used for processing leaf nodes or nodes whose left child is null
            if(curr->left == nullptr)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* prev = curr->left;
                while(prev->right != nullptr && prev->right != curr)
                    prev = prev->right;

                // Node or subtree has not been visited/threaded yet
                if(prev->right == nullptr)
                {
                    prev->right = curr;             // Connected to inorder successor/ singly threaded
                    preorder.push_back(curr->val);  // Process current node
                    curr = curr->left;              // Move to the left child of current node
                }
                else    // Node is already threaded. Traverse and get the inorder values
                {
                    prev->right = nullptr;      // Remove the threads
                    curr = curr->right;         // Explore right subtree 
                }
            }
        }

        return preorder;
    }
};
