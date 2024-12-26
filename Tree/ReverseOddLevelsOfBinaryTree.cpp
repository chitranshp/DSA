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

/*
Optimized DFS approach: Each node acts as root for the elements stored under it. So, we can use DFS to break down the problems and solve it using recursion.

Since the binary tree is perfect, it is symmetrical in nature. Therefore, to reverse the levels, we would want to swap the left value of the left child with the 
right value of the right child, and the right value of the left child with the left value of the right child.
Algorithm:
1. Call traverseDFS(root->left, root->child, level = 0)
    2. If either of left or right is null, return (Base case)
    3. For non null case, swap VALUES of left and right when level is even.
    4. Recursively call, traverseDFS(leftchild->left, rightChild->right) & traverseDFS(leftChild->right, rightChild->left)
    5. Continue untill all levels are traversed.
6. Return updated root.

TC - O(n) where n is number of nodes in tree
SC - O(h) where h is height of tree
*/

class Solution {
public:
    void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
        if(leftChild == nullptr || rightChild == nullptr)
            return;

        if(level % 2 == 0)
        {
            swap(leftChild->val, rightChild->val);
        }

        traverseDFS(leftChild->left, rightChild->right, level + 1);
        traverseDFS(leftChild->right, rightChild->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr)
            return root;

        traverseDFS(root->left, root->right, 0);
        return root;
    }
};


// BFS
/*
TC - O(n)
SC - O(n + 1/ 2) approx O(n) where n + 1/ 2 is the number of leaves in a perfect binary tree
*/

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr)
            return root;

        bool rev = false;
        queue<TreeNode*> q;
        q.push(root);

        while(q.empty() == false) 
        {
            vector<TreeNode*> levelNodes;
            int n = q.size();        // For processing one level at a time

            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                levelNodes.push_back(node);        // Stores all nodes for current level.

                if(node->left != nullptr)
                    q.push(node->left);

                if(node->right != nullptr)
                    q.push(node->right);
            }

            // Reverese values for all nodes at current level if it's odd.
            if(rev == true)
            {
                int left = 0, right = n - 1;
                while(left < right)
                {
                    swap(levelNodes[left]->val, levelNodes[right]->val);        // Just updating the values stored at those nodes. Leaving children unchanged.
                    left++;
                    right--;
                }
            }

            rev = !rev;
        }

        return root;
    }
};
