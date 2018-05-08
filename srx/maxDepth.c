/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) { 
    int l=1;
    int r=1;
    int count=1;
    if(!root)return 0; 
    /* if(root->left&&!root->right){  
        count+=maxDepth(root->left);
    }
    else if(!root->left&&root->right){
        count+=maxDepth(root->right);
    }
    else if(!root->left&&!root->right)return count; */
    else {
        l=1+maxDepth(root->left);
        r=1+maxDepth(root->right);
        count=l>r?l:r;
    }
    return count;
}
