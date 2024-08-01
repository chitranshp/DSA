// https://leetcode.com/problems/number-of-senior-citizens/
// TC - O(n) & SC - O(1)

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        
        for(const string &detail: details)
        {
            int age = detail[11] - '0';
            age = (age * 10) + (detail[12] - '0');
            
            if(age > 60)
                res++;

            /*
            if(detail[11] > '6' || (detail[11] >= '6' && detail[12] >= '1'))
                res++;
            */
        }

        return res;
    }
};
