// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
TC - O(n) + O(n) ( O(n ^ 2) if hashing is not used)
SC - O(n) (map + stack space in worst case
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Input is not valid
        if(preorder.size() != inorder.size())
            return nullptr;     

        unordered_map<int, int> inorderIndexMap;

        // If there is a space constraint, we can skip this. And manually find index in each iteration/recursive step
        // Edge case: If the tree does not have all unique values then we cannot use this map. Then we have no other choice then manually finding the index.
        for(int i = 0; i < inorder.size(); i++)
        {
            inorderIndexMap[inorder[i]] = i;
        }

        TreeNode *root = buildSubtree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderIndexMap);
        return root;
    }

    TreeNode* buildSubtree(const vector<int> &preorder, int preStart, int preEnd,const vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inorderIndexMap)
    {
        // Base case: If the subtree is empty return null
        if(preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = inorderIndexMap[preorder[preStart]];
        int leftSubtreeSize = rootIndex - inStart;

        root->left = buildSubtree(preorder, preStart + 1, preStart + leftSubtreeSize, inorder, inStart, rootIndex - 1, inorderIndexMap);
        root->right = buildSubtree(preorder, preStart + leftSubtreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd, inorderIndexMap);
        return root;
    }
};
