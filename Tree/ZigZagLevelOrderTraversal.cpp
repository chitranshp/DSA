// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/*
Same as level order traversal with small modification.
Approaches:
1. Use dequeue. Alternate between front and back for extracting value from queue. Tradeoff -> Memory overhead for maintaining extra pointers
2. Use stl reverse operation
3. Use a fixed size level array. And insert elements at specific positions.

TC - O(n)
SC - O(n)
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == nullptr)
            return {};

        queue<TreeNode*> q;
        vector<vector<int>> res;
        bool fromLeft = true;

        q.push(root);
        while(q.empty() != true)
        {
            int n = q.size();
            vector<int> level(n);

            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                int index = fromLeft ? i : n - i - 1;
                level[index] = node->val;
                
                if(node->left != nullptr)
                    q.push(node->left);

                if(node->right != nullptr)
                    q.push(node->right);    
            }

            fromLeft = !fromLeft;
            res.push_back(level);
        }

        return res;
    }
};
