// https://leetcode.com/problems/walking-robot-simulation/description/

/*
Approach 1: Similar time complexity as approach 2 due to set being the bigger factor.
*/
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int degree = 0;      // 0 N, 1 E, -1 W, 2 S
        long maxDist = 0;

        set<pair<int, int>> dict;
        for(vector<int> &obstacle: obstacles)
        {
            dict.insert({obstacle[0], obstacle[1]});
        }

        int x = 0, y = 0;

        for(int &command: commands)
        {
            long dist = 0;
            if(command < 0)
            {
                degree += (command == -1) ? 90: -90;
                degree = (degree + 360) % 360;
            }
            else 
            {
                if(degree == 0)
                {
                    for(int i = 1; i <= command; i++)
                    {
                        if(dict.find({x, y + 1}) == dict.end())
                            y++;
                        else 
                            break;
                    }
                }
                else if(degree == 90 || degree == -270)
                {
                    for(int i = 1; i <= command; i++)
                    {
                        if(dict.find({x + 1, y}) == dict.end())
                            x++;
                        else 
                            break;
                    }
                }
                else if(degree == 180 || degree == -180)
                {
                    for(int i = 1; i <= command; i++)
                    {
                        if(dict.find({x, y - 1}) == dict.end())
                            y--;
                        else 
                            break;
                    }
                }
                else if(degree == 270 || degree == -90)
                {
                    for(int i = 1; i <= command; i++)
                    {
                        if(dict.find({x - 1, y}) == dict.end())
                            x--;
                        else 
                            break;
                    }
                }

                dist = pow(x, 2) + pow(y, 2);
                maxDist = max(dist, maxDist);
            }


        }


        return maxDist;
    }
};

/*
TC - O(mlogm) + O(slogm) where m is number of obstacles and s is total number of steps across all command operations involving movement.
SC - O(m)
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int degree = 0;      // 0 N, 1 E, -1 W, 2 S
        long maxDist = 0;

        set<pair<int, int>> dict;    // Set uses comparison operators and binary search tree variant to store elements. Therefore can handle pairs
        for(vector<int> &obstacle: obstacles)
        {
            dict.insert({obstacle[0], obstacle[1]});
        }

        int x = 0, y = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int &command: commands)
        {
            long dist = 0;
            if(command < 0)
            {
                degree += (command == -1) ? 1: -1;
                degree = (degree + 4) % 4;      // Limits 0<= degree <= 3
            }
            else 
            {
                int step = 0;
                while(step < command)
                {
                    int nx = x + directions[degree].first, ny = y + directions[degree].second;
                    if(dict.find({nx, ny}) == dict.end())
                    {
                        x = nx;
                        y = ny;
                    }
                    else 
                        break;

                    step++;
                }

                dist = pow(x, 2) + pow(y, 2);
                maxDist = max(dist, maxDist);
            }
        }


        return maxDist;
    }
};

// Approach 2: Using unordered_set.
/*
Better average case insertion and lookup times. More memory overhead especially for larger inputs.
TC - O(m) + O(s)
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int degree = 0;      // 0 N, 1 E, -1 W, 2 S
        long maxDist = 0;

        unordered_set<string> dict;    //unordered_set supports string by default.
        for(vector<int> &obstacle: obstacles)
        {
            dict.insert(to_string(obstacle[0]) + " " + to_string(obstacle[1]));
        }

        int x = 0, y = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int &command: commands)
        {
            long dist = 0;
            if(command < 0)
            {
                degree += (command == -1) ? 1: -1;
                degree = (degree + 4) % 4;      // Limits 0<= degree <= 3
            }
            else 
            {
                int step = 0;
                while(step < command)
                {
                    int nx = x + directions[degree].first, ny = y + directions[degree].second;
                    string check = to_string(nx) + " " + to_string(ny);
                    if(dict.find(check) == dict.end())
                    {
                        x = nx;
                        y = ny;
                    }
                    else 
                        break;

                    step++;
                }

                dist = pow(x, 2) + pow(y, 2);
                maxDist = max(dist, maxDist);
            }
        }


        return maxDist;
    }
};
