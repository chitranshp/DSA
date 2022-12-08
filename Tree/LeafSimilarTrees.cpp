// https://leetcode.com/problems/leaf-similar-trees/description/

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

//DFS using stack. Maximum space complexity will be O(h) height of tree and TC will be O(n). No extra loop for comparison.
class Solution {
public:

    int dfs(stack<TreeNode*> &s)
    {
        while(true)                         //It will loop untill it founds a leaf;
        {
            TreeNode* tempNode = s.top();
            s.pop();

            if(tempNode->left)
                s.push(tempNode->left);
            if(tempNode->right)
                s.push(tempNode->right);            //Right node will be at top of stack for next iteration. So, it will do a dfs from right to left.
            if(!tempNode->left && !tempNode->right)
                return tempNode->val;
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        stack<TreeNode*> s1, s2;
        s1.push(root1);
        s2.push(root2);
        
        while(!s1.empty() && !s2.empty())
        {
            if(dfs(s1) != dfs(s2))
                return false;
        }
        
        return (s1.empty() && s2.empty());
    }
};


// Recursion bases Inorder traversal and Vector for storing leaf nodes.

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

    void generateLeafseq(TreeNode* root, vector<int> &vec)
    {
        if(!root)
            return;

        generateLeafseq(root->left, vec);

        if(!root->left && !root->right)
            vec.push_back(root->val);

        generateLeafseq(root->right, vec);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> seq1;   //For storing leaf nodes of tree1. (maximum number of leaves in a B tree is (n + 1)/2.
        vector<int> seq2;   //For storing leaf nodes of tree2. 

        generateLeafseq(root1, seq1);
        generateLeafseq(root2, seq2);

        
        if(seq1.size() != seq2.size())
            return false;

        int i = 0, j = 0;

        for(i = 0, j = 0; i < seq1.size() && j < seq2.size(); i++, j++)
        {
            if(seq1[i] != seq2[j])
                return false;
        }

        return i == j;
    }
};
