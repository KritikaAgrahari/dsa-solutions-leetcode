/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    // Maps original nodes to their cloned nodes
    unordered_map<Node*, Node*> mp;

    // DFS function to clone the graph
    Node* dfs(Node* node) {

        // If this node has already been cloned,
        // return the cloned version.
        if (mp.count(node))
            return mp[node];

        // Create a clone of the current node
        Node* clone = new Node(node->val);

        // Store it in the map
        mp[node] = clone;

        // Clone all neighboring nodes
        for (Node* neighbor : node->neighbors) {

            // Clone the neighbor and add it to clone's neighbors
            clone->neighbors.push_back(dfs(neighbor));
        }

        // Return cloned node
        return clone;
    }

    Node* cloneGraph(Node* node) {

        // Empty graph
        if (node == NULL)
            return NULL;

        // Start DFS from the given node
        return dfs(node);
    }
};