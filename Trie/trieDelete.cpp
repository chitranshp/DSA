/*       Deletion in Bottom-up recursive manner
When deleting a key in trie, one of following condiitons might arise
1. Key may not be present in trie. The operation must not modify trie.
2. Key is present as unique key(Does not include a prefix key nor a prefix of any other key)
Then, delete all the nodes.
3. Key to be deleted is the prefix of another long key. Then, just unmark the leaf node.
4. Key to be deleted has multiple keys as prefix. Start deleting from the end of the key till the first node which is leaf of another key.
*/


#include <bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

struct TrieNode
{
    struct TrieNode* Children[ALPHABET_SIZE];
    bool isEndofWord;
};

struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndofWord = false;

    for(int i = 0; i < ALPHABET_SIZE; i++)
        pNode->Children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->Children[index])
            pCrawl->Children[index] = getNode();

        pCrawl = pCrawl->Children[index];
    }
    pCrawl->isEndofWord = true;
}

bool searchNode(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->Children[index])
            return false;

        pCrawl = pCrawl->Children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndofWord);
}

//Returns true if root has no CHILDREN. Else return false.
bool isEmpty(struct TrieNode *root)
{
    for(int i = 0; i < ALPHABET_SIZE; i++)
        if(root->Children[i])
            return false;
    return true;
}


// Removes the key if it is present
struct TrieNode *remove(struct TrieNode *root, string key, int depth = 0)
{
    if(!root)
        return NULL;
    //For last char of the key,
    if(depth == key.length())
    {
        //Unmark as the end of the word
        if(root->isEndofWord)
         root->isEndofWord = false;
        
        //If key has no children(Not a prefix of any other word) then delete the node.
        if(isEmpty(root))
        {
            delete (root);
            root = NULL;
        }

        return root;            //Return
    }

    //If it's not the end of the word, then do call recursively for the child(next character in string) using depth as index
    int index = key[depth] - 'a';
    root ->Children[index] = remove(root->Children[index], key, depth + 1);

    //If root does not has any other child(It's only child got deleted) and is not end of word for any other prefix(Not a part of any other word) then delete the node.
    if ( isEmpty(root) && (root->isEndofWord = false))
    {
        delete (root);
        root = NULL;
    }
    return root;                //Return

}

int main()
{
       string keys[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    int n = sizeof(keys) / sizeof(keys[0]);
 
    struct TrieNode* root = getNode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // Search for different keys
    searchNode(root, "the") ? cout << "Yes\n" : cout << "No\n";
    searchNode(root, "these") ? cout << "Yes\n" : cout << "No\n";
 
    remove(root, "heroplane");
    searchNode(root, "hero") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
