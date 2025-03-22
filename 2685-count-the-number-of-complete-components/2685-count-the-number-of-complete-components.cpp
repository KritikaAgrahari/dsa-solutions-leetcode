class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        // Construct adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;

        // Function to perform DFS and collect nodes in the component
        function<void(int, vector<int>&)> dfs = [&](int node, vector<int>& component) {
            visited[node] = true;
            component.push_back(node);
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, component);
                }
            }
        };

        // Traverse each node and find connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, component);

                // Check if the component is complete
                int size = component.size();
                int expectedEdges = size * (size - 1) / 2;
                int actualEdges = 0;

                for (int node : component) {
                    actualEdges += adj[node].size();
                }
                actualEdges /= 2; // Since edges are counted twice in undirected graph

                if (actualEdges == expectedEdges) {
                    count++;
                }
            }
        }

        return count;
    }
};
