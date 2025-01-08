// https://leetcode.com/problems/count-complete-tree-nodes/description/

/*
Brute Force: DFS/BFS(level order traversal without the inner for loop as we dont need to track levels just count nodes. Both complexities will still remain same but stack space can be saved for deeper trees.
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

/*
TC - O((logn) ^ 2)
1. The recursion goes down at most log𝑁 levels (tree height).
2. At each level, height calculation takes 𝑂(log𝑁)
3. Thus, the overall time complexity is 𝑂((log𝑁)^2)

SC - O(logn)
*/

class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;

        if(!root->left && !root->right)
            return 1;

        int leftHeight = 0, rightHeight = 0;
        TreeNode* leftPointer = root, *rightPointer = root;

        // This will run max go for h iterations where h is height of tree
        // Since, this a complete tree where height = logn. Therefore, at worst this will run logn times
        while(leftPointer)
        {
            leftHeight++;
            leftPointer = leftPointer->left;
        }

        while(rightPointer)
        {
            rightHeight++;
            rightPointer = rightPointer->right;
        }

        // If tree is perfect, directly calculate number of nodes using formula 2^h - 1
        if(leftHeight == rightHeight)
        {
            return ((1 << leftHeight)  - 1);
        }

        // If tree is non-perfect, recursively calculate, number of nodes in left and right subtree and then add them
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
