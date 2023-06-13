/*
Map in c++ is implemented by a Red Black tree, which is an essential balanced binary search tree. It is not a hash table, so it doesn't need that the key is hashable. However, it requires that the key support <, >, or == operations.
So for the map in c++, we can use a vector as key. 

But unordered_map doesn't compares key with any operator it just matches hash value. 
Same is required for vectors and pairs, if we are using them as key for unordered_map. 
But hash function is not defined for them in internal implementation of unordered_map. 
If we want to use them, we are free to create and use our own hash function.

TC - O(m * n * logn)
SC - O(k * logn + logm) where k is the number of distinct vectors
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        map<vector<int>, int> freq;     // This is implemented using BST in cpp (RBT to be spcific)
        int cntPairs = 0;

        for(int i = 0; i < grid.size(); i++)    // O(m * logn)  n - > number of elements in a row, m -> number of columns
            freq[grid[i]]++;    

        for(int j = 0; j < grid[0].size(); j++)     // O(m)
        {
            vector<int> temp;
            for(int i = 0; i < grid.size(); i++)    // O(n)
                temp.emplace_back(grid[i][j]);

            // We are counting number of pairs not total number. If there are two rows with same values as col[j]. This means there are two pairs.

            // In this we are inserting the whole column in map which is an expensive operation especially for large vectors which is not exactly needed
            // cntPairs += freq[temp];

            auto it = freq.find(temp);          // O(logn) as it uses BST
            if(it != freq.end())
                cntPairs += it->second;
        }

        return cntPairs;
    }
};