// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/*
Use the property that inorder traversal of a BST is same as it's ascsending order
TC - O(n) + O(nlogn) for sorting
SC - O(n) auxiliary DS + recursion stack
*/
class Solution {
public:
    TreeNode* helper(const vector<int> &preorder, int prebegin, int preend, vector<int> &inorder, int inbegin, int inend, unordered_map<int, int> &indexInorderMap)
    {
        if(prebegin > preend || inbegin > inend)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[prebegin]);
        int nodeInorderIndex = indexInorderMap[preorder[prebegin]];
        int leftSubtreeSize = nodeInorderIndex - inbegin;

        node->left = helper(preorder, prebegin + 1, prebegin + leftSubtreeSize, inorder, inbegin, nodeInorderIndex - 1, indexInorderMap);
        node->right = helper(preorder, prebegin + leftSubtreeSize + 1, preend, inorder, nodeInorderIndex + 1, inend, indexInorderMap);
        return node;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());          // For BST, inorder is same as the ascending order of bst elements
        unordered_map<int, int> indexInorderMap;

        for(int i = 0; i < inorder.size(); i++)
            indexInorderMap[inorder[i]] = i;

        TreeNode* root;
        int n = preorder.size();
        return helper(preorder, 0, n - 1, inorder, 0, n - 1, indexInorderMap);
    }
};


/*
Without sorting: Using BST property + Preorder
From L to R, for an element at preorder[0] all consecutive elements which are smaller then preorder[0] are part of it's left subtree and other are part of its right subtree. So, we can use divide and conquer to build 
the whole BST

TC - O(n ^ 2)
In worst case ie. skewed tree for each element, we will have to go from it's index + 1 to n as it's skewed all elements will be either < or > then it and this will repeat for all n - 1 elements. So, in total 
n - 1 + n- 2 + ... + 1 = O(n^ 2)
SC - O(n) for recursion stack
*/

class Solution {
public:
    TreeNode* constructBST(const vector<int>& preorder, int left, int right) {
        if(left >= right)
            return nullptr;

        int splitIndex = left + 1;
        while(splitIndex < right && preorder[splitIndex] < preorder[left])
            splitIndex++;

        TreeNode* node = new TreeNode(preorder[left]);
        node->left = constructBST(preorder, left + 1, splitIndex);
        node->right = constructBST(preorder, splitIndex, right);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = constructBST(preorder, 0, preorder.size());
        return root;
    }
};

