// https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    //O(n! * n + n!(log n!))
    void generatepermutation(vector<string>& temp, string& num, int index)
    {
        if(index >= num.size())         //O(n) to make a deep copy
        {
            temp.push_back(num);
            return;
        }

        for(int i = index; i < num.size(); i++) 
        {
            swap(num[index], num[i]);
            generatepermutation(temp, num, index + 1);
            swap(num[index], num[i]);
        }
    }

    string getPermutation(int n, int k) 
    {
        string num;
        vector<string> temp;
        for(int i = 0; i < n; i++)
            num.push_back(i + '1');
        
        generatepermutation(temp, num, 0);
        sort(temp.begin(), temp.end());

        return temp[k - 1];
    }
};
