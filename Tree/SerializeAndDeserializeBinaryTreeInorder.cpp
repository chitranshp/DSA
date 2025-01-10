// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/*
TC - O(n)
SC - O(n) 
*/

class Codec {
public:

     // Encodes a tree to a single string.
     string serialize(TreeNode* root) {
        if(root == nullptr)
            return "[]";

        string serializedString = "[", nullstring = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr)
            {
                // Don't push null immediately. Save it untill we encounter a non-null node along with a trailing ','
                nullstring += "null,";
            }
            else 
            {
                // When a non-null node is encountered, push the saved null nodes and reset nullstring for next iteration
                if(!nullstring.empty())
                {
                    serializedString += nullstring;
                    nullstring = "";
                }

                // Push the non null node value and add a trailing ','
                serializedString += to_string(node->val) + ",";

                q.push(node->left);
                q.push(node->right);
            }
        }

        // If it reaches here, means it is already a non null string with atleast 1 integer node value. All integer node values have a trailing ','. 
        // If string only has all 'null' means it is empty tree and won't be reaching here
        serializedString.pop_back();
        serializedString.push_back(']');
        
        return serializedString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // "[]"
        if(data.size() <= 2)
            return nullptr;

        // This converts the given string data into a queue of string where each string represents one node
        queue<string> stringQueue;
        string str = "";

        for(int i = 1; i < data.size() - 1; i++)
        {
            // ',' is the delimmiter. If we reach a ',' means we have read and stored one node value and that can be pushed stringQueue
            // Hint: data is of the form "1234,null,32,1". Each node can have multiple characters and they are taken together formed a string and then pushed
            if(data[i] == ',')   
            {
                stringQueue.push(str);
                str = "";
            }
            else
                str += data[i];
        }
        stringQueue.push(str);  // Pushing last saved node as string in string Queue

        // This part uses that queue of string and converts it into a tree, by treating it as level order traversal result
        queue<TreeNode*> nodeQueue;
        int rootval = stoi(stringQueue.front());
        stringQueue.pop();

        TreeNode* root = new TreeNode(rootval);
        nodeQueue.push(root);
        while(!nodeQueue.empty())
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if(!stringQueue.empty())
            {
                if(stringQueue.front() != "null")
                {
                    node->left = new TreeNode(stoi(stringQueue.front()));
                    nodeQueue.push(node->left);
                }

                stringQueue.pop();
            }
            
            if(!stringQueue.empty())
            {
                if(stringQueue.front() != "null")
                {
                    node->right = new TreeNode(stoi(stringQueue.front()));
                    nodeQueue.push(node->right);
                }
                stringQueue.pop();
            }
        }

        return root;
    }
};
