// https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    void dfs(vector<vector<int>> &rooms, int source, vector<bool> &visited)
    {
        visited[source] = 1;
        for(int node : rooms[source])
        {
            if(!visited[node])
                dfs(rooms, node, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        vector<bool> visited(rooms.size(), 0);
        int source = 0;
        dfs(rooms, source, visited);

        for(int i = 0; i < visited.size(); i++)
            if(!visited[i]) 
                return false;

        return true;
    }
};
