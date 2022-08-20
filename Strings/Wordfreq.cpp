/* https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings3528/1 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string mostFrequentWord(string arr[], int n)
    {
        unordered_map<string, int> count;
        int maxFreq = 0;
        string maxFreqWord;
        for(int i = 0; i < n; i++)
        {
            count[arr[i]]++;
            if(count[arr[i]] > maxFreq)
                maxFreq = count[arr[i]];
        }

        for(int i = 0; i < n; i++)
        {
            if(count[arr[i]] == maxFreq)
            {
                count[arr[i]]--;
                maxFreqWord = arr[i];
            }
        }
        return maxFreqWord;
    }
};

int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        std::ios::sync_with_stdio(false);
    #endif

    int t;  //No of test cases
    cin >> t;
    while (t--) 
    {
        int n;   //No of words
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];  //words

        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
