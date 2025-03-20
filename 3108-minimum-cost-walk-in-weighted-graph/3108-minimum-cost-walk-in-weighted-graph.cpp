#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (rank[px] > rank[py]) swap(px, py);
            parent[px] = py;
            if (rank[px] == rank[py]) rank[py]++;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return a[2] < b[2]; });
        
        unordered_map<int, DSU> componentMap;
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (componentMap.find(w) == componentMap.end()) 
                componentMap[w] = DSU(n);
            componentMap[w].unite(u, v);
        }

        vector<int> res;
        for (auto &q : queries) {
            int s = q[0], t = q[1];
            if (s == t) {
                res.push_back(0);
                continue;
            }
            
            int minAnd = -1;
            for (auto &[w, dsu] : componentMap) {
                if (dsu.find(s) == dsu.find(t)) {
                    minAnd = (minAnd == -1) ? w : min(minAnd, w);
                }
            }
            res.push_back(minAnd);
        }
        return res;
    }
};
