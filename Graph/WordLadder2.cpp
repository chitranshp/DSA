// https://leetcode.com/problems/word-ladder-ii/

/*
The only trick here is that we do not have to delete a particular word immediately from the wordList even if during the replacement of characters it matches with the transformed word. Instead, we delete it after the traversal for that COMPLETE LEVEL when completed which allows us to explore all possible paths. This allows us to discover multiple sequences in order to reach the targetWord involving similar words. It's not possible that a path from same word at a later level will be shorter than the one's already in pipeline with that same word at earlier level. 

*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> res;
        queue<vector<string>> q;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> usedatlevel;
        int level = 0;

        q.push({beginWord});
        while(!q.empty())
        {
          vector<string> vec = q.front();     // Stores the parent transformation sequence
          q.pop();

           // For level 1, last element pushed in the queue will have 1 string. At each level, the size of vector<string> containing transformation sequences will increase by 1.
          // Now, erase all words that have been used in the previous levels to transform
          // If we are finding a transformation sequence(vector<string>) having 4 strings in it, in the front of queue. That means all the transformations upto level 3 are done now and level 4 transformation is about to start. At this point we can safely delete, all the words that have been already been used till level3.
           if (vec.size() > level)   
            {
                level++;        // Increment level.
                for (auto &it : usedatlevel)
                {
                    dict.erase(it);
                }

                usedatlevel.clear();    //To save space and skip needless iterations for next run.
            }

          string word = vec.back();
          if(word == endWord)
          {
            if(res.size() == 0)
              res.push_back(vec);
            else if(res[0].size() == vec.size())   // Compare the size  of new sequence(vector) with already found shortest sequence.
            {
              res.push_back(vec);
            }
          }
          
          for(int i = 0; i < beginWord.size(); i++)
          {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
              word[i] = ch;
              if(dict.count(word) > 0)
              {
                vec.push_back(word);    // Add transformed word to word sequence
                q.push(vec);
                usedatlevel.push_back(word);
                vec.pop_back();   // Restore word sequence for checking other characters at same index
              }

              word[i] = original; // Restore word to check at next indices
            }
          }
        }

        return res;
    }
};