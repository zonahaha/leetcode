/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool addSum(struct TreeNode* root,int sum){
    bool res=false;
    if(root->left){
        root->left->val+=root->val;
        res=addSum(root->left,sum);
        if(res==true)return true;
    }
    if(root->right){
        root->right->val+=root->val;
        res=addSum(root->right,sum);
        if(res==true)return true;
    }
    if(!root->left&&!root->right){
        if(root->val==sum)return true;
    }      
    return res;
} 
bool hasPathSum(struct TreeNode* root, int sum) {
    if(!root)return false; 
    return addSum(root,sum);
}
////////////////////////////////////////////////////////////////////////另一种写法,不需要两个函数
bool hasPathSum(struct TreeNode* root,int sum){
    if(!root)return false;
    if(!root->left&&!root->right){
        return sum==root->val;//还能这样写，真厉害啊
    }return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
}
