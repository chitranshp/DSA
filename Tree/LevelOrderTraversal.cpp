// https://practice.geeksforgeeks.org/problems/level-order-traversal/1

/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*> q;
      vector<int> res;
      
      if(node == nullptr)
        return res;
    
      q.push(node);
      while(!q.empty())
      {
          Node* curr = q.front();
          res.push_back(curr->data);
          q.pop();
          
          if(curr->left != nullptr)
            q.push(curr->left);
          if(curr->right != nullptr)
            q.push(curr->right);
      }
      
      return res;
    }
};
