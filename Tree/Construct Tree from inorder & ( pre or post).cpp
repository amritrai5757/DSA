    TreeNode* dfs(vector<int>&postorder, int preStart, int preEnd, vector<int>&inorder, int inStart,int inEnd,map<int,int>&m){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        TreeNode* root=new TreeNode(postorder[preEnd]);//
        int inRoot=m[postorder[preEnd]];//
        int numsLeft=inRoot-inStart;
        root->left=dfs(postorder,preStart,preStart+numsLeft-1,inorder,inStart,inRoot-1,m);//
        root->right=dfs(postorder,preStart+numsLeft,preEnd-1,inorder,inRoot+1,inEnd,m);//
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return dfs(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
    }







    TreeNode* dfs(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart,int inEnd,map<int,int>&m){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=m[root->val];
        int numsLeft=inRoot-inStart;
        root->left=dfs(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,m);
        root->right=dfs(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,m);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return dfs(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
    }
