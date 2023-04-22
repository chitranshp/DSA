// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

/*
    Two matrices A1 and A2 of dimensions [p x q] and [r x s] can only be multiplied if and only if q=r
    The total number of multiplications required to multiply A1 and A2 are: p*q*s
    
        Number of matrices = n - 1 = 4
        Size of arr = n = 5
                0   1 2  3  4
                40 20 30 10 30
        matrix      1  2  3 4
        Dimensionos of matrix i= arr[i - 1] * arr[i]
        
        Here we have to partition the given matrix chain in such a way that on multiplication we get minimum number of multiplicatins.
        This is a problem of parition DP. Steps to solve such a problems are as follows:
            Start with the entire block/array and mark it with i,j. We need to find the value of f(i,j).
            Try all partitions.
            Run the best possible answer of the two partitions ( answer that comes after dividing the problem into two subproblems and solving them recursively).
            
            
        For parition (helper) function, the first index where we can create a partition is 1 not 0, as
        matrix 1 has size given by arr[0] * arr[1]. So, if we create a parition at index 0, we will be getting an
        invalid matrix.
        Whereas for partition at 1, we will get two groups of matrices one with i = 0 and k = 1 i.e. matrix 1 and the
        another partition being matrix 2 to matrix 4(arr[2] to arr[5])
        
        Similarly if partition index == n - 1 = 4, this will give invalid matrix from arr[0] to arr[3] and arr[4] alone in other
        partition. arr[4] the 2nd dimension of matrix 4(last matrix).      (n - 1 is the last index as per 0-indexing)  
        Therefore, partition index can be any index in the range 1 to n - 2. (Both inclusive)

                        0 1 2 3 4
        Matrix            A B C D
                    
                    (A)(BCD)    (AB)(CD)  (ABC)(D)
                   1to1 2to4   1to2 3to4 1to3 4to4
                   for k -> i to j - 1 where j = n - 1. Initial fun call will be f(i:1, j: n - 1)
                  1tok k+1to4  1tok k+1to4  1toK k+1to4
                    k = 1        k = 2          k = 3

        
        Base case - When i == j
        (Note: Dimensions of given matrix is given by matrix[i - 1] * matrix[i])
        If i == j, that means single matrix is left.
        Cost of multiplying single matrix is 0. As we don't need to multiply a sinlge matrix element
        Multiplication requires atleast 2 elements as it is a binary operator.
        
        Note: Cost of multiplying 2 matrices a with size m * k and b with size k * n = m * k * n. 
        (First dimension of 1st matrix * 2nd dimension of first matrix/1st dimension of 2nd matrix * 2nd dimension of 2nd matrix)
        
        
        With Plain recursion 
        TC - Exponential
        SC - O(n)
        
        With memoization - There are n * n states. But inside the helper loop there is another loop running from k = i to j - 1.
        In worst case that will run about n - times.
        TC approx. O(n * n * n)
        SC - O(n ^ 2) + O(n)
        
        1
*/

class Solution{
public:
    int helper(int n, int arr[], int i, int j, vector<vector<int>> &dp)
    {
        //No multiplication required as only 1 matrix is there
        if(i == j)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int steps = 0;
        int mini = INT_MAX;
        
        // k -> [1, n - 2] as k < j and j = n - 1.
        for(int k = i; k < j; k++)
        {
            steps = helper(n, arr, i, k, dp) + helper(n, arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
            mini = min(mini, steps);     //We are storing for what value of k, we are getting minimum steps for multiplication.
            //And each k, divides the given matrix chain into 2 partition.
            //So, basically we are returning the partition for which we are getting minimum number of steps.
        }
        
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int> (N, -1));
        
        // From 1 to n - 1. 
        return helper(N, arr, 1, N - 1, dp);
    }
};

/*
TC - O(n * n * n)
SC - O(n * n)
*/

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        //Base case will be handled here dp[i][i] = 0 where 0 <= i < n
        vector<vector<int>> dp(N, vector<int> (N, 0));
        int steps = 0, mini = INT_MAX;
        
        for(int i = N - 1; i >= 1; i--)
        {
            // (k < j and k = i to j therefore i < j)i < j which means j > i or j can have values ranging from i + 1 till end(N - 1)
            // i will always left of j unless matrix formed will be invalid
            // In recursion i goes from 0 to 1 and j goes from N - 1 to lower bound(2).
            // Therefore in bottom up i will go from N - 1 to 1 and j will go in reverse
            for(int j = i + 1; j < N; j++)
            {
                int val = 0;
                int mini = INT_MAX;
                
                for(int k = i; k < j; k++)
                {
                    val = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    mini = min(val, mini);
                }
                
                dp[i][j] = mini;
            }
        }
        // From 1 to n - 1. 
        return dp[1][N - 1];
    }
};