// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

/*
TC - O(nlogk) or O(nlogn) where k = number of unique horizontal distances and n = number of nodes. In worst case, n = k (ex. In skewed tree)
SC - O(nlogn)
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(root == nullptr)
            return {};
            
        vector<int> res;
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        while(!q.empty())
        {
            auto it = q.front();
            Node * node = it.first;
            int horizontalDist = it.second;
            q.pop();
            
            mpp.insert({horizontalDist, node->data});    // Allowed as map uses RBT internally. Same with unordered_maps as they use hashing. And hashing can be done on negative keys
            if(node->left != nullptr)
                q.push({node->left, horizontalDist - 1});
                
            if(node->right != nullptr)
                q.push({node->right, horizontalDist + 1});
        }
        
        for(auto &it: mpp)
        {
            res.push_back(it.second);
        }
        
        return res;
    }
};
