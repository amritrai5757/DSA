Use dp when u at node u want property of its left & right . When u use dp you dont declare int or bool or node for both differnetl use 1 return type


2 sum in bst : make a vector<int> inorder & store the inorder using recursion Then apply normal 2 sum of array as array is aleardy sorted.  Tc:o(n) traversal  & sc:o(n) 
          
          
          
Recursive soln:o(n)
// In diameter in brute we need to find left height & right height of each node.so tc will become o(n^2) . So we use dp & whenver dp used int dfs called otherwise void dfs
int path; //: diameter : max path betn any 2 nodes when distance is calculated on basis on edges between 2 nodes
          // max path sum : max distance betn 2 nodes when distance is calculated on baseis of nodes value . IT may be neagtive.

void dfs(Node* root){  
   if(!root)return;
   //cout<<root->data; For Preorder : root-> left->right
   dfs(root->left);
   //cout<<root->data; ans.push_back(root->data) For Inorder : left -> root -> right .If for(i=0to nodes) if(ans[i]<ans[i+1]) IT IS binaray search tree
   dfs(root->right);
   //cout<<root->data; For Postorder left->right->root
   
   //For max path sum : int left=max(0for negative,dfs(root->left)); ans=max(ans,left+right+root->val);//It will store answer for all heads
  // For max path sum :             return max(left,right)+root->val;
   //For Diameter : diameter= max(diameter,left+right);
   //For checking Balanced tree(left and right subtrees of every node differ in height by max 1) : if(abs(left-right)>1 || left ==-1 || right==-1) return -1;
   //For height/depth: return 1+max(left,right) where int left=dfs(root->left) &similary right & if(!root)return 0; int dfs
}









//Not required to study : Not commonly used just for knowledge : Iterative way to do preInPost Traversal : Not used just for knowledge

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder; 
       
        stack<TreeNode*> st; 
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop(); 
            preorder.push_back(root->val); 
            if(root->right != NULL){
                st.push(root->right);
            }
            if(root->left!= NULL){
                st.push(root->left);
            }
        }
        return preorder; 
    }




    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        TreeNode* node = root;
        vector<int> inorder; 
        while(true) {
            if(node != NULL) {
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) break; 
                node = st.top(); 
                st.pop(); 
                inorder.push_back(node->val); 
                node = node->right; 
            }  
        }
        return inorder; 
    }



//using 2 stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1, st2; 
        st1.push(root); 
        while(!st1.empty()) {
            root = st1.top(); 
            st1.pop();
            st2.push(root); 
            if(root->left != NULL) {
                st1.push(root->left); 
            }
            if(root->right != NULL) {
                st1.push(root->right); 
            }
        }
        while(!st2.empty()) {
            postorder.push_back(st2.top()->val); 
            st2.pop(); 
        }
        return postorder;
    }
    
// Using 1 stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1;
        TreeNode* current = root;  
        while(current != NULL || !st1.empty()) {
            if(current != NULL){
                st1.push(current);
                current = current->left;
            }else{
                TreeNode* temp = st1.top()->right;
                if (temp == NULL) {
                    temp = st1.top();
                    st1.pop(); 
                    postorder.push_back(temp->val);
                    while (!st1.empty() && temp == st1.top()->right) {
                        temp = st1.top();
                        st1.pop(); 
                        postorder.push_back(temp->val);
                    }
                } else {
                    current = temp;
                }
            }
        }
        return postorder;
    }



//All traversals in one iteration :
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st; 
        st.push({root, 1}); 
        vector<int> pre, in, post;
        if(root == NULL) return post;

        while(!st.empty()) {
            auto it = st.top(); 
            st.pop(); 

            // this is part of pre
            // increment 1 to 2 
            // push the left side of the tree
            if(it.second == 1) {
                pre.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->left != NULL) {
                    st.push({it.first->left, 1}); 
                }
            }

            // this is a part of in 
            // increment 2 to 3 
            // push right 
            else if(it.second == 2) {
                in.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->right != NULL) {
                    st.push({it.first->right, 1}); 
                }
            }
            // don't push it back again 
            else {
                post.push_back(it.first->val); 
            }
        } 

        return post; 
    }
