// Return all root to leaf path i,e print all paths like u print in matrix with void.No dp required

void dfs(TreeNode* root,string &temp,vector<string>&ans){
        if(!root)return;
        int tt=temp.size();
        temp+=to_string(root->val);temp+="->";
        if(!(root->left) && !(root->right)){
            temp.pop_back();temp.pop_back();
            ans.push_back(temp); 
        }
        
        dfs(root->left ,temp,ans);       
        dfs(root->right,temp,ans);
        temp.erase(temp.begin()+tt,temp.end());
}

vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp="";
        dfs(root,temp,ans);
        return ans;
}
