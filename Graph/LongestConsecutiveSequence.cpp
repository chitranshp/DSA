// https://leetcode.com/problems/longest-consecutive-sequence/

/*
Approach1: Using Sorting
TC - O(nlogn)
SC - O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();

        sort(nums.begin(), nums.end());

        int currentStreak = 1, maxStreak = 1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i + 1] == nums[i] + 1)
                currentStreak++;
            else if(nums[i] == nums[i + 1])
                continue;
            else
                currentStreak = 1;

            maxStreak = max(maxStreak, currentStreak);
        }

        return maxStreak;
    }
};

/*
Intuition: If we regard a consecutive sequence as a conected component (or a disjoint set), 
the problem becomes to get the size of largest connected component (or set).
Two nodes are connected if they are consecutive.

In disjoint set, we are tracking using the index of elements as elements have value in the range [-1e9, 1e9].
And to get, corresponding index of a value, we use a map to get it in constant time.

Note: This also handles duplicate cases like [0, 0, 1]. For first zero, it will store in map and check for 1.
And when zero is encountered for second time, it will be skipped as we have already calculated longest sequence involving zero.

The overall time complexity is the sum of these parts: O(n)+O(n⋅α(n))+O(n) which can be taken as O(n)
SC - O(n)

Optimal appoach: Another approach using hashset(unordered_set) is also possible.
*/

class UnionFind {
    private:
    vector<int> parent;
    vector<int> size;

    public:
    UnionFind(int n) 
    {
        size.resize(n, 1);  // Each node will have 1 member i.e. itself, therefore size of 1.
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

    // Size can be used directly to solve the problem
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

    int getMaxSize() 
    {
        int maxSize = 0;
        for(const int &s: size)
        {
            maxSize = max(s, maxSize);
        }

        return maxSize;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size() <= 1)
            return nums.size();

        int n = nums.size();
        unordered_map<int, int> valuesToIndex; //[value, index] To get corresponding index of nums[i] + 1 or nums[i] - 1, if found
        UnionFind uf(n);

        for(int i = 0; i < n; i++)
        {
            // If that element is already visited(We know which component it belongs to
            if(valuesToIndex.find(nums[i]) != valuesToIndex.end())
                continue;
                 
            // Check whether nums[i] + 1, has been visited, if yes merge both components
            if(valuesToIndex.find(nums[i] + 1) != valuesToIndex.end())
                uf.unionBySize(i, valuesToIndex[nums[i] + 1]);

            if(valuesToIndex.find(nums[i] - 1) != valuesToIndex.end())
                uf.unionBySize(i, valuesToIndex[nums[i] - 1]);

            valuesToIndex[nums[i]] = i;
        }

        return uf.getMaxSize(); // set having largest size will have most number of elements or longest consecutive sequence
    }
};
