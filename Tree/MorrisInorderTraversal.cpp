// https://leetcode.com/problems/binary-tree-inorder-traversal/

/*
Morris inorder traversal is an algorithm which allows to traverse the tree with O(1) space complexity. It does not use any other data structure like auxiliary stack or queue
It utilizes the concept of threading binary trees.

Threaded binary trees
1. Single threaded binary trees: Empty right child pointers are threaded/connected to their inorder successor
2. Double threaded binary trees: Empty left child pointeres are connected to inorder predecessor and right child poiners are connected to inorder successor.

Case 1: There's no left subtree    (Note: This will be applicable for leaf nodes as well)
  Print the value of current node      (1. r->left 2. print(curr) 3. r->right)
  Move to the right child of current node(if exists)

Case 2: There's a left subtree and rightmost child of this subtree is pointing to null (Tree has not been threaded yet)
  Find the rightmost child of this LEFT subtree and point to the current node(It's inorder successor.) We can also say that, for the current node we will find it's inorder
  predeccesor and make it point to current node.
  Move to the LEFT child and repeat the process

Case 3: There's a left subtree and rightmost child of this subtree is pointing to current node (Tree has already been threaded)
  Process/Print the current node
  Find the rightmost child node pointing to curr and sever the connection i.e. make it point to null again as it is not needed again
  Move to the right child of current as left subtree is complete.

TC - O(2n) As each node will be traversed twice except nodes not having left child
SC - O(1)
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;

        while(curr != nullptr)
        {
            // Base case: This will be called for and used for processing leaf nodes or nodes whose left child is null
            if(curr->left == nullptr)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* prev = curr->left;
                while(prev->right != nullptr && prev->right != curr)
                    prev = prev->right;

                // Node or subtree has not been visited/threaded yet. Find the inorder predeccessor of current node and make it point to current node
                if(prev->right == nullptr)
                {
                    prev->right = curr; // Connected to inorder successor/ singly threaded
                    curr = curr->left;  // Move to the left child of current node (Process the left subtree)
                }
                else    // Node is already threaded. Traverse and get the inorder values then severe the thread
                {
                    prev->right = nullptr;          // Remove the thread
                    inorder.push_back(curr->val);   // Process the current node
                    curr = curr->right;             // Left subtree is done. Then move to the right subtree
                }
            }
        }

        return inorder;
    }
};
