//https://leetcode.com/problems/longest-word-in-dictionary/
#include<bits/stdc++.h>

using namespace std;

void consider(string& a, string& answer)
{
    if(a.length() > answer.length())  //If the new word is longer then previous longest one
        answer = a;
    else if(a < answer)  
        answer = a;         //Stores the lexicographical smaller word in answer
}
string longestWord(vector<string>& words) {
    set<string> dictionary(words.begin(), words.end());
    set<string> Canbecreated;
    string answer;
    for(string s:dictionary)
    {
        if(s.length() == 1)
        {
            Canbecreated.insert(s);   
            consider(s, answer);
        }
        else
        {
            string shorten = s;
            shorten.pop_back();
            //If the shorten words is present in dicitonary(input) AND it can be created in the way described in problem
            if(dictionary.count(shorten) && Canbecreated.count(shorten))
            {
                Canbecreated.insert(s);
                consider(s, answer);
            }
        }
    }
    return answer;
}

int main()
{
    vector<string> words = {"b", "ba", "ban", "bana", "banan", "banana", "a", "app", "appl", "apple", "apply"};
    string result = longestWord(words);
    cout<<result;
    return 0;
}
