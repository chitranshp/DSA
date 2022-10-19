//leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int n = arr.size() - 1, shiftcount = count(arr.begin(), arr.end(), 0);
        for(int i = n; i >= 0; i--)
        {
            if(arr[i] == 0)
                shiftcount--;
            
            if(i + shiftcount <= n)
            {
                arr[i + shiftcount] = arr[i];
                if(i + shiftcount + 1 <= n && arr[i] == 0)
                    arr[i + shiftcount + 1] = 0;
            }
        }
    }
};
