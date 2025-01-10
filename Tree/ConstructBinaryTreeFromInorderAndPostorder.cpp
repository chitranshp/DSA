// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
TC - O(n) + O(n) ( O(n ^ 2) if hashing is not used)
SC - O(n) (map + stack space in worst case
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Invalid input
        if(inorder.size() != postorder.size())
            return nullptr;

        unordered_map<int, int> inorderIndexMap;
        
        // If there is a space constraint, we can skip this. And manually find index in each iteration/recursive step
        // Edge case: If the tree does not have all unique values then we cannot use this map. Then we have no other choice then manually finding the index.
        for(int i = 0; i < inorder.size(); i++)
        {
            inorderIndexMap[inorder[i]] = i;
        }

        TreeNode* root = buildSubtree(inorder, 0, inorder.size() - 1, postorder,0, postorder.size() - 1, inorderIndexMap);
        return root;
    }

    TreeNode* buildSubtree(const vector<int> &inorder, int inStart, int inEnd, const vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &inorderIndexMap)
    {
        // If the subtree is empty return null
        if(inStart > inEnd || postStart > postEnd)
            return nullptr;

        int rootInorderIndex = inorderIndexMap[postorder[postEnd]];
        int numNodesInLeftSubtree = rootInorderIndex - inStart;

        TreeNode* root = new TreeNode(inorder[rootInorderIndex]);
        root->left = buildSubtree(inorder, inStart, rootInorderIndex - 1, postorder, postStart, postStart + numNodesInLeftSubtree - 1, inorderIndexMap);
        root->right = buildSubtree(inorder, rootInorderIndex + 1, inEnd, postorder, postStart + numNodesInLeftSubtree, postEnd - 1, inorderIndexMap);
        return root;
    }
};
