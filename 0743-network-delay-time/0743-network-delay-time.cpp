class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Step 1: Create adjacency list
        unordered_map<int, vector<pair<int,int>>> adj;

        // Store graph as (neighbour, weight)
        for(int i=0;i<times.size();i++){

            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w});
        }

        // Step 2: Create Min Heap
        // Stores {distance, node}
        // Node having minimum distance comes first
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        // Step 3: Distance array
        vector<int> dist(n+1,INT_MAX);

        // Source node distance is 0
        dist[k]=0;

        // Push source node into heap
        pq.push({0,k});

        // Step 4: Run Dijkstra
        while(!pq.empty()){

            // Get node having minimum distance
            int d = pq.top().first;
            int node = pq.top().second;

            // Remove it from heap
            pq.pop();

            // Visit all neighbours
            for(int i=0;i<adj[node].size();i++){

                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;

                // If shorter path found
                if(d + weight < dist[neighbour]){

                    // Update distance
                    dist[neighbour]=d+weight;

                    // Push updated distance
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        // Step 5: Find maximum distance
        int ans=INT_MIN;

        for(int i=1;i<=n;i++){

            // If any node cannot be reached
            if(dist[i]==INT_MAX)
                return -1;

            ans=max(ans,dist[i]);
        }

        return ans;
    }
};