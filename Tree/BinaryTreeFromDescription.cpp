// https://leetcode.com/problems/create-binary-tree-from-descriptions/

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> getNode;
        unordered_map<int, bool> isChild;

        for(const vector<int> &vec: descriptions) 
        {
            if(getNode.count(vec[0]) == 0) // First check, if node is created(added to map) or not. If not, then create it and add it to map.
            {
                TreeNode *parent = new TreeNode(vec[0]);
                getNode[vec[0]] = parent;
            }
            
            if(getNode.count(vec[1]) == 0) // Repeat the same for child
            {
                TreeNode *child = new TreeNode(vec[1]);
                getNode[vec[1]] = child;
            }
            
            if(vec[2] == 1) // Depending on the child, add it to left or right of parent
            {
                getNode[vec[0]]->left = getNode[vec[1]];
            }
            else 
            {
                getNode[vec[0]]->right = getNode[vec[1]];
            }

            isChild[vec[1]] = true; // For each child node, mark it as a child using a separate map.
        }

        TreeNode* root = nullptr;
        for(const vector<int> &vec : descriptions)  // Iterate over PARENT of all individual description[i]. Node which is absent in isChild map will be the root
        {
            if(isChild[vec[0]] == false)
            {
                root = getNode[vec[0]];
                break;
            }
                
        }

        return root;
    }
};
