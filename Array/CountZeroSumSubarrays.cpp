//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1?page=2&curated[]=1&sortBy=submissions
// TC O(n)

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) 
    {
        ll currsum = 0;
        int i, count = 0;
        unordered_map<ll, int> prefixsum;
        
        for(i = 0; i < n; i++)
        {
            currsum += arr[i];
            
            if(currsum == 0)
                count++;
            if(prefixsum.find(currsum) != prefixsum.end())
                count = count + prefixsum[currsum];
            prefixsum[currsum]++;
        }
        return count;
    }
};
