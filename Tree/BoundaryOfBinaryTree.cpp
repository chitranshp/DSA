// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/*
TC - O(n)
SC - O(h) + O(n) height of recursion stack + Extra vector for right boundary
*/

class Solution {
public:
    bool isLeaf(Node *curr)
    {
        return !curr->left && !curr->right;
    }
    
    void helperLeftBoundary(Node *curr, vector<int> &res)
    {
        while(curr)
        {
            if(!isLeaf(curr))
                res.push_back(curr->data);
                
            curr = curr->left? curr->left: curr->right;
        }
        
        return;    
    }
    
    void helperLeafBoundary(Node *curr, vector<int> &res)
    {
        if(curr == nullptr)
            return;
            
        if(isLeaf(curr))
        {
            res.push_back(curr->data);
            return;
        }
            
        helperLeafBoundary(curr->left, res);
        helperLeafBoundary(curr->right, res);
    }
    
    void helperRightBoundary(Node *curr, vector<int> &res)
    {
        vector<int> rightBoundary;
        while(curr)
        {
            if(!isLeaf(curr))
            {
                rightBoundary.push_back(curr->data);
            }
            
            curr = curr->right? curr->right: curr->left;
        }
        
        for(int i = rightBoundary.size() - 1; i >= 0; i--)
            res.push_back(rightBoundary[i]);
            
        return;
    }
    
    vector <int> boundary(Node *root)
    {
        if(!root)
            return {};
            
        Node* curr = root;
        vector<int> res;
        
        // If root is a leaf, it will be handled by helperLeafBoundary as it will be a leaf.
        if(!isLeaf(root))       
            res.push_back(root->data);
        
        
        helperLeftBoundary(curr->left, res);
        helperLeafBoundary(curr, res);
        helperRightBoundary(curr->right, res);
        return res;
    }
};

// Further improvement for right boundary helper function. Avoids revisiting entire tree and visits nodes only on right boundary
// SC - O(h)

    void helperRightBoundary(Node *curr, vector<int> &res)
    {
        if(curr == nullptr || isLeaf(curr))
            return;
            
        if(curr->right != nullptr)
            helperRightBoundary(curr->right, res);
        else
            helperRightBoundary(curr->left, res);
            
        res.push_back(curr->data);  // Uses recursion stack to reverse.
    }
