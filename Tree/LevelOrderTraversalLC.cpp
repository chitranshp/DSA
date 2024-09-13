// https://leetcode.com/problems/binary-tree-level-order-traversal

// TC - O(n)
// SC - O(n)

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;

        if(!root)
            return res;

        q.push(root);

        while(!q.empty())
        {
            vector<int> level;
            int currentDepth = q.size();    // All the nodes for a level will be processed together inside for loop. 

            for(int i = 0; i < currentDepth; i++)       // Process and enque all nodes present at a level.
            {
                TreeNode* node = q.front();
                int nodeVal =  node->val;
                int currentDepth = q.size();
                q.pop();
                
                level.push_back(nodeVal);

                if(node->left != nullptr)
                {
                    q.push(node->left);
                }

                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }

            res.push_back(level);
        }
        return res;
    }
};
