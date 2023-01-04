// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
public:
    /*
    Since, this is a question for minimum rounds, we will try to include as many 3 rounds as possible first. After that only when no more 3 rounds can be done then we try for rounds with 2 tasks.

    Therefore, we will divide freq by 3 first and find out max 3 rounds that we can do.
    For [3] can't be done -> -1
    [2, 2] one round -> 1
    [2, 2, 2] one round -> 1

    when freq = 3 * k -> freq / 3  ex. freq = 6 rounds will be 2(3 + 3)
    when freq = 3 * k + 1 ex. 7 (3 + 2 + 2) 3 rounds or 10(3 + 3 + 2 + 2) 4 rounds where as 7/3 = 2(one round of 3 + second round of 3) 
    In this case that last round will be made up of two rounds each of 2 tasks. Therefore, we add 1 to the total to cover up for that extra round.

    when freq = 3 * k + 2 ex. 8(3 + 3 + 2) 11(3 + 3 + 3 + 2) 8/3 = 2 and 11/3 = 3. Here again on dividing by 3 we get the accurate number of rounds where 3 tasks are being done but we miss one last round where 2 tasks are being performed. Therefore, we again add an extra 1 to the total.

    To sum up
    freq : frequency of that task say, 7
    res: Number of min rounds required

    res = freq / 3;
    if(freq % 3 != 0)
        freq++;

    Or we can also replace it with one line
    res += (freq + 2) / 3  

    If it is 6 ie of form 3 * k, we will still get same result as freq / 3 as (6 + 2)/3 is also 2 in cpp
    If it is 7 ie of form 3 * k + 1. It will become 3*k + 3 = 3*(k + 1) which on divison by 3 will give k + 1 not k.
    If it is 8 ie of form 3 * k + 2, it will become 3*k + 5 = 3 * k + 3 + 2 which will also give k = 1 in end instead of k.
    */
    int minimumRounds(vector<int>& tasks) 
    {
        int res = 0;
        unordered_map<int, int> freq;
        //sort(tasks.begin(), tasks.end());  //O(nlogn)

        for(int &x: tasks)
            ++freq[x];

        for(auto &it : freq)                //O(n)
        {
            if(it.second == 1)
                return -1;
            
            /*
            res += (it.second / 3);
            if(it.second % 3 != 0)
                res += 1;
            */

            res += (it.second + 2) / 3;
        }

        return res;
    }

};

// O(1) SC but O(nlogn) TC
/*
class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        int freq = 0, res = 0;
        sort(tasks.begin(), tasks.end());
        for(int i = 0; i < tasks.size(); i++)
        {
            freq = 1;
            while( i < tasks.size() - 1 && tasks[i] == tasks[i + 1])
            {
                freq++;
                i++;
            }
            
            if(freq == 1)
                return -1;

            res += (freq / 3);
            if(freq % 3 != 0)
                res += 1;
        }

        return res;
    }

};

*/
