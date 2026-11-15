

class Solution {  // Define the Solution class
public:           // Make functions accessible

    void solve(TreeNode* root, vector<int>& ans) {  // Helper function to traverse the tree

        if (root == NULL) {  // Check if the current node is NULL
            return;          // Stop recursion if node is NULL
        }


        solve(root->left, ans);    // Recursively visit the left subtree
        ans.push_back(root->val); 

        solve(root->right, ans);   // Recursively visit the right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {  // Main function returning traversal

        vector<int> ans;  // Create an empty vector to store node values

        solve(root, ans); // Call helper function starting from root

        return ans;       // Return the preorder traversal result
    }
};
