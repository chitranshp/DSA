// https://leetcode.com/problems/binary-tree-paths/submissions/885245137/

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
    void dfs(TreeNode* node, string path, vector<string> &allpaths)
    {
        if(node == nullptr)
            return;

        path += to_string(node->val);  

        if(node->left == nullptr && node->right == nullptr)
        {
            allpaths.push_back(path);
            return;
        }

        path += "->";             
        dfs(node->left, path, allpaths);
        dfs(node->right, path, allpaths);
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> allpaths;
        string path;
        dfs(root, path, allpaths);

        return allpaths;    
    }
};
