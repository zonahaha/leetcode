/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    int l=1;
    int r=1;
    if(!root)return 0;
    else{  
        l=1+minDepth(root->left);
        r=1+minDepth(root->right);
    }
    if(l==1||r==1)return l==1?r:l;
    return l<r?l:r;
}
