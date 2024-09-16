// https://leetcode.com/problems/minimum-time-difference

/*
TC - O(nlogn) + O(n)
SC - O(n)
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> convertedTime;

        for(string &str: timePoints) {
            int hh = stoi(str.substr(0, 2));
            int mm = stoi(str.substr(3, 2));
            int convTime = hh * 60 + mm;
            convertedTime.push_back(convTime);
        }

        sort(convertedTime.begin(), convertedTime.end());

        // Handles the cyclic nature of time
        convertedTime.push_back(1440 + convertedTime[0]);   // 00:35 also means 24 hours + 35 minutes

        int minDifference = INT_MAX;
        for(int i = 0; i < convertedTime.size() - 1; i++)
        {
            int timeDifference = abs(convertedTime[i] - convertedTime[i + 1]);
            minDifference = min(timeDifference, minDifference);
        }

        return minDifference;
    }
};
