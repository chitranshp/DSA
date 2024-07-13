// https://leetcode.com/problems/robot-collisions
// TC - O(nlogn) + O(n) 
// SC - O(n)

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ind(positions.size());
        vector<int> st;

        for(int i = 0; i < positions.size(); i++) 
        {
            ind[i] = i;     // These indexes represent the indexes for position, healths and directions
        }

        // Indirectly sorting positions using ind. After this, order of ind represent sorted positions.
        sort(ind.begin(), ind.end(), [&](int a, int b) {        // [&] capture clause ensures that, we can automatically capture variables in surrounding scope by reference.
           return (positions[a] < positions[b]);
        });

        for(int i : ind) 
        {
            if(directions[i] == 'R')    // If its going to right, push it to stack
            {
                st.push_back(i);
            }
            else if(directions[i] == 'L')
            {
                while(!st.empty() && healths[i] != 0)  // Check if there's a collision, If YES(stack is not empty) either all right going robots will get destroyed(stack gets empty) or this left going robots will get destroyed(health becomes 0)
                {
                    if(healths[st.back()] >  healths[i]) 
                    {
                        healths[st.back()]--;
                        healths[i] = 0;
                    }
                    else if(healths[st.back()] == healths[i])
                    {
                        healths[st.back()] = 0;
                        st.pop_back();
                        healths[i] = 0;
                    }
                    else 
                    {
                        healths[st.back()] = 0;   
                        st.pop_back();
                        healths[i]--;
                    }
                }
            }

        }

        vector<int> res;

        // All robots with non-zero healths are those who survived this movement sequence either with collison or without collision. We are using healths so that order is same as the orginial sequence of given positions.
        for(int h: healths)
        {
            if(h != 0)
            {
                res.push_back(h);
            }
        }

        return res;
    }

};
