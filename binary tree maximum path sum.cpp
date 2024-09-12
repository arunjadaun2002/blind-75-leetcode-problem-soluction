int downpath(TreeNode* root, int maxi){
    if(root==nullptr) return 0;

    int lh=max(0,downpath(root->left,maxi));
    int rh=max(0,downpath(root->right,0));

    maxi=max(maxi,lh+rh+root->val);
    
    return max(lh,rh)+(root->val);
}

int maxPathsum(TreeNode* root){
    int maxi=INT_MIN;

    downpath(root,maxi);
    return maxi;
}