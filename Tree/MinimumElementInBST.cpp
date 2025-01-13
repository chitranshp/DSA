// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

/*
TC - O(n) in worst case i.e. skewed binary tree
SC - O(1)
*/

class Solution {
  public:
    int minValue(Node* root) {
        while(root != nullptr && root->left != nullptr)
            root = root->left;
            
        return root->data;
    }
};
