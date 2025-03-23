#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        
        // Build the graph
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }
        
        // Min-heap {time, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        // Start from node 0
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            auto [currTime, u] = pq.top();
            pq.pop();
            
            if (currTime > dist[u]) continue;
            
            for (auto [v, time] : graph[u]) {
                long long newTime = currTime + time;
                
                if (newTime < dist[v]) {
                    dist[v] = newTime;
                    ways[v] = ways[u];  // Reset ways to this new shortest path count
                    pq.push({newTime, v});
                } else if (newTime == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
