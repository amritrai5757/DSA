    TreeNode* dfs(TreeNode*root,TreeNode*p, TreeNode*q){
        if(!root)return NULL;
        if(root==p || root==q)return root;
        
        TreeNode* left=dfs(root->left,p,q);
        TreeNode* right=dfs(root->right,p,q);
        if(left && right)return root;
        if(left)return left;
        if(right)return right;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
