/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool mirro(struct TreeNode* root1, struct TreeNode* root2);
bool isSymmetric(struct TreeNode* root) {
    if(!root)return true;
    if((root->left&&!root->right)||(root->right&&!root->left))return false;
    if(!root->left&&!root->right)return true;
    if(root->left->val==root->right->val){
       return mirro(root->left,root->right);
    } 
    else return false;
}

bool mirro(struct TreeNode* root1, struct TreeNode* root2){
    bool res1=true;
    bool res2=true;
    if(!root1->left&&!root1->right&&!root2->left&&!root2->right)return true;
    if((root1->left&&!root2->right)||
       (root1->right&&!root2->left)||
       (!root1->right&&root2->left)||
       (!root1->left&&root2->right))
        return false;    
        if(root2->left&&root1->right){
          if(root2->left->val==root1->right->val) res1=mirro(root1->right,root2->left);  
            else return false;
        } 
         if(root1->left&&root2->right){
         if(root2->right->val==root1->left->val) res2=mirro(root1->left,root2->right);
             else return false;
        }    
    return res1&&res2;
}
