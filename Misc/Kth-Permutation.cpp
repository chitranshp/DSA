// https://leetcode.com/problems/permutation-sequence/submissions/887530173/

// TC O(n^2) SC O(n)
class Solution {
public:
    //
    string getPermutation(int n, int k) 
    {
        int fact = 1, index = 0;
        vector<int> numbers;     //This is 0-indexed. 
        string result;

        for(int i = 1; i < n; i++)      //For n, we need the value of (n - 1)! to find the respective block
        {
            fact *= i;                          
            numbers.push_back(i);
        }
        numbers.push_back(n);           //To append the last number

        k = k - 1;              //To handle number being 0-indexed. If n = 4 and k = 24, 24/(4 - 1)! will be 4(Out of bound). Therefore decrementing k by 1.
        while(numbers.size() != 0)      
        {
            index = k / fact;               // If k = 15, 15/3! = 2 we get the 2nd block(0 - indexed) ie 15 = 6 * 2 + 3
            result.push_back(numbers[index] + '0');

            k = k % fact;                   // We already know it's in 2nd block. Therefore, updating it for next iteration i.e. Inside 2nd block what's left. (15 % 6 = 3)
            // erase has TC of O(n)
            numbers.erase(numbers.begin() + index);     //numbers size will be decreased by 1.
            if(numbers.size() != 0)                     //To avoid division by zero.
                fact = fact / numbers.size();       // 10! / 10 = 9 or 3! / 3 = 2!
        }                                               //Total TC O(n^2)

        return result;
    }
};



//Recursion and Backtracking - Gives TLE
/*
class Solution {
public:
    //O(n! * n + n!(log n!))
    void generatepermutation(vector<string>& temp, string& num, int index)
    {
        if(index >= num.size())         //O(n) to make a deep copy
        {
            temp.push_back(num);
            return;
        }

        for(int i = index; i < num.size(); i++) 
        {
            swap(num[index], num[i]);
            generatepermutation(temp, num, index + 1);
            swap(num[index], num[i]);
        }
    }

    string getPermutation(int n, int k) 
    {
        string num;
        vector<string> temp;
        for(int i = 0; i < n; i++)
            num.push_back(i + '1');
        
        generatepermutation(temp, num, 0);
        sort(temp.begin(), temp.end());

        return temp[k - 1];
    }
};

*/
