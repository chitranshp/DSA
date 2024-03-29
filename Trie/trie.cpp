#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;

struct trienode
{
    struct trienode *children[ALPHABET_SIZE];
    bool isendofword;    
};

//Returns a new node which is initialize to NULLs.
struct trienode *getnode(void)
{
    struct trienode *pnode = new trienode;
    pnode->isendofword = false;
    
    for(int i = 0; i < ALPHABET_SIZE; i++)
        pnode->children[i] = NULL;

    return pnode;
}

//If key is not present, It will insert it. Else if, it's present as prefix of any other word in trie then it will mark endofword as True for last letter.
void insert(struct trienode *root, string key)
{
    struct trienode *pcrawl = root;
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(!pcrawl->children[index])
            pcrawl->children[index] = getnode();

        pcrawl = pcrawl->children[index];
    }
    pcrawl->isendofword = true;
    
}

bool search(struct trienode *root, string key)
{
    struct trienode *pcrawl = root;
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(!pcrawl->children[index])
            return false;
        
        pcrawl = pcrawl->children[index];
    }
    return (pcrawl->isendofword);
}

int main()
{
    string keys[] = {"the", "they", "them", "their", "a", "answer", "any"};
    int n = sizeof(keys)/sizeof(keys[0]);
    //Constructing Trie
    struct trienode *root = getnode();
    
    //Inserting keys
    for(int i = 0; i < n; i++)
        insert(root, keys[i]);
    
    search(root, "the")? (cout << "Yes\n") : (cout << "No\n");
    search(root, "a")? (cout << "Yes\n") : (cout << "No\n");
    search(root, "answer")? (cout << "Yes\n") : (cout << "No\n");
    search(root, "answe")? (cout << "Yes\n") : (cout << "No\n");
    return 0;
}
