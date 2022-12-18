// https://leetcode.com/problems/daily-temperatures/description/

//TC O(N) SC O(N)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        const int n = temperatures.size();
        vector<int> nwd(n, 0);      //We are already initializing it with 0's
        stack<int> s;

        for(int i = n - 1; i >= 0; i--)
        {
            while(!s.empty() && temperatures[i] >= temperatures[s.top()])
                s.pop();

            if(!s.empty())  
                nwd[i] = s.top() - i;
            
            s.push(i);          //Pushing index of day's not temperature
        }

        return nwd;
    }
};
