/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root){
    int l=1;
    int r=1;
    if(!root)return 0;
    else{
        l=1+maxDepth(root->left);
        if(l==0)return -1;
        r=1+maxDepth(root->right);
        if(r==0)return -1;
        if(l-r>1||l-r<-1)return -1;
    }
    return l>r?l:r;
}  
bool isBalanced(struct TreeNode* root) {
    if(root==NULL)return true;
    if(maxDepth(root)!=-1){
        isBalanced(root->left);
        isBalanced(root->right);
    }
    else return false;
    return true;    
}
