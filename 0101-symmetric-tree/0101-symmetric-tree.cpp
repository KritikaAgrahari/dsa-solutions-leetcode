
class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) {

        // If both nodes are NULL, they are symmetric
        if (left == NULL && right == NULL) return true;

        // If only one node is NULL, they are not symmetric
        if (left == NULL || right == NULL) return false;

        // If values are different, they are not symmetric
        if (left->val != right->val) return false;

        // Compare outer children and inner children
        return check(left->left, right->right) &&
               check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};
