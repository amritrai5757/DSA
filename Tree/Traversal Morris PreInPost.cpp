Tc; o(n)
Space complexity : o(1) i,e thats why it is used to reduce space complexity   :  Uses concept of threaded binary tree        

void inorderTraversal(TreeNode* root){
        TreeNode* cur = root; 
        // For postorder : Make a vector & wherever there is left make it right & where there is right make it left & v.push_back() where there is Preorder
        while(cur) {
            if(!cur->left) {                        
                cout<<cur->val<<" ";     
                                        // For kth smallest : cnt++; if(cnt==k) cout<<cur->val; break;
                cur = cur->right; 
            }
            else {
                TreeNode* prev = cur->left; 
                while(prev->right && prev->right != cur) {
                    prev = prev->right; 
                }
                if(!prev->right){
                    prev->right = cur;
                                              // For Preorder : cout<< cur->val;
                    cur = cur->left; 
                }
                else {
                    prev->right = NULL; 
                    cout<<cur->val<<" ";      // For Preorder : no cout here    // For kth smallest : cnt++; if(cnt==k) cout<<cur->val; break;
                    cur = cur->right; 
                }
            }
        } 
        // For Postorder : reverse(AnsVector)
}
