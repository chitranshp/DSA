// https://leetcode.com/problems/accounts-merge/

/*
Let V be the total number of accounts & E be the total number of mails across all accounts. 
1. First loop, O((V + E) * alpha(V)) (can be taken as O(V + E)) as we are iterating over all accounts and mapping for each mail
2. Next loop O(E) as we are just rearranging all the mails
3. If K is the avg size of mails for each account then O(V * KlogK) including sorting. This will be upper bounded by O(ElogE) as E = V * k(total number of edges across all nodes) and in worst case k = E

Total time complexity = O(V + E + E + ElogE) = O(ElogE)
Space complexity = O(V + E) (For disjoint set, it will be O(V))
*/

class DisjointSet 
{
    public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++)
        parent[i] = i;
    }
    
    int findParent(int x)
    {
        if(parent[x] == x)
        return x;
        return parent[x] = findParent(parent[x]);
    }
    
    void unionBySize(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);
        
        if(parentU == parentV)
            return;
        
        if(size[parentU] < size[parentV])
        {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else if(size[parentU] >= size[parentV])
        {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        
    return;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mapMailsToNodes;
        DisjointSet ds(n);

        for(int i = 0; i < accounts.size(); i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(mapMailsToNodes.find(mail) == mapMailsToNodes.end())
                {
                    mapMailsToNodes[mail] = i;
                }
                else
                {
                    ds.unionBySize(mapMailsToNodes[mail], i);
                }
            }
        }

        vector<string> mergedMails[n];          // Here, each mergedMails[i] represent total mail id's of user at index i of accounts
        for(const auto &it: mapMailsToNodes)
        {
            string mail = it.first;
            int indexOfMail = it.second;
            int parentNode = ds.findParent(indexOfMail);
            mergedMails[parentNode].push_back(mail);
        }


        vector<vector<string>> res;
        for(int i = 0; i < n; i++)
        {
            if(mergedMails[i].empty() == false)  // Nodes which are not ultimate parents will be empty in mergedMails
            {
                sort(mergedMails[i].begin(), mergedMails[i].end());

                vector<string> temp;
                temp.push_back(accounts[i][0]);     //storing userName
                for(string &s: mergedMails[i])
                    temp.push_back(s);

                res.push_back(temp);
            }
            
        }

        return res;
    }
};
