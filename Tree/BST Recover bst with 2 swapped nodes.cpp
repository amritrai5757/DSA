// tc:o(n) sc other than auxiliary space:o(1)  Auxiliary space: o(n) 
// We can further do morris traversal to reduce auxiliary stack space to o(1)

TreeNode* first, prev, middle, last; 

void inorder(TreeNode* root) {
        if(!root == NULL) return;  
        inorder(root->left);
       
        if (prev && (root->val < prev->val)){        
            if (!first){    //First 2 adjacent unsorted element found 
                first = prev;
                middle = root;
            }      
            else           //3rd & 4th adjacent unsorted found
                last = root;
        }
    
        prev = root;
        inorder(root->right); 
}

void recoverTree(TreeNode* root) {
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val);  // Since it is fixed that only 2 elements are swapped. So signifies that if 4 element found swapping  first and last would solve the problem.
        else if(first && middle) swap(first->val, middle->val);   //else swap the first 2 adjcent
}
