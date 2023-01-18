// https://leetcode.com/problems/sum-of-left-leaves/submissions/880730399/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isleftchild = false) 
    {
        int res = 0;
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});

        while(!st.empty())
        {
            pair<TreeNode*, bool> curr = st.top();
            st.pop();

            if(curr.first->left == nullptr && curr.first->right == nullptr && curr.second == true)
                res += curr.first->val;

            if(curr.first->left != nullptr)
                st.push({curr.first->left, true});

            if(curr.first->right != nullptr)
                st.push({curr.first->right, false});
        }

        return res;
    }
};
