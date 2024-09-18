// https://leetcode.com/problems/largest-number/

/*
Let there be k digits in each integer at average.
Therefore, conversion of vector array of strings will take O(n * k)
Sorting O(n log n) -> Each comparison will take O(k) as there are 2 strings of each k size. Total comparisons O(nlogn) and time for each comparison O(k).
Therefore, total sorting TC -> O(n * k logn) (O(nlogn) * O(k))

Accumulation -> O(n * k)

Total TC - O(n * k logn)
SC - O(n * k)
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        bool nonZeroPresent = false;
        
        for(int &num: nums)
        {
            // This logic can be skipped, if we check 0th index of sorted vector of strings.
            // if(num != 0)
            //     nonZeroPresent = true;
            
            numStrings.push_back(to_string(num));
        }

        // For case where nums = [0, 0] then result string will become "00" without this. Not for cases like [1, 0, 0] and result string "001" is not possible as per our logic
        // if(nonZeroPresent == false)
        //     return "0";        

        sort(numStrings.begin(), numStrings.end(), [&](string &a, string &b){
            return a + b > b + a;
        });

        // Only the case where all nums are 0, the resultant sorted string will have 0 at first index. ex "0000"
        if(numStrings[0] == "0")
            return "0";

        return accumulate(numStrings.begin(), numStrings.end(), string(""));;
    }
};
