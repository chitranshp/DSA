// https://www.geeksforgeeks.org/problems/children-sum-parent/1

/*
TC - O(n)
SC - O(1)
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    
    
    int isSumProperty(Node *root)
    {
        if(root == nullptr)
            return 1;

        // Leaf Node
        if(!root->left && !root->right)
            return 1;
        
        
        int left = (root->left != nullptr) ? root->left->data: 0;
        int right = (root->right != nullptr)? root->right->data: 0;
        
        
        
        if(root->data == left + right)
            return isSumProperty(root->left) && isSumProperty(root->right);
            
        return 0;
    }
};
