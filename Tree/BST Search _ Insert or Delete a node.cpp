// In both insert & delete : Space =o(n). We can reduce auxiliary space to o(1) by doing it iterative
// In both cases : Tc=o(height) or o(logn). In worst o(n) if height=nodes i,e squessed tree

TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        if(root->val>val) root->left = insertIntoBST(root->left,val);
        else root->right = insertIntoBST(root->right,val);
        return root;     
}


//Delete :-

int findminfromright(TreeNode* root){
        while(root->left) root=root->left;
        return root->val;
}


TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            if(!root->right)
                return root->left;
            else if(!root->left)
                return root->right;
            else{
		//replace the root value by find the minimum val(extreme left) from right side 
                root->val=findminfromright(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
}
