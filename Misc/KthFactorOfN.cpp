// https://leetcode.com/problems/the-kth-factor-of-n/submissions/1537242193/

/*
Proof: Factors Come in Pairs
Definition of Factors: Suppose i is a factor of n. Then there exists an integer j such that: 𝑛 =𝑖 × 𝑗
Here, 𝑖 and j are called a factor pair.

Relating 𝑖 and j with n: There are two cases for any factor i:

Case 1:  𝑖 ≤ sqrt(n)
 
In this case,i is naturally within the range 1 to sqrt(n)

Case 2: 𝑖 > sqrt(n)
 
	If 𝑖 > sqrt(n), consider its paired factor j:

		𝑗 = 𝑛 / i
 
	Since 𝑖 > sqrt(𝑛), dividing n by i gives:

		𝑗 = 𝑛 / i < sqrt(n)
 
	Thus, j is less than n

Conclusion of the Proof: For every factor 𝑖 >sqrt(n), There is a corresponding factor 𝑗 < sqrt(n) such that 
					i×j=n.

Therefore: Every factor of n is part of a pair (𝑗,𝑖) where at least one of the factors (either j or 𝑖) is less than or equal to sqrt(n)

Thus, by iterating from 1 to sqrt(n), you are guaranteed to encounter at least one factor from every pair. This means you don’t need to check beyond sqrt(n)
​because any factor 𝑖 > sqrt(n) will have already been identified as 𝑛/j when j <= sqrt(n)

TC - O(sqrt(n))
SC - O(sqrt(n))
*/

class Solution {
public:
    int kthFactor(int n, int k) {
        int m = sqrt(n);
        vector<int> largeFactors;
        
        int cnt = 0;
        for(int i = 1; i <= m; i++)
        {
            if(n % i  == 0)
            {
                // Case: When both i and n/i are same, then dont count them twice. As it will be only one distinct factor
                // Ex. n = 4, 2 * 2 = 4
                if(i != n / i)
                    largeFactors.push_back(n/i);

                if(++cnt == k)
                    return i;
            }
        }

        // kth factor does not exist
        if(cnt + largeFactors.size() < k)
            return -1;

        // n = 4 (1 * 4, 2 * 2) , k = 3 which will be 4
        // 1, 2 will be covered in first for loop. Therefore, cnt = 2 4 will be stored in largeFactors
        // largeFactors {4} size = 1, (1 - (3 - 2)) = 0 which is the  index of 4 in largeFactors
        int pos = largeFactors.size() - (k - cnt);                  
        return largeFactors[pos];
    }
};
