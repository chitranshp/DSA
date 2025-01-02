// https://leetcode.com/problems/binary-tree-right-side-view/

/*
TC - O(nlogn) or O(nlogk)
SC - O(n)
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});
        while(!q.empty())
        {
            auto it = q.front();
            TreeNode *node = it.first;
            int verticalDist = it.second;
            q.pop();

            // If that verticalDist does not exist, insert it. Else skip          
            if(mpp.find(verticalDist) == mpp.end())
                mpp.emplace(verticalDist, node->val);

            // We are enqueuing the right node first. So, that first node, we encounter will be the rightmost one
            if(node->right != nullptr)
                q.push({node->right, verticalDist + 1});

            if(node->left != nullptr)
                q.push({node->left, verticalDist + 1});
        }
        
        for(auto &it: mpp)
        {
            res.push_back(it.second);
        }

        return res;
    }
};

/*
Optimal Approach: We will do level Order traversal. Each node which is last in the level will be the one seen from right.
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // If last node of a level
                if(i == n - 1)              
                    res.push_back(node->val);

                if(node->left != nullptr)
                    q.push(node->left);

                if(node->right != nullptr)
                    q.push(node->right);
            }
        }

        return res;
    }
};
