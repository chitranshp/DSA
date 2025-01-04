// https://leetcode.com/problems/maximum-width-of-binary-tree/

/*
Edge case: Empty tree, Skewed tree(can cause overflow), Sparse and deep trees(ex. a tree of 60 levels in which only first and last nodes at every level are non null)
Max number of nodes at a level = 2 ^ (level)
TC - O(n)
SC - O(n) Queue
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        int width = 0;

        q.push({root, 0});
        while(!q.empty())
        {
            int n = q.size();
            // Normalize/Rescale values to start from 0. So, that when doing 2 * i for finding child node index, it doesn't overflow.
            // We can also use any fixed arbitary number instead. Here, we use min index for each level, which will scale parents to have indexes from 0.
            long long minIndexAtEachLevel = q.front().second; 
            long long left = 0, right = 0;
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front().first;
                long long nodeIndex = q.front().second - minIndexAtEachLevel;
                q.pop();

                if(i == 0)
                    left = nodeIndex;
                if(i == n - 1)
                    right = nodeIndex;
                
                if(node->left != nullptr)
                    q.push({node->left, 2 * nodeIndex + 1});

                if(node->right != nullptr)
                    q.push({node->right, 2 * nodeIndex + 2});  // Type Cast to avoid overflow
            }

            width = max(width, right - left);       // As we want maximum width between two nodes (Ex. Suppose, last level has only one node. We will take the value )
        }

        return width + 1;
    }
};
