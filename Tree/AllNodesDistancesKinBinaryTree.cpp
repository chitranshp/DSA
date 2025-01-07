// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/*
Approach: 
  1. Convert tree into bidirectional graph and then solve
  2. Track and store parents in a map to allow O(1)  lookup time. Then use dfs/bfs to search all the nodes at target k

TC - O(n)
SC - O(n)
*/

class Solution {
public:
    unordered_map<int, TreeNode*> recordParents(TreeNode* root)
    {
        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> q;

        q.push(root);
        parent[root->val] = nullptr;

        while(!q.empty())
        {
            int n = q.size();
            TreeNode* node = q.front();
                
            q.pop();

            // No need to go level wise as we are just storing parents. Loop will be redundant
            if(node->left != nullptr)
            {
                q.push(node->left);
                parent[node->left->val] = node;
            }
            
            if(node->right != nullptr)
            {
                q.push(node->right);
                parent[node->right->val] = node;
            }
        }

        return parent;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // If we use TreeNode* it will reduce the dereferencing overhead and would even work in case when all nodes are not unique. But will take up more space for storing pointers(memory address) as compared to int.
        unordered_map<int, TreeNode*> parent = recordParents(root);    
        vector<int> res;
        queue<TreeNode*> q;

        int depth = 0;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);
        while(!q.empty() && depth <= k)
        {
            int n = q.size();
            //depth++;              // If we increment depth here only, for our target only depth will be updated as 1 which should be actually at 0
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(depth == k)
                    res.push_back(node->val);

                if(parent[node->val] != nullptr && visited.find(parent[node->val]) == visited.end())
                {
                    q.push(parent[node->val]);
                    visited.insert(parent[node->val]);
                }

                if(node->left != nullptr && visited.find(node->left) == visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right != nullptr && visited.find(node->right) == visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }

            depth++;
        }

        return res;
    }
};
