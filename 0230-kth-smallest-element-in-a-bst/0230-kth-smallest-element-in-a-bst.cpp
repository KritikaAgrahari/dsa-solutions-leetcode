
class Solution {
public:
    // Function to perform inorder traversal
    void inorder(TreeNode* root, vector<int>& ans) {

        // Base case: if node is NULL, stop recursion
        if (root == NULL) return;

        // First visit the left subtree
        inorder(root->left, ans);

        // Store the current node value in the vector
        ans.push_back(root->val);

        // Then visit the right subtree
        inorder(root->right, ans);
    }

    // Function to find the kth smallest element
    int kthSmallest(TreeNode* root, int k) {

        // Create a vector to store inorder values
        vector<int> ans;

        // Get all values in sorted order
        inorder(root, ans);

        // Return the kth smallest element (index starts from 0)
        return ans[k - 1];
    }
};
