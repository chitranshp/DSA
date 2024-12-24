// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/?envType=daily-question&envId=2024-12-20
/*
TC - O(N)  (Each nodes is being processed twice. Even reverse operation ammortized cost will be O(n) as it is being performed on levels. And both operations are sequential (reversal + tree updation)
SC -O(N)  (To store all nodes in nodesList vector) + O(W) width of binary tree (because of width of queue) approx equal to O(N)
*/

class Solution {
public:
    vector<int> helperLevelOrder(TreeNode* root)
    {
        vector<int> nodesList;
        queue<TreeNode*> q;
        q.push(root);

        bool rev = false;

        while(q.empty() == false)
        {
            int n = q.size();
            vector<int> levelNodes;

            for(int i = 0; i < n; i++)
            {
                TreeNode* node;
                node = q.front();
                q.pop();

                levelNodes.push_back(node->val);

                if(node->left != nullptr)
                    q.push(node->left);
                    
                if(node->right != nullptr)
                    q.push(node->right);
            }

            if(rev == true)
                reverse(levelNodes.begin(), levelNodes.end());

            nodesList.insert(nodesList.end(), levelNodes.begin(), levelNodes.end());
            rev = !rev;
            
        }

       return nodesList;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)
            return root;

        vector<int> nodesList = helperLevelOrder(root);
        queue<TreeNode*> q;
        q.push(root);

        for(int i = 0; i < nodesList.size(); i++)
        {
            TreeNode* node = q.front();
            q.pop();

            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;

            if(leftChild < nodesList.size())
            {
                node->left->val = nodesList[leftChild];
                q.push(node->left);
            }
            
            if(rightChild < nodesList.size())
            {
                node->right->val = nodesList[rightChild];
                q.push(node->right);
            }
        }

        return root;
    }
};
