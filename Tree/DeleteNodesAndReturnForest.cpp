// https://leetcode.com/problems/delete-nodes-and-return-forest
// TC - O(n) stack size in worst case(skewed tree)
// SC - O(n) + O(m) where m is size 0f delete vector

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
    TreeNode* helper(TreeNode* node, unordered_set<int>& us, vector<TreeNode*>& result, bool isRoot) {
        if(node == nullptr)
            return nullptr;

        bool deleted = us.count(node->val); 

        // If it's a root and not going to be deleted, store it in result. As it will then remain a root.
        // We ONLY need to RETURN the ROOTS of remaining forest, not the entire forest.
        if(isRoot == true && deleted == false) {
            result.push_back(node);
        }

        // Here, we are using preorder. But as it is mentioned, there is not restriction of the order. We can also use inorder or postorder.
        node->left = helper(node->left, us, result, deleted);
        node->right = helper(node->right, us, result, deleted);

        return deleted == true? nullptr: node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> us(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        bool isRoot = true;

        if(root == nullptr)
            return {};

        helper(root, us, result, isRoot);
        return result;
    }
}; 

// Alternate appraoch: Same complexity just without extra flag variable for root tracking

class Solution {
public:
    TreeNode* helper(TreeNode* node, unordered_set<int>& us, vector<TreeNode*>& result) {
        if(node == nullptr)
            return nullptr;

        bool deleted = us.count(node->val); 
        node->left = helper(node->left, us, result);
        node->right = helper(node->right, us, result);

        if(deleted == true) {
            if(node->left != nullptr) {
                result.push_back(node->left);
            }
            
            if(node->right != nullptr) {
                result.push_back(node->right);
            }
            return nullptr;
        }

        return node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> us(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;

        if(root == nullptr)
            return {};

        if(us.count(root->val) == 0) {
            result.push_back(root);
        }

        helper(root, us, result);
        return result;
    }
}; 




