//https://leetcode.com/problems/happy-number/
/* Instead of slow and fast(Floyd's cycle finding alorithm), we could also have used unordered map. */

class Solution {
public:
    int findsum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += pow(n % 10, 2);
            n = n / 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) 
    {
        int slow = findsum(n);
        int fast = findsum(slow);
        
        while(fast != slow)                 //for 1 sum will also be one, so fast and slow will be same eventually
        {
            if(fast == 1)                   //Optional
                break;
            
            slow = findsum(slow);
            fast = findsum(findsum(fast));
        }
        
        return fast == 1;
    }
};
