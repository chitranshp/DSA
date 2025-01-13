// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

/*
TC - Worst case in skewed tree O(n)
SC - O(1)
*/

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    Node* curr = root;
    int ceil = INT_MAX;
    while(curr != nullptr)
    {
        if(curr->data == input)
            return curr->data;
        else if(curr->data > input)
        {
            ceil = min(ceil, curr->data);
            curr = curr->left;
        }
        else 
        {
            curr = curr->right;
        }
    }
        
    return (ceil == INT_MAX)? -1: ceil;
}

// Approach 2: Same approach with removing redundant/unnecessary steps

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    Node* curr = root;
    int ceil = -1;                  // Default initialization for the case when ceil is not found. All values in tree are lesser then input
    while(curr != nullptr)
    {
        if(curr->data == input)
        {
          ceil = curr->data;
          break;
        }
        else if(curr->data > input)
        {
            ceil = curr->data;        // We are going down in the left subtree as seen in next step. So, all further values for curr are bound to have lesser value then curr->data
            curr = curr->left;
        }
        else 
        {
            curr = curr->right;
        }
    }
        
    return ceil;
}
