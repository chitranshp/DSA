// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
TC - O(nlogk) where k is the number of unique horizontal distances(for map insertion). Total O(n) nodes will be traversed.
In worse case, O(nlogn) where k = n
SC - O(n) for queue, map and vector
*/

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    
    vector<int> topView(Node *root) {
        if(root == nullptr)
            return {};
            
        vector<int> res;
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        while(!q.empty())
        {
            Node* node = q.front().first;
            int horizontalDist = q.front().second;
            q.pop();
            // if(mpp.find(horizontalDist) == mpp.end())
            //     mpp.insert({horizontalDist, node->data});
            mpp.emplace(horizontalDist, node->data);        //Emplace will insert only if no such existing key is find in map
                
            if(node->left != nullptr)
                q.push({node->left, horizontalDist - 1});
                
            if(node->right != nullptr)
                q.push({node->right , horizontalDist + 1});
        }
        
        for(auto &it: mpp)
        {
            res.push_back(it.second);
        }
        
        return res;
    }
};
