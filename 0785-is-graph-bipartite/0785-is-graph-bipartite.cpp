class Solution {
public:
    // Helper DFS function to color the graph
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int currColor) {
        color[node] = currColor;  // Assign current color to the node

        // Visit all neighbors of the current node
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];

            if (color[neighbor] == -1) {
                // If the neighbor hasn't been colored, give alternate color
                if (!dfs(neighbor, graph, color, 1 - currColor)) {
                    return false;  // Conflict found in recursion
                }
            } else if (color[neighbor] == currColor) {
                // If neighbor is already colored with same color, not bipartite
                return false;
            }
        }

        return true;  // All neighbors processed without conflict
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();  // Number of vertices in the graph
        vector<int> color(n, -1);  // Initialize all nodes with -1 (unvisited)

        // Graph may be disconnected, so check each component
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                // Start DFS from unvisited node with color 0
                if (!dfs(i, graph, color, 0)) {
                    return false;  // Found non-bipartite component
                }
            }
        }

        return true;  // All components are bipartite
    }
};
