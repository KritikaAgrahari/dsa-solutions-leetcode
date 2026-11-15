class Solution {
public:
    
    int diameter(TreeNode* root, int& result) {
        if(!root)
            return 0;
        
        int left  = diameter(root->left, result);
        int right = diameter(root->right, result);
        
        result = max(result, left + right); //What if I longest diamenter passes through left -> me -> right
        
        return max(left, right) + 1; //But I will return max I can afford if (left -> me -> right) was not answer
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int result = INT_MIN;
        
        diameter(root, result);
        
        return result;
    }
};
