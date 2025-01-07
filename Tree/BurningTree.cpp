// https://www.geeksforgeeks.org/problems/burning-tree/1

/*
TC - O(n)
SC - O(n)
*/

class Solution {
  public:
    Node* recordParents(Node* root, int &target, unordered_map<Node*, Node*> &parent) 
    {
        Node* targetNode = nullptr;
        queue<Node*> q;
        q.push(root);
        parent[root] = nullptr;
        
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            
            if(node->data == target)
                targetNode = node;
            
            if(node->left)
            {
                q.push(node->left);
                parent[node->left] = node;
            }
            
            if(node->right)
            {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
        
        return targetNode;
    }
    
    int minTime(Node* root, int target) {
        
        unordered_map<Node*, Node*> parent;
        Node* targetNode = recordParents(root, target, parent);
        
        // No such node found in tree with value target
        if(targetNode == nullptr)
            return -1;      
        
        int time = 0;
        unordered_set<Node*> visited;
        visited.insert(targetNode);
        queue<Node*> q;
        q.push(targetNode);
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                Node* node = q.front();
                q.pop();
                
                if(parent[node] != nullptr && visited.find(parent[node]) == visited.end())
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
                
                if(node->left != nullptr && visited.find(node->left) == visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                
                if(node->right != nullptr && visited.find(node->right) == visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }
            
            time++;
        }
        
        return time - 1;
    }
};
