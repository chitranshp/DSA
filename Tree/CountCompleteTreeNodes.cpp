// https://leetcode.com/problems/count-complete-tree-nodes/description/

/*
Brute Force: DFS/BFS
TC - O(n)
SC - O(n)  (Stack space as in worst case all n nodes can be in the stack)
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
