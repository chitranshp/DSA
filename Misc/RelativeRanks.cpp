// https://leetcode.com/problems/relative-ranks/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size());
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }

        int place= 1;
        while(pq.empty() != true) {
            int index = pq.top().second;
            pq.pop();

            if(place > 3) {
                res[index] = to_string(place);
            }
            else if(place <= 3) {
                if(place == 1)
                    res[index] = "Gold Medal";
                else if(place == 2)
                    res[index] = "Silver Medal";
                else
                    res[index] = "Bronze Medal";
            }

            place++;
        }

        return res;
    }
};
