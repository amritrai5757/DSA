void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        
        if(root->left){  // Change limks : make left subtree attached with root->right & then new root->right with previous root->right  as preorder : root->left->right
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;
            while(root->right) root = root->right;
            root->right = right;
        }        
}
