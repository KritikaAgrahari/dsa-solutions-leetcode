class Solution {
public:

    // Helper function to check if the graph is bipartite using DFS
    bool checkBipartiteDFS(vector<int> adj[], int curr, vector<int>& color, int currColor) {
        color[curr] = currColor;  // Assign current node a color

        // Traverse all adjacent nodes of 'curr'
        for (int i = 0; i < adj[curr].size(); i++) {
            int v = adj[curr][i];  // Get the i-th neighbor of 'curr'

            if (color[v] == color[curr]) {
                // If the adjacent node has the same color as current, not bipartite
                return false;
            }

            if (color[v] == -1) {
                // If the adjacent node hasn't been colored yet
                int colorOfV = 1 - currColor;  // Alternate color

                // Recurse for the adjacent node
                if (checkBipartiteDFS(adj, v, color, colorOfV) == false) {
                    return false;  // If any branch fails, not bipartite
                }
            }
        }

        return true;  // All neighbors validated, return true
    }

    // Main function to check if graph is bipartite
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);  // Initialize all nodes with -1 (unvisited)

        // Try to color each component (graph may be disconnected)
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                // If node 'i' is uncolored, start DFS from it with color 1
                if (checkBipartiteDFS(adj, i, color, 1) == false) {
                    return false;  // If one component is not bipartite, return false
                }
            }
        }

        return true;  // All components are bipartite
    }
};
