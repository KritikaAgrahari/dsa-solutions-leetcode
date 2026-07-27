class Solution {
public:

    // DFS function to detect a cycle
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {

        // If node is currently being visited,
        // a cycle exists.
        if (visited[node] == 1)
            return true;

        // If node is already completely processed,
        // no need to visit again.
        if (visited[node] == 2)
            return false;

        // Mark node as currently visiting
        visited[node] = 1;

        // Visit all neighboring courses
        for (int i = 0; i < adj[node].size(); i++) {

            // If a cycle is found, return true
            if (dfs(adj[node][i], adj, visited))
                return true;
        }

        // Mark node as completely processed
        visited[node] = 2;

        // No cycle found
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list
        vector<vector<int>> adj(numCourses);

        // Build graph
        for (int i = 0; i < prerequisites.size(); i++) {

            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];

            // prereq -> course
            adj[prereq].push_back(course);
        }

        // 0 = not visited
        // 1 = visiting
        // 2 = completely visited
        vector<int> visited(numCourses, 0);

        // Start DFS from every course
        for (int i = 0; i < numCourses; i++) {

            // If cycle exists, courses cannot be finished
            if (dfs(i, adj, visited))
                return false;
        }

        // No cycle found
        return true;
    }
};