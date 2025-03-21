#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;  // Count missing ingredients
        unordered_map<string, vector<string>> graph;  // Dependency graph
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<string> q;
        vector<string> result;

        // Step 1: Build the Graph
        for (int i = 0; i < recipes.size(); ++i) {
            indegree[recipes[i]] = ingredients[i].size();  // Initially set indegree to required ingredients
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);  // Ingredient -> Recipes dependent on it
            }
        }

        // Step 2: Initialize Queue with Available Supplies
        for (const string& supply : supplies) {
            q.push(supply);
        }

        // Step 3: Process Recipes (Topological Sorting)
        while (!q.empty()) {
            string item = q.front();
            q.pop();

            // If this is a recipe and all its ingredients are available, add it to result
            if (indegree.count(item)) {
                result.push_back(item);
            }

            // Reduce indegree for dependent recipes
            for (const string& recipe : graph[item]) {
                if (--indegree[recipe] == 0) {  // All ingredients are now available
                    q.push(recipe);
                }
            }
        }

        return result;
    }
};
