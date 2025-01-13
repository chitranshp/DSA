// https://www.geeksforgeeks.org/problems/floor-in-bst/1 

/*
TC - O(n) Due to worst case in skewed tree
SC - O(1) 
*/

public:
    int floor(Node* root, int x) {
        int floor = -1;
        
        while(root != nullptr)
        {
            if(root->data == x)
            {
                floor = root->data;
                break;
            }
            else if(root->data > x)
            {
                root = root->left;
            }
            else if(root->data < x)     // This will only run if root->data < x. 
            {
                // It will go down in right sub tree, therefore each next val is bound to be more than previous value but not more than x because of else if condition
                floor = root->data;
                root = root->right;
            }
        }
        
        return floor;
    }
};
