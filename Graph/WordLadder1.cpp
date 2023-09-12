// https://leetcode.com/problems/word-ladder/

/*
We will be using BFS to solve this.

TC - O(wordListLength * wordLength * 26)     Assuming insertion, search, removal in unordered set have O(1) time complexity. Although in worst case due to rare collisions, it might be linear.

SC - O(2 * wordListLength) queue and set + O(wordLength)
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());   
        queue<pair<string, int>> q;

        q.push({beginWord, 1});         // A sequence with only beginWord will have 1 word. (Number of words not number of transformation steps)

        //This outer loop will run atmost DictionaryLength times, because a transformation is only pushed in queue if it exists in dictionary. And after each matching transformation, it is deleted from dictionary. So, that each word in dictionary will be visited in worst case.
        while(!q.empty() && dict.count(endWord) == 1)
        {
            string word = q.front().first;
            int seqLen = q.front().second;
            q.pop();

            // Erase the current word from set to avoid revisiting it. As we are using BFS, we are guarranted to reach the shortest path. So, revisiting an already visited node will never be required and deleting it will be more efficient.
            dict.erase(word);       // Except beginWord, all strings popped from queue will be present in end. And in case, beginWord is not in dict, then this will simply return false or 0.

            if(word == endWord)
                return seqLen;

            // O(WordLength * 26)
            for(int i = 0; i < beginWord.length(); i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;               // Modify the string
                    if(dict.find(word) != dict.end())
                    {
                        q.push({word, seqLen + 1});     // Only 1 char is changed
                    }

                    word[i] = original;         // Return the string to it's original value
                }
            }
        }

        return 0;      
    }
};