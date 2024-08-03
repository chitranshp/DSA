/*
Simple Dijkstra's algorithm can indeed fail in scenarios where there is a constraint on the number of stops because it prioritizes minimizing cost without considering the number of stops. This can lead to situations where paths with fewer stops and higher costs are chosen over potentially cheaper paths that require more stops, which might prevent finding the optimal solution within the stop constraints.

Modified BFS:
Priority on Stops: Modified BFS prioritizes paths based on the number of stops, processing nodes level-by-level. This means that nodes with fewer stops are processed first, ensuring that all paths up to the maximum allowed stops are explored.
Queue Behavior: By using a queue, you ensure that paths are explored in order of their number of stops. Even if a path with a higher cost but fewer stops reaches an intermediate node first, paths with more stops but potentially lower cost will still be processed because they will be enqueued with the correct stop count and cost. Even a priority queue will work but it is not required as going level wise vs picking minimum level is somewhat similar and wont give any additional advantages but will add an extra cost.
Path Updates: Paths with fewer stops are processed first, but paths with more stops can still be enqueued and processed if they offer a lower cost to the destination. The queue ensures that all possible paths within the stop limit are considered, and the cost is updated appropriately.

TC - Each node can be dequeued k + 1 times(stops <= k). We can think that each node can be placed between 1 to k + 1 th position.
and every time a node is dequeued, each of it's neighbour will get enqueued. The number of neighbours are dependednt
on number of edges. So, total time complexity of loop wil be O((k + 1) * (m + n))
TC - O((k + 1) * (m + n))
SC - O(m + n)
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        queue<pair<int, pair<int, int>>> q;
        vector<int> price(n, INT_MAX);

        for(vector<int> &flight: flights) 
        {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        price[src] = 0;
        q.push({0, {src, price[src]}});     // stops, {node, price[node]}

        while(!q.empty())
        {
            int node = q.front().second.first;
            int currentPrice = q.front().second.second;
            int stops = q.front().first;
            q.pop();
            
            // Helps in terminating loop when all possible paths within k stops have been explored
            // As path with more stops will keep getting dequeued without enquing another node.
            if(stops > k)
                continue;       // No need to explore this path any further, but explore other potential paths in queue.

            for(const pair<int, int> &it: graph[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;
                if(currentPrice + edgeWt < price[adjNode])
                {
                    // If k = 1 and we are at our first stop, then there is a chance that next stop will be dst.
                    if(stops <= k)
                    {
                        price[adjNode] = currentPrice + edgeWt;
                        q.push({stops + 1, {adjNode, price[adjNode]}});
                    }
                }
            }
        }

        //Return price only after exploring all possible paths within k stops from source.
        return price[dst] == INT_MAX? -1: price[dst];
    }
};
