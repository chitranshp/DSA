// https://leetcode.com/submissions/detail/893537235/

class Solution {
public:
/*
First digit needs to be positive as per problem statement. Last digit sign is uncertain and depends on first digit.
Here there can be two possible cases
    Case - 1: Number of digits is even + - + -

    Case - 2: Number of digits is odd  + - +

To get the individual digits we have to go through Right to left.
So, we will try to utilize this one right to left iteration to get our required sum.
We will take last digit as -ve and take the sum for rest of the digits alternatively. This approach will yield the correct answer for Case -1 but for case 2 it will give the opposite answer. 
                    - + -      (As we are starting from last digit as -ve)

Whereas our correct answer should be + - +.
Therefore, to get sum as per problem statement we just multiply the resultant sum for Case with odd number of digits with as (-a + b -c) = +a -b + c

Now to calculate number of digits we can use a counter and check for even/odd or else we use this property:
        (-1)^n where n is any +ve even integer = +1
        (-1)^n where n is any +ve odd integer = -1

At the end, we return sum * n. 
*/

//TC O(n) SC O(1)
    int alternateDigitSum(int n) 
    {
        int sign = 1;
        int sum = 0;
        int i = 0;
        while(n)
        {
            sign *= -1;
            sum = sum + sign * (n % 10);
            n = n / 10;
        }    

        return sum * sign;
    }
};
