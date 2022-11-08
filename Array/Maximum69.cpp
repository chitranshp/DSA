// https://leetcode.com/problems/maximum-69-number/

class Solution {
public:
    int maximum69Number (int num) 
    {
        //int i = 0, temp = num;
        int FirstSixIndex = -1;      //from left

        for(int i = 0, temp = num; temp != 0; temp /= 10, i++)
            if(temp % 10 == 6)
                FirstSixIndex = i;

/*
        while(temp) 
        {
            if (temp % 10 == 6)      //last six from right, will be 1st from left
                FirstSixIndex = i;
            
            i++;
            temp /= 10;
        }
*/

        return (FirstSixIndex == -1)? num : num + 3 * pow(10, FirstSixIndex);
    }
};
