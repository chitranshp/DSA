// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*
If we need to find kth largest, we can do inorder in reverse i.e. visit right then left
TC - O(n)
SC - O(n) recursion stack in worst case 
*/

class Solution {
public:
    void helper(TreeNode* root, int &k, int &res)
    {
        if(root == nullptr || res != INT_MIN)
            return;

        helper(root->left, k, res);
        
        k--;
        if(k == 0)
        {
            res = root->val;
            return;
        }
        
        helper(root->right, k, res);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = INT_MIN;
        helper(root, k, res);
        return res;
    }
};

/*
Iterative approach
TC - O(n)
SC - O(1)
*/

    int kthSmallest(TreeNode* root, int k) {
        // int res = INT_MIN;
        // helper(root, k, res);
        // return res;

        stack<TreeNode*> st;
        while(true)
        {
            while(root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            // root will be equal to nullptr here
            root = st.top();        
            st.pop();
            if(--k == 0)
                return root->val;

            root = root->right;
        }
    }
