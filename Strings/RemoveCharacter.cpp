https://practice.geeksforgeeks.org/problems/remove-character3815/1?page=6&difficulty[]=-1&sortBy=submissions

class Solution {
  public:
    string removeChars(string string1, string string2) 
    {
        int *m = new int[26]();           
        int cnt = 0;
        
        for(int i = 0; i < string2.length(); i++)
            m[string2[i] - 'a'] = 1;
  
        string2 = "";
        for(int i = 0; i < string1.length(); i++)
        {
            if(m[string1[i] - 'a'] != 1)
                string2.push_back(string1[i]);
        }
        
        return string2;
    }
};