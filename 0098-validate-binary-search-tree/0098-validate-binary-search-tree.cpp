
class Solution {
public:
    // Check whether each node lies within its allowed range
    bool check(TreeNode* root, long long mini, long long maxi) {

        // If node is NULL, it is valid
        if (root == NULL) return true;

        // Check whether current node violates BST range
        if (root->val <= mini || root->val >= maxi)
            return false;

        // Check left subtree: values must be smaller than root
        bool left = check(root->left, mini, root->val);

        // Check right subtree: values must be greater than root
        bool right = check(root->right, root->val, maxi);

        // Both subtrees must be valid
        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        // Initially, every integer value is allowed
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
