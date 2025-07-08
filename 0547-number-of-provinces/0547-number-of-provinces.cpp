class Solution {
public:
    int n; 

    void dfs(vector<vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true; 
        
        for(int v = 0; v < n; v++) {
            if(adj[u][v] == 1 && !visited[v]) {
                dfs(adj, v, visited); 
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size(); 
        
        vector<bool> visited(n, false); 
        int count = 0; 
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count++; 
                dfs(isConnected, i, visited);
            }
        }
        
        return count; 
    }
};
