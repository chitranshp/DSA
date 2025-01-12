// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
Flatten the right subtree first, followed by left subtree
Then conncect the left most right child of left subtree to first node in right subtree and make the left child null
TC - O(n)
SC - O(n)
*/

/*
class Solution {
public:
    TreeNode* flattenHelper(TreeNode* root, TreeNode* prev) {
        if(root == nullptr)
            return nullptr;             

        if(root->right != nullptr)      // If we are not doing these nullchecks here before calling this function recursively, we need to return prev when root == null as to preserve last visited node in prev and not to get overwritten by null
            prev = flattenHelper(root->right, prev);        

        if(root->left != nullptr)
            prev = flattenHelper(root->left, prev);

        root->right = prev;
        root->left = nullptr;
        return root;    // Prev always maintains the last visited node which is the preorder successor of current node
    }
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        flattenHelper(root, prev);
        return;
    }
};
*/

class Solution {
public:
    TreeNode* flattenHelper(TreeNode* root, TreeNode* prev) {
        if(root == nullptr)
            return prev;     
      
        prev = flattenHelper(root->right, prev);        
        prev = flattenHelper(root->left, prev);

        root->right = prev;
        root->left = nullptr;
        return root;    // Prev always maintains the last visited node which is the preorder successor of current node
    }
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        flattenHelper(root, prev);
        return;
    }
};

// Recursion: Same approach using global variable
class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;

    }
};

// Iterative approach same logic
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;

        TreeNode* prev = nullptr, *curr = root;
        stack<TreeNode*> st;
        st.push(curr);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();

            if(node->right != nullptr)
                st.push(node->right);
            if(node->left != nullptr)
                st.push(node->left);

            node->left = nullptr;           // We can null it or remove this left child. As it is already stored it stack if it existed
            if(st.empty() == false)
            {
                node->right = st.top();
            }       
        }
        return;
    }
};

