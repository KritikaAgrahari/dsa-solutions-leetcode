class Solution {
public:
    // Flag to check if there is a cycle in the graph
    bool hasCycle = false;

    // Depth-First Search function to explore the graph and perform topological sorting
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {
        visited[u] = true;        // Mark current node as visited
        inRecursion[u] = true;    // Mark node as part of the current recursion stack (for cycle detection)

        // Explore all adjacent nodes of 'u'
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];    // Get the i-th adjacent node

            if (inRecursion[v] == true) {  // If the adjacent node is already in the recursion stack → cycle found
                hasCycle = true;
                return;
            }

            if (!visited[v]) {    // If the adjacent node hasn't been visited yet
                DFS(adj, v, visited, st, inRecursion);  // Recursively call DFS on the adjacent node
            }
        }

        // After visiting all children, push current node onto the stack
        st.push(u);

        // Mark this node as no longer in the recursion stack
        inRecursion[u] = false;
    }

    // Main function to find topological order of courses
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;           // Adjacency list for representing the graph
        vector<bool> visited(numCourses, false);       // Tracks visited nodes
        vector<bool> inRecursion(numCourses, false);   // Tracks nodes in the current DFS path
        hasCycle = false;                              // Reset cycle flag
        stack<int> st;                                 // Stack to store the topological order

        // Build the adjacency list from prerequisites
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];  // Course to be taken
            int b = prerequisites[i][1];  // Prerequisite course

            adj[b].push_back(a);         // Edge from 'b' to 'a' (b → a)
        }

        // Run DFS from every unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited, st, inRecursion);
            }
        }

        vector<int> result;  // Vector to store the final topological order

        if (hasCycle) {
            return {};  // If there is a cycle, return an empty list
        }

        // Pop all nodes from stack to get the topological order
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;  // Return the computed order
    }
};
