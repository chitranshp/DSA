// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

/*
Recursion + Backtracking
TC - O(n) as each node is processed once
SC - O(h + L) h is height of tree(recursion stack) and L is the total number of nodes from root to leaves across all paths
*/

class Solution {
  public:
    void findPaths(Node* root, vector<int> &path, vector<vector<int>> &res)
    {
        if(root == nullptr)
            return;
        
        // If current node is a leaf
        if(root->left == nullptr && root->right == nullptr)
        {
            path.push_back(root->data);     // Save it in current path
            res.push_back(path);
            path.pop_back();                // Backtrack
            return;
        }
        
        path.push_back(root->data);
        findPaths(root->left, path, res);
        findPaths(root->right, path, res);
        path.pop_back();                    // Backtrack
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        vector<int> path;
        findPaths(root, path, res);
        return res;
    }
};
