// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

// Approach 1: Floyd-Warshall algorithm
// TC - O(N ^ 3) & SC - O(N ^ 2)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distanceMatrix(n, vector<int> (n, 1e9));
        pair<int, int> smallestPair = {-1, 1e9};     // 1e9 indicates that no direct path

        // Graph is Bidirectional
        for(const vector<int> &edge: edges)
        {
            distanceMatrix[edge[0]][edge[1]] = edge[2];
            distanceMatrix[edge[1]][edge[0]] = edge[2];
        }

        // Sets distance to self as 0, previously it was set to 1e9 as part of initialization
        for(int i = 0; i < n; i++)
        {
            distanceMatrix[i][i] = 0;
        }

        // Calculate all pair shortest paths using Bellman ford algorithm
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    distanceMatrix[i][j] = min(distanceMatrix[i][j] , distanceMatrix[i][k] + distanceMatrix[k][j]);
                }
            }
        }

        // Iterate through updated distanceMatrix and find vertex satisfying given condition
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
             {
                if(i != j && distanceMatrix[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }

            if(cnt <= smallestPair.second)  // Update smallest pair if shorter or equal path is found 
            {
                smallestPair.first = i;
                smallestPair.second = cnt;
            }
        }

        return smallestPair.first;
    }
};

/*
Approach 2: All pairs shortest path using Dijkstra algorithm n times
TC - O(N * E * logN)
SC - O(V) + O(V + E)
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pair<int, int> smallestPair = {-1, 1e9};

        for(const vector<int> &edge: edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        // Apply Dijkstra's algorithm for each vertex to get all pairs shortest path
        for(int src = 0; src < n; src++)
        {
            fill(dist.begin(), dist.begin() + n, 1e9);  // Reset distance vector for next source
            dist[src] = 0;
            pq.push({dist[src], src});

            while(!pq.empty())
            {
                int node = pq.top().second;
                int dis = pq.top().first;
                pq.pop();

                for(const pair<int, int> &it: graph[node])
                {
                    int adjNode = it.first;
                    int edgeWt = it.second;
                    if(dis + edgeWt < dist[adjNode])
                    {
                        dist[adjNode] = dis + edgeWt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }

            }

            int cnt = 0;
            for(int destNode = 0; destNode < n; destNode++)
            {
                if(destNode != src && dist[destNode] <= distanceThreshold)
                {
                    cnt++;
                }
            }

            if(cnt <= smallestPair.second)  // Update smallest pair if shorter or equal path is found 
            {
                smallestPair.first = src;
                smallestPair.second = cnt;
            }
        }

        return smallestPair.first;
    }
};

// Further Optimization(Applicable for both approach 1 & 2) : When distance becomes more than threshold, we can set it as 1e9

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pair<int, int> smallestPair = {-1, 1e9};    // (city, number of reachable cities within threshold)

        // Building bidirectional adjacency list.
        for(const vector<int> &edge: edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        // Applying dijkstra algorithm for each vertex to get all pairs shortest path
        for(int src = 0; src < n; src++)
        {
            fill(dist.begin(), dist.begin() + n, 1e9);  // Reset distance vector for next source
            dist[src] = 0;
            pq.push({dist[src], src});

            while(!pq.empty())
            {
                int node = pq.top().second;
                int dis = pq.top().first;
                pq.pop();

                // Any nodes reachable from this path will have distance > threshold. And dist value has default value of 1e9
                if(dis > distanceThreshold)
                    continue;

                for(const pair<int, int> &it: graph[node])
                {
                    int adjNode = it.first;
                    int edgeWt = it.second;
                    if(dis + edgeWt < dist[adjNode])
                    {
                        dist[adjNode] = dis + edgeWt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }

            int cnt = 0;
            for(int destNode = 0; destNode < n; destNode++)
            {
                if(destNode != src && dist[destNode] <= distanceThreshold)
                {
                    cnt++;
                }
            }

            if(cnt <= smallestPair.second)  // Update smallest pair if shorter or equal path is found 
            {
                smallestPair.first = src;
                smallestPair.second = cnt;
            }
        }

        return smallestPair.first;
    }
};
  
