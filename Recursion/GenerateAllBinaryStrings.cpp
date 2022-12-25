// https://practice.geeksforgeeks.org/problems/generate-all-binary-strings/1

class Solution{
public:
    void generateBinaryStrings(int& num)
    {
        string str = "";
        helper(num, str, 0);
        return;
    }
    
    void helper(int &num, string& s, int index)
    {
        if(index == num)
        {
            cout<<s<<" ";
            return;
        }
        
        s += "0";
        helper(num, s, index + 1);
        s.pop_back();
        
        if(index > 0 && s[index - 1] == '1')
            return;
            
        s += "1";
        helper(num, s, index + 1);
        s.pop_back();
        
        return;
    }
};
