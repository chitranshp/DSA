// https://leetcode.com/problems/crawler-log-folder/

// TC - O(n) as we are compairing for "../" and "./". Therefore dominant factor will be the loop which is of O(n)

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int dist = 0;
        stack<string> st;

        for(string &s: logs) {
            if(s == "../") {
                dist = max(dist - 1, 0);
                //If we want to print the current path as well
                // if(!st.empty()) {  
                //     st.pop();
                // }
            }
            else if(s != "./") {
                dist++;
                // st.push(s);
            }
        }

        return dist;
    }
};
