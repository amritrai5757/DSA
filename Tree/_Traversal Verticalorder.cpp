// Vertical Order Traversal, Vertical order sum,Vertical width of tree by BFS(top,bottom view)
// NOTE : ONLY BFS SOLUTION likE dijkstra
// Iterative:
vector<vector<int>> verticalTraversal(Node* root){
        vector<vector<int>> ans;
        if(!root)return ans;
        map<int, vector<int>> m; 
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size()){
            int sz = q.size();
            vector<pair<int, int>>a; 
            for(int i=0;i<sz;i++){
                pair<Node*, int> temp = q.front();
                q.pop();
                a.push_back({temp.second, temp.first->val});
                if(temp.first->left)q.push({temp.first->left, temp.second - 1});
                if(temp.first->right)q.push({temp.first->right, temp.second + 1});
            }
            sort(a.begin(),a.end());
            for(auto it:a)m[it.first].push_back(it.second);   
        }
        for(auto it:m)ans.push_back(it.second);
        return ans;
}
