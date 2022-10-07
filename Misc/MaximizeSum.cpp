// https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1 
    
public:
    int Maximize(int a[],int n)
    {
        unsigned int res = 0;
        sort(a, a + n);
        int mod = pow(10, 9) + 7;
        for(int i = 0; i < n; i++)
        {
            res = res + a[i] * i;
            res = res % mod;
        }
        
        return res;
        
    }
};