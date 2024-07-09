// https://leetcode.com/problems/average-waiting-time/

class Solution {
public:
    // wt = completionTimeished - arrival = (currentTime + cook)
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime = customers[0][0], arr = 0, completionTime = 0;
        double avgwt = 0, totalWtTime = 0;

        for(vector<int> &vec: customers) {
            if(currentTime < vec[0]) {
                currentTime = vec[0];
            }

            completionTime = currentTime + vec[1];
            totalWtTime += (completionTime - vec[0]);
            currentTime = completionTime;
        }

        avgwt = totalWtTime / customers.size();
        return avgwt;
    }
};
