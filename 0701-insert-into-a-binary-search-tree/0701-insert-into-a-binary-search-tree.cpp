
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If the current node is NULL, create a new node
        if (root == NULL) return new TreeNode(val);

        // If val is smaller than the current node, go to the left subtree
        if (root->val > val) {

            // Recursively insert val into the left subtree
            root->left = insertIntoBST(root->left, val);
        }
        else {

            // If val is greater, recursively insert into the right subtree
            root->right = insertIntoBST(root->right, val);
        }

        // Return the updated root node
        return root;
    }
};
