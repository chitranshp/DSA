// https://leetcode.com/problems/range-sum-of-bst/description/

//Using Recusive approach
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if(!root)
            return 0;

        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        if(root->val > high)
            return rangeSumBST(root->left, low, high);

        //If it is not less than low and not greater than high, then it must be in the range greater then or equal to low and less then or equal to high.
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

//Using Iterative approach

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if(!root)
            return 0;

        queue<TreeNode*> q;
        int sum = 0;

        q.push(root);
        while(!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            //if curr is 10, it will add it's sum(low = 7, high = 15)
            if(curr->val >= low && curr->val <= high)
                sum += curr->val;

            //If current node is 10 or 20, it will push it's left node to back of queue
            if(curr->left && curr->val > low)
                q.push(curr->left);

            //If current node is 10 or 5, it will push it's right node to back of queue
            if(curr->right && curr->val < high)
                q.push(curr->right);
        }

        return sum;
    }
};
