// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/


/*
TC - O(n) Each node is processed once and max recursion depth O(n) for skewed trees
SC - O(n)
*/
class Codec {
public:

    // Encodes a tree to a single string.
    // 1,2,null,null,3,4,null,null,5, null, null ,
    string serialize(TreeNode* root) {
        if(!root)
            return "null,";

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> stringQueue;
        string str = "";

        for(int i = 0; i < data.size(); i++)
        {
            if(data[i] == ',')
            {
                stringQueue.push(str);
                str = "";
                continue;
            }
            str += data[i];
        }

        // Non null tree Input will always have ',' in the end. So, all values will get processes inside for loop only
        // if(str != "")
        //     stringQueue.push(str);

        return deserializeHelper(stringQueue);
    }

    TreeNode* deserializeHelper(queue<string> &q)
    {
        if(!q.empty())
        {
            string val = q.front();
            q.pop();

            if(val == "null")
                return nullptr;

            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserializeHelper(q);
            root->right = deserializeHelper(q);
            return root;
        }

        return nullptr;
    }
};
